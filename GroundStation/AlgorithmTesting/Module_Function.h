#pragma once
// OpenCV
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgcodecs.hpp>

// #include <chrono>
#include <iostream> //I/O스트림 헤더
#include <string>//스트링 객체 사용 헤더
#include <list>//리스트 자료형 헤더
#include <vector>
#include <string>
#include <dirent.h>
#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>

#include <algorithm>


using namespace cv;
using namespace std;

class Module_Function
{
public:
    Module_Function();
    void laneDetection(int i, string videoFullName);
private:
    // int sensorType;
    // string strDirPath;
    // vector<string> fileNames;
    // string strFileType;
    // string strExtension;
    // vector<Mat> images;

};