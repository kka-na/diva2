#pragma once

#ifndef MODELRUNTHREAD_H
#define MODELRUNTHREAD_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
// #include <QTimer>
#include <QThread>
#include <QDebug>
#include <QCoreApplication>

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class ModelRunThread : public QThread
{
    Q_OBJECT
public:
    explicit ModelRunThread(QObject *parent = 0);
    bool stop_flag = false;
	
private slots:
    void stop();

private:
    void run() override;

};

#endif // ALGORITHMTESTING_H