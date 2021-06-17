#pragma once
#include "ImuSensingThread.h"
#include <sys/time.h>


enum IMU{IMU_EXCEPTION=0, IMU_ACCELX, IMU_ACCELY, IMU_ACCELZ, IMU_GYROX, IMU_GYROY, IMU_GYROZ, IMU_MAGX, IMU_MAGY, IMU_MAGZ,
        IMU_ESTROLL, IMU_ESTPITCH, IMU_ESTYAW, IMU_ESTROLL_UNCERT, IMU_ESTPITCH_UNCERT, IMU_ESTYAW_UNCERT};

static map<string, IMU> ImuMap;

void ImuMap_init();

ImuSensingThread::ImuSensingThread(){

}

void ImuSensingThread::run(zmq::socket_t *pubSock, const char *devicename, mscl::uint32 baudrate)
{
    
    printf("[MobilePlatform/Sensing/ImuSensingThread] run (MSCL VER.%s)\n", mscl::MSCL_VERSION.str());
    ImuMap_init();

    int count=0;

    clock_t clk_bef = clock(); 
    clock_t clk_now = clock();
    if(USE_IMU==1)
    {
        // [Connect the IMU device]
        // <create the connection object with port and baud rate>
        mscl::Connection connection = mscl::Connection::Serial(devicename, baudrate);
        
        // <create the InertialNode, passing in the connection>
        mscl::InertialNode msclNode = mscl::InertialNode(connection);
        printf("[MobilePlatform/Sensing/ImuSensingThread] connect to IMU device\n");

        while(1)
        {
            sensors::Imu imu;

            // <Get MipDataPackets>
            mscl::MipDataPackets msclPackets = msclNode.getDataPackets(500);
            
            // < timestamp >
            struct timeval tv;
            auto *timestamp = new google::protobuf::Timestamp();
            gettimeofday(&tv, NULL);
            timestamp->set_seconds(tv.tv_sec);
            timestamp->set_nanos(tv.tv_usec*1000);
            imu.set_allocated_timestamp(timestamp);
                
            for(mscl::MipDataPacket packet : msclPackets)
            {
                packet.descriptorSet();
                mscl::MipDataPoints points = packet.data();
                    
                printf("=========== 읽은 데이터 ===========\n");
                printf("     Channel     |     Value     \n");
                    
                // [Store the GPS data]
                // <Make json object>
                // Json::Value json_dataset;
                // string path = "imu.json"; // TO-DO: the rule of file name
                // ifstream in(path.c_str());
                // if(in.is_open()) in >> json_dataset;
                // printf("[MobilePlatform/Sensing/ImuSensingThread] Make Json Object (path:%s)\n",path.c_str()); 

                // Json::Value json_data; 
                int count =0;
                for(mscl::MipDataPoint dataPoint : points)
                {    
                    // [Parsing to Proto]
                    const char *cName = dataPoint.channelName().c_str();
                    printf("%15s  | %5d : ",cName, ImuMap[cName]);

                    switch(ImuMap[cName]){
                    case IMU_ACCELX:
                        {count++; imu.set_scaledaccelx(dataPoint.as_float()); break;}
                    case IMU_ACCELY:
                        {count++; imu.set_scaledaccely(dataPoint.as_float()); break;}
                    case IMU_ACCELZ:
                        {count++; imu.set_scaledaccelz(dataPoint.as_float()); break;}
                    default:
                        {}
                    }

                    // <make a json object>
                    // json_data[cName] = dataPoint.as_string();
                    
                } // End : read a packet line
                printf("===========================\n");
                // [Send to PUB socket]
                // <Serialization>        
                int data_len = imu.ByteSize();
                unsigned char data[data_len] = "\0";
                imu.SerializeToArray(data, data_len);
                printf("[MobilePlatform/Sensing/ImuSensingThread] complete to serialize (size=%d)\n",data_len);
                        
                if(count==3){
                    zmq::message_t zmqData(data_len);
                    memcpy((void *)zmqData.data(), data, data_len);
                    s_send_idx(*pubSock, SENSOR_IMU);
                    s_send(*pubSock, zmqData);
                }
                
                // <Send>
                // clk_now = clock();
                // if((float)(clk_now - clk_bef)/CLOCKS_PER_SEC >= 0.1)
                // {
                //     if(count==3){
                //     zmq::message_t zmqData(data_len);
                //     memcpy((void *)zmqData.data(), data, data_len);
                //     s_send_idx(*pubSock, SENSOR_IMU);
                //     s_send(*pubSock, zmqData);
                //     printf("(%dms)[MobilePlatform/Sensing/ImuSensingThread] Complete to send to PUB Socket\n", (float)(clk_now-clk_bef)/CLOCKS_PER_SEC*1000);
                    
                //     clk_bef = clk_now;
                //     }
                // }
        

                // // [STORING]
                // // <add a json to json_dataset>
                // json_dataset.append(json_data);
                // printf("[MobilePlatform/Sensing/ImuSensingThread] Append a json data\n");

                // // <save the json file>
                // Json::StyledWriter jsonWriter;
                // ofstream out(path.c_str());
                // out<<jsonWriter.write(json_dataset);
                // out.close();
                // printf("[MobilePlatform/Sensing/ImuSensingThread] complete to make json file at \"%s\"\n",path.c_str());

            } // End : read all packet lines
        
            // [Options]
            //usleep (100);
            
        } // End : while(1)
    } // End : if(USE_IMU==1)
}


void ImuMap_init(){
    ImuMap["scaledAccelX"] = IMU_ACCELX;
    ImuMap["scaledAccelY"] = IMU_ACCELY;
    ImuMap["scaledAccelZ"] = IMU_ACCELZ;
    ImuMap["scaledGyroX"] = IMU_GYROX;
    ImuMap["scaledGyroY"] = IMU_GYROY;
    ImuMap["scaledGyroZ"] = IMU_GYROZ;
    ImuMap["scaledMagX"] = IMU_MAGX;
    ImuMap["scaledMagY"] = IMU_MAGY;
    ImuMap["scaledMagZ"] = IMU_MAGZ;

    ImuMap["estRoll"] = IMU_ESTROLL;
    ImuMap["estPitch"] = IMU_ESTPITCH;
    ImuMap["estYaw"] = IMU_ESTYAW;

    ImuMap["estRollUncert"] = IMU_ESTROLL_UNCERT;
    ImuMap["estPitchUncert"] = IMU_ESTPITCH_UNCERT;
    ImuMap["estYawUncert"] = IMU_ESTYAW_UNCERT;

    ImuMap[""] = IMU_EXCEPTION;
}