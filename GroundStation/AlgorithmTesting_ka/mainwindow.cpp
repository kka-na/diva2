#pragma once

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QListWidget>
// #include <QtMultimedia>
// #include <QGraphicsVideoItem>

// ZeroMQ
#include <zmq.hpp>

// OpenCV
//#include <opencv2/opencv.hpp>
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include <opencv2/imgcodecs.hpp>

#include <iostream>
#include <string>
#include <map>

using namespace std;
//using namespace cv;

void setMSettings();
QStringList getAlgorithmQStringList(int sensorIdx);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QPixmap bg("/home/diva2/diva2/GroundStation/AlgorithmTesting_ka/color.jpeg");

           QPalette p(palette());
           setMSettings();
           p.setBrush(QPalette::Background, bg);
           setAutoFillBackground(true);
           setPalette(p);

    ui->setupUi(this);
    // connect(ui->pushButton, SIGNAL(on_pushButton_clicked()), algorithmThread, SLOT(start()));
    printf("[MainWindow::MainWindow] pushButton\n");
}

enum Sensor { lidar, cam, can, imu, gps};
int sensorIdx=Sensor::lidar;
int algorithmIdx = 0;
map<int, string> mLidar;
map<int, string> mCam;
map<int, string> mCan;
map<int, string> mImu;
map<int, string> mGps;

void MainWindow::display_original(QImage image, QImage image_result){
    printf("[MainWindow::display_original] start\n");
    originalImageWidget->setPixmap(QPixmap::fromImage(image).scaled(originalImageWidget->width(), originalImageWidget->height(), Qt::KeepAspectRatio));
    originalImageWidget->setAlignment(Qt::AlignCenter);

    resultImageWidget->setPixmap(QPixmap::fromImage(image_result).scaled(resultImageWidget->width(), resultImageWidget->height(), Qt::KeepAspectRatio));
    resultImageWidget->setAlignment(Qt::AlignCenter);

    originalImageWidget->show();
    resultImageWidget->show();

    QCoreApplication::processEvents();
}

void MainWindow::on_pushButton_clicked()
{
    // PushButton : Play
    cout << "[MainWindow::on_pushButton_clicked] start\n";

    // ==================
    algorithmThread = new AlgorithmThread(this);
    algorithmThread->start();

    originalImageWidget =ui->label_original_img;
    originalImageWidget->clear();
    resultImageWidget = ui->label_result_img;
    resultImageWidget->clear();
    // algorithmThread->run();
    connect(algorithmThread, SIGNAL(send_qimage(QImage, QImage)), this, SLOT(display_original(QImage, QImage)));
    
    // =====================
    
    printf("sensor: %d\n", sensorIdx);
    printf("algorithm: %d\n", algorithmIdx);
    printf("model: %s\n", model_path.path().toStdString().c_str());
    printf("weight: %s\n", weight_path.path().toStdString().c_str());
    printf("dir: %s\n",dir.path().toStdString().c_str());
    /*
    int ret;
    string command;
    command += "cd /home/diva2/diva2/build/GroundStation/AlgorithmTesting ";
    command += "&& ./GS_algorithm ";
    command += (to_string(sensorIdx) + " ");
    command += (to_string(algorithmIdx) + " ");
    command += (model_path.path().toStdString() + " ");
    command += (weight_path.path().toStdString() + " ");
    command += (dir.path().toStdString());

    // ret = system("cd /home/diva2/diva2/build/GroundStation/AlgorithmTesting && ./GS_algorithm");
    ret = system(command.c_str());

    // /home/diva2/diva2/GroundStation/AlgorithmTesting/Algorithm/output_video.avi
    

    QGraphicsScene *scene = new QGraphicsScene;
    QMediaPlayer *player = new QMediaPlayer();
    QGraphicsVideoItem *videoItem = new QGraphicsVideoItem;

    ui->graphicsView_2->setScene(scene);
    player->setVideoOutput(videoItem);
    ui->graphicsView_2->scene()->addItem(videoItem);
    player->setMedia(QUrl::fromLocalFile("/home/diva2/diva2/GroundStation/AlgorithmTesting/Algorithm/output_video.avi"));
    // player->setVolume();
    ui->graphicsView_2->fitInView(videoItem);
    player->play();

    */


}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    // ComboBox : Sensor
    printf("[MainWindow::on_comboBox_currentIndexChanged] start (index=%d)\n", index);
    sensorIdx = index;

    // [ Sensor에서 사용가능한 function만을 load ]
    ui->comboBox_2->clear();
    ui->comboBox_2->insertItems(0, getAlgorithmQStringList(sensorIdx));
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    // ComboBox : Function
    printf("[MainWindow::on_comboBox_2_currentIndexChanged] start (index=%d)\n", index);
    algorithmIdx = index;
}

void setMSettings(){
    printf("[setMSettings] start \n");

    // cam
    mCam.insert(make_pair(0, "Lane Detection"));
    mCam.insert(make_pair(1, "Object Detection"));
}

QStringList getAlgorithmQStringList(int sensorIdx){
    printf("[getAlgorithmQStringList] start (sensorIdx=%d)\n", sensorIdx);
    QStringList qStringList;
    map<int,string> mMap;
    switch (sensorIdx) {
    case Sensor::lidar: {mMap=mLidar; break;}
    case Sensor::cam: {mMap=mCam; break;}
    case Sensor::can: {mMap=mCan; break;}
    case Sensor::imu: {mMap=mImu; break;}
    case Sensor::gps: {mMap=mGps; break;}
    defualt: {break;}
    }
    map<int,string>::iterator iter;
    printf("[getAlgorithmQStringList] size= %d\n", mMap.size());
    for(iter=mMap.begin(); iter!=mMap.end(); iter++){
        printf("2");
        qStringList << QApplication::translate("MainWindow", iter->second.c_str(), Q_NULLPTR);
        printf("%d, %s\n", iter->first, iter->second.c_str());
    }
    return qStringList;
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_pushButton_2_clicked()
//{s
//    QString file = QFileDialog::getOpenFileName(this, "file", "/home/kayeon", "Files (*.*)");
//    //각자의 파일 경로로 바꿔야 함
//    qDebug() << file;
//}

//void MainWindow::on_listView_activated(const QModelIndex &index)
//{

//}





void MainWindow::on_pushButton_select_clicked()
{
    // Select Directory

    // show exisiting directory
    dir = QFileDialog::getExistingDirectory();
    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    ui->listDir-> clear();
    list = dir.entryInfoList();
    // loop for file print
    for(int i = 0; i < list.size(); ++i){
        QFileInfo fileInfo = list.at(i);
        ui -> listDir ->addItem(QString("%1").arg(fileInfo.fileName()));
    }
}

void MainWindow::on_pushButton_3_clicked(){
    this->model_path = QFileDialog::getOpenFileName(this, "file selct","home/kayeon/", "Files(*.*)");
    // qDebug()<<file;

}

void MainWindow::on_pushButton_4_clicked(){
    this->weight_path = QFileDialog::getOpenFileName(this, "file selct","home/kayeon/", "Files(*.*)");
    // qDebug()<<file;
}
