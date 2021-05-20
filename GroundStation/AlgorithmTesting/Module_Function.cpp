#include "Module_Function.h"

Module_Function::Module_Function(){

}

void Module_Function::laneDetection(int i, string videoFullName){
    string funcPath;
    string funcName;
    switch (i)
    {
    case 0:
    {
        funcPath = "/home/diva2/diva2/build/test/lane_detection/LaneDetector";
        funcName = "./lanes";
        break;
    }
    case 1:
    {
        funcPath = "/home/diva2/diva2/test/lane-detection2";
        funcName = "python line_fit_video.py";
        break;
    }
    default:     
        break;
    }
    printf("[Module_Function::laneDetection] start\n");
    string command = "cd "+funcPath+" && pwd && "+funcName+" "+videoFullName;
    // printf("command: %s\n", command.c_str());
    int ret = system(command.c_str());
    /*
    int ret = system("cd /home/diva2/diva2/build/te7st/lane_detection/LaneDetector \\
                        && pwd \\
                        && ./lanes /home/diva2/diva2/build/GroundStation/AlgorithmTesting/hellop.mp4"); // cd /home/diva2/diva2/build/test/lane_detection/LaneDetector
                        // && ./lanes /home/diva2/diva2/test/lane_detection/project_video.mp4"); // cd /home/diva2/diva2/build/test/lane_detection/LaneDetector
    */printf("%d\n",ret);
    

}
