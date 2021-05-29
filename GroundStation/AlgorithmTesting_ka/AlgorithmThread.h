#pragma once

#ifndef ALGORITHMTESTING_H
#define ALGORITHMTESTING_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
// #include <QTimer>
#include <QThread>
#include <QDebug>
#include <QCoreApplication>

#include <zmq.hpp>
#include "../../protobuf/sensors.pb.h"

#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgcodecs.hpp>

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class AlgorithmThread : public QThread
{
    Q_OBJECT
public:
    explicit AlgorithmThread(QObject *parent = 0);
    bool stop_flag = false;
	
private slots:
    void stop();

private:
    void run() override;
signals :
    void send_qimage(QImage, QImage);
	// void send_acc(float, float, float);
    

};

#endif // ALGORITHMTESTING_H