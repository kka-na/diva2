#pragma once
#include "AlgorithmThread.h"

enum Sensor { lidar, cam, can, imu, gps};

inline static std::string s_recv(zmq::socket_t & socket, int flags = 0) {
    zmq::message_t message;
    socket.recv(& message, flags);

    return std::string(static_cast < char *> (message.data()), message.size());
}

AlgorithmThread::AlgorithmThread(QObject *parent) : QThread(parent)
{

}

void AlgorithmThread::lane_detection(){
    zmq::context_t ctx(1);
    zmq::socket_t algorithmTesting_sub(ctx, ZMQ_SUB);
    algorithmTesting_sub.connect("tcp://localhost:9899");
    algorithmTesting_sub.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    printf("[AlgorithmThread::lane_detection] connect\n");

    int frame_cnt = 0;
    float millis_sum = 0;


    while(!stop_flag){
        printf("[AlgorithmThread::lane_detection] while\n");
        // [ Setting ]
        sensors::algorithm_img algo_img;        

        // < receive message from pub(=diva2/GroundStation/AlgorithmTesting/main) >
        zmq::message_t msg;
        cv::Mat frame_original;
        frame_original.create(480, 640, CV_8UC3);
        cv::Mat frame_result;
        frame_result.create(480, 640, CV_8UC3);

        // < parsing serialized data to message >
        // algo_img.ParseFromArray(msg.data(), msg.size());
        algorithmTesting_sub.recv(&msg);
        if((int)(msg.size())==3){
            printf("[AlgorithmThread::lane_detection] The size of msg is only %dbytes\n", msg.size());
            printf("[AlgorithmThread::lane_detection] Finish this program\n");
            break;
        }
        frame_cnt++;
        printf("[AlgorithmThread::lane_detection] msg size = %d\n", msg.size());

        std::string _buff = std::string(static_cast<char *>(msg.data()), msg.size());
        algo_img.ParseFromString(_buff);
        float millis = algo_img.millis_term();
        millis_sum += millis;
        float fps = (float)(1000*frame_cnt)/(float)(millis_sum);
        printf("fps=%f\n", fps);

        // [ Preprocessing for Visualization ]
        // < Setting for original image >
        memcpy((void*)frame_original.data, (void*)(&algo_img.image_original()[0]),
                    frame_original.step[0]*(size_t)frame_original.rows);
        // cv::cvtColor(frame_original, frame_original, cv::COLOR_BGR2RGB);
        
        // < Setting for result image >
        memcpy((void*)frame_result.data, (void*)(&algo_img.image_result()[0]),
                    frame_result.step[0]*(size_t)frame_result.rows);
        // cv::cvtColor(frame_result, frame_result, cv::COLOR_BGR2RGB);
        
        // [ Visualization at Qt GUI ]
        QImage image_original(frame_original.size().width, frame_original.size().height, QImage::Format_RGB888);
        memcpy(image_original.scanLine(0), frame_original.data, 
            static_cast<size_t>(image_original.width() * image_original.height() * frame_original.channels()));
        
        QImage image_result(frame_result.size().width, frame_result.size().height, QImage::Format_RGB888);
        memcpy(image_result.scanLine(0), frame_result.data, 
            static_cast<size_t>(image_result.width() * image_result.height() * frame_result.channels()));
        
        emit send_qimage(image_original, image_result, QString::number(fps)); 
        // emit send_qimage(image_original, image_result);
    }

    printf("[AlgorithmThread::lane_detection] end\n");
    exit(0);
}

void AlgorithmThread::obj_detection(){
    void *ctx = zmq_ctx_new();
    void *socketSub = zmq_socket(ctx, ZMQ_REP);
    int rc = -1;
    rc = zmq_connect(socketSub, "tcp://localhost:9899");
    printf("[AlgorithmThread::obj_detection] connect:%d\n", rc);


    int frame_cnt = 0;
    float millis_sum = 0;
    while(!stop_flag){
        printf("[AlgorithmThread::obj_detection] while\n");
        // [ Setting ]
        
        // [ Communicate ]
        // < receive topic from pub(=diva2/GroundStation/AlgorithmTesting/main) >
        // string topic = s_recv(algorithmTesting_sub);
        // printf("[AlgorithmThread::run] topic = %s\n", topic.c_str());
        
        // < receive message from pub(=diva2/GroundStation/AlgorithmTesting/main) >
        cv::Mat frame_original;
        frame_original.create(480, 640, CV_8UC3);
        cv::Mat frame_result;
        frame_result.create(480, 640, CV_8UC3);

        // < parsing serialized data to message >
        char buf [512];
        printf("[AlgorithmThread::obj_detection] ready to read\n");
        int nbytes = zmq_recv (socketSub, buf, 512, 0);
        // assert (nbytes != -1);
        printf("[AlgorithmThread::obj_detection] receive %d bytes\n", nbytes);
        printf("... %s\n", buf);

        cv::Mat mat = cv::imread(buf);
        int width = mat.size().width;
        int height = mat.size().height;
        cv::resize(mat, frame_result, cv::Size(640, 480));
        frame_result.copyTo(frame_original);
        // imshow(buf, mat);
        // waitKey(0);
        // destroyAllWindows();

        // [ Visualization at Qt GUI ]
        QImage image_original(frame_original.size().width, frame_original.size().height, QImage::Format_RGB888);
        memcpy(image_original.scanLine(0), frame_original.data, 
            static_cast<size_t>(image_original.width() * image_original.height() * frame_original.channels()));
        
        QImage image_result(frame_result.size().width, frame_result.size().height, QImage::Format_RGB888);
        memcpy(image_result.scanLine(0), frame_result.data, 
            static_cast<size_t>(image_result.width() * image_result.height() * frame_result.channels()));
        
        float fps = 0;
        emit send_qimage(image_original, image_result, QString::number(fps)); 
        // emit send_qimage(image_original, image_result);

    }

    printf("[AlgorithmThread::obj_detection] end\n");
    exit(0);

}
void AlgorithmThread::run(){
    printf("[AlgorithmThread::run] start\n");
    printf("   sensorIdx:%d\n", this->sensorIdx);
    printf("   algorithmIdx:%d\n", this->algorithmIdx);
    printf("\n");
    
    if((sensorIdx==Sensor::cam) && (algorithmIdx==0)){
        lane_detection();
    }else if((sensorIdx==Sensor::cam) && (algorithmIdx==1)){
        obj_detection();
    }
    
    printf("[AlgorithmThread::run] end\n");
    exit(0);
}

void AlgorithmThread::stop(){
    stop_flag = true;
}

void AlgorithmThread::set_input_path(string input_path){
    this->input_path = input_path;
}

void AlgorithmThread::set_algorithmIdx(int algoIdx){
    this->algorithmIdx = algoIdx;
}
void AlgorithmThread::set_sensorIdx(int sensorIdx){
    this->sensorIdx = sensorIdx;
}