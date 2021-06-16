#pragma once

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QListWidget>

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

// [ Global Variables ]
enum Sensor { lidar, cam, can, imu, gps};
int sensorIdx=Sensor::lidar;
int algorithmIdx = 0;
map<int, string> mLidar;
map<int, string> mCam;
map<int, string> mCan;
map<int, string> mImu;
map<int, string> mGps;


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
    ui->cb_Algorithm->clear();
    printf("complete to setup UI\n");
}


MainWindow::~MainWindow()
{
    delete ui;
}

// [[ Select Arguments ]]
// [ Sensor ComboBox ]
void MainWindow::on_cb_Sensor_currentIndexChanged(int index)
{
    sensorIdx = index;
    printf("[MainWindow::on_comboBox_currentIndexChanged] start (index=%d)\n", sensorIdx);

    // < Load Algorithms Related to SensorIdx >
    ui->cb_Algorithm->clear();
    ui->cb_Algorithm->insertItems(0, getAlgorithmQStringList(sensorIdx));
}
// [ Algorithm ComboBox ]
void MainWindow::on_cb_Algorithm_currentIndexChanged(int index)
{
    algorithmIdx = index;
    printf("[MainWindow::on_cb_Algorithm_currentIndexChanged] start (index=%d)\n", algorithmIdx);
}

// [ Set Sensor-Algorithm Map ]
void setMSettings(){
    printf("[setMSettings] start \n");

    // cam
    mCam.insert(make_pair(0, "Lane Detection"));
    mCam.insert(make_pair(1, "Object Detection"));
}
// [ Select Data File : Set PushButton "pb_Select_DataFile"]
void MainWindow::on_pb_Select_DataFile_clicked(){
    this->data_path = QFileDialog::getOpenFileName(this, "file selct", QDir::homePath()+QString("/algorithm_resources/"), "Files(*.*)");
    ui->pb_Select_DataFile->setText(this->data_path.dirName());
}
// [ Select Config File : Set PushButton "pb_Select_ConfigFile"]
void MainWindow::on_pb_Select_ConfigFile_clicked(){
    this->config_path = QFileDialog::getOpenFileName(this, "file selct", QDir::homePath()+QString("/algorithm_resources/"), "Files(*.*)");
    ui->pb_Select_ConfigFile->setText(this->config_path.dirName());
}
// [ Select Config File : Set PushButton "pb_Select_WeightFile"]
void MainWindow::on_pb_Select_WeightFile_clicked(){
    this->weight_path = QFileDialog::getOpenFileName(this, "file selct", QDir::homePath()+QString("/algorithm_resources/"), "Files(*.*)");
    ui->pb_Select_WeightFile->setText(this->weight_path.dirName());
}
// [ Select Input Files : Set PushButton "pb_Select_Directory"]
void MainWindow::on_pb_Select_Directory_clicked()
{
    // < Show Exisiting Directory >
    this->input_path = QFileDialog::getExistingDirectory();
    this->input_path.setFilter(QDir::Files | QDir::NoSymLinks);
    ui->list_FileList-> clear();
    list = this->input_path.entryInfoList();

    // < Loop for File Print >
    for(int i = 0; i < list.size(); ++i){
        QFileInfo fileInfo = list.at(i);
        ui -> list_FileList ->addItem(QString("%1").arg(fileInfo.fileName()));
    }
    ui->pb_Select_Directory->setText(this->input_path.dirName());
}


// [[ Display Result ]]


// [ Play Button ]
void MainWindow::on_pb_Play_clicked()
{
    printf("[MainWindow::on_pb_Play_clicked] start\n");

    // [ Set the Environments ]
    // < Set Algorithm Thread to Run >
    algorithmThread = new AlgorithmThread(this);
    algorithmThread->set_input_path(this->input_path.dirName().toStdString());
    algorithmThread->set_sensorIdx(sensorIdx);
    algorithmThread->set_algorithmIdx(algorithmIdx);
    algorithmThread->start();
    modelRunThread = new ModelRunThread(this);
    modelRunThread->set_sensorIdx(sensorIdx);
    modelRunThread->set_algorithmIdx(algorithmIdx);
    modelRunThread->set_datafile(this->data_path.path().toStdString());
    modelRunThread->set_configfile(this->config_path.path().toStdString());
    modelRunThread->set_weightfile(this->weight_path.path().toStdString());
    modelRunThread->start();
    connect(algorithmThread, SIGNAL(send_qimage(QImage, QImage, QString)), this, SLOT(display_original(QImage, QImage, QString)));

    // < Set Image Widgets to Initialize >
    originalImageWidget =ui->label_original_img;
    originalImageWidget->clear();
    resultImageWidget = ui->label_result_img;
    resultImageWidget->clear();
    fpsWidget = ui->label_fps;
    fpsWidget->clear();

    // =====================

    /*
    printf("sensor: %d\n", sensorIdx);
    printf("algorithm: %d\n", algorithmIdx);
    printf("model: %s\n", model_path.path().toStdString().c_str());
    printf("weight: %s\n", weight_path.path().toStdString().c_str());
    printf("dir: %s\n",dir.path().toStdString().c_str());
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





// [ Image Result ]
void MainWindow::display_original(QImage image, QImage image_result, QString fps){
// void MainWindow::display_original(QImage image, QImage image_result){
    printf("[MainWindow::display_original] start\n");
    // < Set Original Image Widget >
    originalImageWidget->setPixmap(QPixmap::fromImage(image).scaled(originalImageWidget->width(), originalImageWidget->height(), Qt::KeepAspectRatio));
    originalImageWidget->setAlignment(Qt::AlignCenter);
    // < Set Result Image Widget >
    resultImageWidget->setPixmap(QPixmap::fromImage(image_result).scaled(resultImageWidget->width(), resultImageWidget->height(), Qt::KeepAspectRatio));
    resultImageWidget->setAlignment(Qt::AlignCenter);
    // < Set fps Widget >
    QString q_fps = fps + " fps";
    fpsWidget->setText(q_fps);
    fpsWidget->setAlignment(Qt::AlignCenter);

    // < Show Image Widgets >
    originalImageWidget->show();
    resultImageWidget->show();
    fpsWidget->show();

    QCoreApplication::processEvents();
}




// [ Get Sensor-Algorithm Map ]
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

    // < Get Algorithm According to sensorIdx >
    printf("[getAlgorithmQStringList] size= %d\n", mMap.size());
    map<int,string>::iterator iter;
    for(iter=mMap.begin(); iter!=mMap.end(); iter++){
        qStringList << QApplication::translate("MainWindow", iter->second.c_str(), Q_NULLPTR);
    }
    return qStringList;
}



