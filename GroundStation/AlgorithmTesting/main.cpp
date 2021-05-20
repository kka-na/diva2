#include <iostream>
#include "Module_Input.h"
#include "Module_Function.h"

using namespace std;


int main(){
    cout<<"hello world"<<endl;
    Module_Input moduleInput(MODULE_SENSOR_TYPE_CAM);
    // moduleInput.setFileNamesWithDir("/home/diva2/diva2/build/MobilePlatform/Sensing/2021-05-18/CAM/", ".jpg");
    // moduleInput.sortFileNames();
    // moduleInput.displayFileName();

    // moduleInput.setImages();
    // moduleInput.setFps(60);
    // moduleInput.image2video("2021-05-18.mp4"); // /home/diva2/diva2/build/GroundStation/AlgorithmTesting/CAM/hello.mp4");

    Module_Function moduleFunction;
    // moduleFunction.laneDetection(0, "/home/diva2/diva2/build/GroundStation/AlgorithmTesting/2021-05-18.mp4");
    moduleFunction.laneDetection(1, "/home/diva2/diva2/build/GroundStation/AlgorithmTesting/testvideo2.mp4");
    // moduleFunction.laneDetection("/home/diva2/diva2/test/lane_detection/project_video.mp4");
    return 0;
}