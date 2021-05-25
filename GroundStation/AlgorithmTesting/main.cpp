#pragma once
#include <iostream>
#include "Module_Input.h"
#include "Module_Function.h"
#include "global.h"

using namespace std;

static map<int, string> mLidar;
static map<int, string> mCam;
static map<int, string> mCan;
static map<int, string> mImu;
static map<int, string> mGps;
static vector<map<int,string>> mAlgorithms;

void setMSettings();

int main(int argc, char *argv[])
{
	/*
        argv[1] : sensorIdx
        argv[2] : algorithmIdx
        argv[3] : fileDir 
    */
    // int sensorIdx = atoi(argv[1]);
    // int algorithmIdx = atoi(argv[2]);
    // string fileDir = argv[3];
    
    int sensorIdx = SensorIdx::cam;
    int algorithmIdx = 1;
    string fileDir = "";
    
    printf("   sensor: %d\n", sensorIdx);
    printf("   algorithm: %d\n", algorithmIdx);
    printf("   fileDir: %s\n", fileDir.c_str());
	
    Module_Input moduleInput(sensorIdx);
    // moduleInput.setFileNamesWithDir(fileDir.c_str(), ".jpg");
    // moduleInput.sortFileNames();
    // moduleInput.displayFileName();

    // ***  /home/diva2/diva2/build/MobilePlatform/Sensing/2021-05-22/CAM/
    // string outputFileName = moduleInput.getDateNameFromDir() + ".mp4";
    // moduleInput.setFiles();
    // moduleInput.image2video(outputFileName.c_str()); // /home/diva2/diva2/build/GroundStation/AlgorithmTesting/CAM/hello.mp4");
    // string fileName = "/home/diva2/diva2/build/GroundStation/AlgorithmTesting/"+outputFileName;
    // moduleInput.displayVideos(fileName);

    setMSettings();
    Module_Function moduleFunction(sensorIdx, algorithmIdx);
    // fileName = "/home/diva2/diva2/build/GroundStation/AlgorithmTesting/testvideo2.mp4";
    // moduleFunction.setFileName(fileName);
    // moduleFunction.run();
    string model_path = "./checkpoints/fcn_big_01.json";
    string weight_path = "./checkpoints/fcn_big_01.h5";
    moduleFunction.model_run(model_path, weight_path);
    
    // moduleFunction.laneDetection(0, "/home/diva2/diva2/test/lane_detection/project_video.mp4");
    // moduleFunction.laneDetection(0, fileDir.c_str());
    // moduleFunction.laneDetection(1, "/home/diva2/diva2/build/GroundStation/AlgorithmTesting/testvideo2.mp4");
    // moduleFunction.laneDetection("/home/diva2/diva2/test/lane_detection/project_video.mp4");
    return 0;
}

void setMSettings(){
    // cam
    mCam.insert(make_pair(0, "Lane Detection"));
    mCam.insert(make_pair(1, "Object Detection"));

    mAlgorithms.push_back(mLidar);
    mAlgorithms.push_back(mCam);
    mAlgorithms.push_back(mCan);
    mAlgorithms.push_back(mImu);
    mAlgorithms.push_back(mGps);
}