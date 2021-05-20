// #pragma once
// // OpenCV
// #include <opencv2/opencv.hpp>
// #include "opencv2/imgproc/imgproc.hpp"
// #include "opencv2/highgui/highgui.hpp"
// #include <opencv2/imgcodecs.hpp>

// // #include <chrono>
// #include <iostream> //I/O스트림 헤더
// #include <string>//스트링 객체 사용 헤더
// #include <list>//리스트 자료형 헤더
// #include <vector>
// #include <string>
// #include <dirent.h>
// #include <stdio.h> 
// #include <sys/types.h> 
// #include <sys/stat.h> 
// #include <unistd.h>

// #include <algorithm>


// using namespace cv;
// using namespace std;

// class Module_Input_CAM
// {
// public:
//     Module_Input_CAM();
//     ~Module_Input_CAM();
    
//     // GET Functions
//     vector<Mat> getImages();
//     string getVideoFullName();

//     // SET Functions
//     void setImagesWithFileNames(vector<string> fullFileNames);
//     void setVideoFullName(string strFullName){this->videoFullName=strFullName;}
//     // DISPLAY Functions
//     void displayImages();
//     void displayImage(int i=0);
    
//     // functions
//     void saveImages2video(string strFileName);
    
// private:
//     vector<Mat> images;
//     string videoFullName;
//     int fps;
// };