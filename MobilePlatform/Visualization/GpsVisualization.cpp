#include "GpsVisualization.h"
#include <sys/time.h>

#include "../../service/Timestamp.h"
#include "../../service/global_name.hpp"
#include "../../protobuf/sensors.pb.h"
#include <fstream>
#include "jsoncpp/json/json.h"
#pragma comment(lib, "jsoncpp\\lib\\lib_json.lib")
#pragma warning(disable : 4996) //error C4996 뜨는 경우

using namespace std;

GpsVisualization::GpsVisualization() {}

void GpsVisualization::run(void *contextSub)
{
    printf("[MobilePlatform/Visualization/GpsVisualization] run\n");

    // [Connect with socket SUB with Sensing Process]
    zmq::socket_t SubSock(*(zmq::context_t *)contextSub, ZMQ_SUB);
    SubSock.connect(protocol::SENSING_SUB);
    SubSock.setsockopt(ZMQ_SUBSCRIBE, "GPS", 3);
    // SubSock.setsockopt(ZMQ_SUBSCRIBE, "", 0);
    printf("[MobilePlatform/Visualization/GpsVisualization] Connet with SUB socket\n");

    clock_t time_bef = clock();
    clock_t time_now = clock();

    fstream dataFile;
    dataFile.open("GPS_DELAY.csv", ios::out);
    
    while (1)
    {
        int USE_PROTO = 1;

        // [Receive the topic From SUB Socket]
        zmq::message_t msgtopic = s_recv(SubSock);
        string topic = (const char *)msgtopic.data();
        printf("[MobilePlatform/Visualization/GpsVisualization] Toic=%s\n",topic.c_str());

        // [Receive the message from SUB Socket]
        sensors::Gps gps;
        zmq::message_t msgData;
        SubSock.recv(&msgData);

        // < timestamp >
        struct timeval tv;
        auto *end_ts = new google::protobuf::Timestamp();
        gettimeofday(&tv, NULL);
        end_ts->set_seconds(tv.tv_sec);
        end_ts->set_nanos(tv.tv_usec*1000);

        time_now = clock();
        printf("(%dms)[MobilePlatform/Visualization/GpsVisualization] Receive %dbytes\n",(float)(time_now-time_bef)/CLOCKS_PER_SEC*1000,msgData.size());
        time_bef = time_now;
        int data_len = msgData.size();
        unsigned char cBytes[data_len];
        memcpy(cBytes, msgData.data(), msgData.size());
        for (auto i = 0; i < data_len; i++)
            printf("%02X ", cBytes[i]);
        printf("\n");

        printf("\n");
        gps.ParseFromArray(msgData.data(), msgData.size());

        // <TIME>
        auto *dur_ts = new google::protobuf::Timestamp();
        dur_ts->set_seconds(end_ts->seconds()-gps.timestamp().seconds());
        dur_ts->set_nanos(end_ts->nanos()-gps.timestamp().nanos());
        printf("dur:%f,  %f\n", dur_ts->seconds(), dur_ts->nanos());
        dataFile<<dur_ts->seconds()<<","<<dur_ts->nanos()<<","<<dur_ts->seconds()*1000+dur_ts->nanos()<<endl;
        
        printf("latitude=%f, longitude=%f\n",gps.latitude(), gps.longitude());

        // [OPTIONAL: DELETE ALL GLOBAL OBJECTS ALLOCATED BY LIBPROTOBUF]
        google::protobuf::ShutdownProtobufLibrary();

        
        // [OPTIONS]
        // sleep(1);
    }
    dataFile.close();
}