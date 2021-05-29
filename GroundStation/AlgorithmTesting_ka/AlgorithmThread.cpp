#pragma once
#include "AlgorithmThread.h"

inline static std::string s_recv(zmq::socket_t & socket, int flags = 0) {
    zmq::message_t message;
    socket.recv(& message, flags);

    return std::string(static_cast < char *> (message.data()), message.size());
}

AlgorithmThread::AlgorithmThread(QObject *parent) : QThread(parent)
{

}

void AlgorithmThread::run(){
    printf("[AlgorithmThread::run] start\n");
    zmq::context_t ctx(1);
    zmq::socket_t algorithmTesting_sub(ctx, ZMQ_SUB);
    algorithmTesting_sub.connect("tcp://localhost:9898");
    algorithmTesting_sub.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    printf("[AlgorithmThread::run] connect\n");

    while(!stop_flag){
        printf("[AlgorithmThread::run] while\n");
        // [ Setting ]
        sensors::algorithm_img algo_img;        

        // [ Communicate ]
        // < receive topic from pub(=diva2/GroundStation/AlgorithmTesting/main) >
        // string topic = s_recv(algorithmTesting_sub);
        // printf("[AlgorithmThread::run] topic = %s\n", topic.c_str());
        
        // < receive message from pub(=diva2/GroundStation/AlgorithmTesting/main) >
        zmq::message_t msg;
        algorithmTesting_sub.recv(&msg);
        printf("[AlgorithmThread::run] msg size = %d\n", msg.size());
        
        // < parsing serialized data to message >
        algo_img.ParseFromArray(msg.data(), msg.size());


        // [ Preprocessing for Visualization ]
        // < Setting for original image >
        cv::Mat frame_original;
        frame_original.create(480, 640, CV_8UC3);
        memcpy((void*)frame_original.data, (void*)(&algo_img.image_original()[0]),
                    frame_original.step[0]*(size_t)frame_original.rows);
        cv::cvtColor(frame_original, frame_original, cv::COLOR_BGR2RGB);
        
        // < Setting for result image >
        cv::Mat frame_result;
        frame_result.create(480, 640, CV_8UC3);
        memcpy((void*)frame_result.data, (void*)(&algo_img.image_result()[0]),
                    frame_result.step[0]*(size_t)frame_result.rows);
        cv::cvtColor(frame_result, frame_result, cv::COLOR_BGR2RGB);


        // [ Visualization at Qt GUI ]
        QImage image_original(frame_original.size().width, frame_original.size().height, QImage::Format_RGB888);
        memcpy(image_original.scanLine(0), frame_original.data, 
            static_cast<size_t>(image_original.width() * image_original.height() * frame_original.channels()));
        
        QImage image_result(frame_result.size().width, frame_result.size().height, QImage::Format_RGB888);
        memcpy(image_result.scanLine(0), frame_result.data, 
            static_cast<size_t>(image_result.width() * image_result.height() * frame_result.channels()));
        
        emit send_qimage(image_original, image_result);
    }
}

void AlgorithmThread::stop(){
    stop_flag = true;
}
