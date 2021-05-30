#pragma once
#include "ModelRunThread.h"


ModelRunThread::ModelRunThread(QObject *parent) : QThread(parent)
{

}

void ModelRunThread::run(){
    printf("[ModelRunThread::run] start\n");
    string command;
    command += "cd /home/diva2/diva2/GroundStation/AlgorithmTesting/Algorithm/ ";
    command += "&& python3 model.py ";
    int ret = system(command.c_str());

}

void ModelRunThread::stop(){
}
