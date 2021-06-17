#include <iostream>
#include <thread> 
#include <string>
#include <zmq.hpp>
#include <zmq.h>
#include "../../service/global_name.hpp"
// OpenCV
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgcodecs.hpp>
#include "../../protobuf/sensors.pb.h"

using namespace std;
using namespace cv;


inline static zmq::message_t s_recv(zmq::socket_t & socket, int flags = 0) {
    zmq::message_t message;
    socket.recv(& message, flags);
	std::cout << "receive: \"" << (const char*)message.data() << "\"... done." << std::endl;
    return message;
}

int main(int argc, char *argv[]){
    
    // SUB
    // zmq::context_t contextSub(1);
    // printf("sub context generated (in main)\n");

    // zmq::socket_t socketSub(contextSub, ZMQ_SUB);
    // socketSub.connect("tcp://localhost:5959");
    // // socketSub.bind("tcp://*:5563");
    // socketSub.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    // printf("[simple_sub] connect with SUB socket\n");


    char str[] ="/home/diva2/algorithm_resources/test/result2.jpg";
    char delimeter[] = "/";
    char *result;
    char parsing[20][30];
    result = strtok(str, delimeter);
    int cnt=0;
    while(result!=NULL){
        strcpy(parsing[cnt++], result);
        result = strtok(NULL, delimeter);
    }
    for(int i=0; i<cnt; i++){
        printf("[%d]:%s\n", i, parsing[i]);
    }
    char buf[512];
    for(int i=0; i<cnt-2; i++){
        sprintf(buf, "%s/%s", buf, parsing[i]);
    }
    sprintf(buf, "%s/%s/%s", buf, "result", parsing[cnt-1]);
    printf("result = %s\n", buf);

    /*
    void *context = zmq_ctx_new();
    void *socketSub = zmq_socket(context, ZMQ_REP);
    int rc = -1;
    rc = zmq_connect(socketSub, "tcp://localhost:9899");
    printf("connect:%d\n", rc);
    
    printf("[zeromq] Protocol0: Start Signal\n");
    char buf [512];
    int nbytes = zmq_recv (socketSub, buf, 512, 0);
    assert (nbytes != -1);
    printf("... recv %d bytes\n", nbytes);
    if(strcmp(buf, "start")==0){
        printf("... ... content: %s\n",buf);
    }

    int count = 1;
    while(1){
        printf("[zeromq] Protocol%d: Communicate file name\n",count);
        int len;
        len = sprintf(buf,
            "/home/diva2/diva2/test/obj_detection/darknet/data/test/testcone%d.jpg",count++);
        buf[len] = '\0';
        rc = zmq_send(socketSub, buf, len+1, 0);
        printf("... send result = %d\n", rc);
        printf("... ... content: %s\n", buf);
        
        nbytes = zmq_recv (socketSub, buf, 512, 0);
        assert (nbytes != -1);
        printf("... recv %d bytes\n\n", nbytes);
        printf("... ... content: %s\n", buf);
        printf("\n");
        

        Mat mat = imread(buf);
        int width = mat.size().width;
        int height = mat.size().height;
        resize(mat, mat, Size(width/2, height/2));
        imshow(buf, mat);
        waitKey(0);        
    }*/
    
}