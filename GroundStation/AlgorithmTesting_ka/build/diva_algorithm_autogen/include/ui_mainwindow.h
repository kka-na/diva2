/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *cb_Sensor;
    QComboBox *cb_Algorithm;
    QLabel *label_Sensor;
    QLabel *label_Algorithm;
    QLabel *label_5;
    QPushButton *pb_Play;
    QPushButton *pb_SelectDirectory;
    QListWidget *list_FileList;
    QPushButton *pb_SelectModel;
    QPushButton *pb_SelectWeight;
    QLabel *label_original_img;
    QLabel *label_result_img;
    QLabel *label_FileList;
    QLabel *label_fps;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1497, 788);
        MainWindow->setBaseSize(QSize(640, 0));
        MainWindow->setStyleSheet(QLatin1String("QLabel{\n"
"\n"
"border-radius: 2px;\n"
"\n"
"padding: 2px;\n"
"\n"
"background-color: rgba(0, 0, 128, 1.0);\n"
"\n"
"font: bold italic 15px;\n"
"\n"
"color:white;\n"
"\n"
"}\n"
"\n"
"QComboBox\n"
"\n"
"{\n"
"\n"
"color:rgba(0, 0, 128, 1.0);\n"
"\n"
"background-color: white;\n"
"\n"
"border-color: white;\n"
"\n"
"border-width: 1px;\n"
"\n"
"border-style: solid;\n"
"\n"
"padding: 1px 0px 1px 3px; /*This makes text colour work*/\n"
"\n"
"}\n"
"\n"
"QPushButton{\n"
"\n"
"border-radius: 2px;\n"
"\n"
"padding: 2px;\n"
"\n"
"background-color: rgba(0, 0, 128, 1.0);\n"
"\n"
"font: bold italic 15px;\n"
"\n"
"color:white;\n"
"\n"
"}\n"
"\n"
"background-color : rgb(173, 127, 168)\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        cb_Sensor = new QComboBox(centralwidget);
        cb_Sensor->setObjectName(QStringLiteral("cb_Sensor"));
        cb_Sensor->setGeometry(QRect(20, 130, 191, 25));
        cb_Algorithm = new QComboBox(centralwidget);
        cb_Algorithm->setObjectName(QStringLiteral("cb_Algorithm"));
        cb_Algorithm->setGeometry(QRect(20, 210, 191, 25));
        label_Sensor = new QLabel(centralwidget);
        label_Sensor->setObjectName(QStringLiteral("label_Sensor"));
        label_Sensor->setGeometry(QRect(20, 100, 61, 21));
        label_Algorithm = new QLabel(centralwidget);
        label_Algorithm->setObjectName(QStringLiteral("label_Algorithm"));
        label_Algorithm->setGeometry(QRect(20, 180, 91, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(840, 30, 61, 21));
        pb_Play = new QPushButton(centralwidget);
        pb_Play->setObjectName(QStringLiteral("pb_Play"));
        pb_Play->setGeometry(QRect(100, 660, 89, 25));
        pb_SelectDirectory = new QPushButton(centralwidget);
        pb_SelectDirectory->setObjectName(QStringLiteral("pb_SelectDirectory"));
        pb_SelectDirectory->setGeometry(QRect(20, 290, 131, 21));
        list_FileList = new QListWidget(centralwidget);
        list_FileList->setObjectName(QStringLiteral("list_FileList"));
        list_FileList->setGeometry(QRect(20, 360, 256, 281));
        pb_SelectModel = new QPushButton(centralwidget);
        pb_SelectModel->setObjectName(QStringLiteral("pb_SelectModel"));
        pb_SelectModel->setGeometry(QRect(20, 250, 101, 21));
        pb_SelectWeight = new QPushButton(centralwidget);
        pb_SelectWeight->setObjectName(QStringLiteral("pb_SelectWeight"));
        pb_SelectWeight->setGeometry(QRect(130, 250, 111, 21));
        label_original_img = new QLabel(centralwidget);
        label_original_img->setObjectName(QStringLiteral("label_original_img"));
        label_original_img->setGeometry(QRect(360, 160, 512, 384));
        label_original_img->setBaseSize(QSize(640, 480));
        label_original_img->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        label_result_img = new QLabel(centralwidget);
        label_result_img->setObjectName(QStringLiteral("label_result_img"));
        label_result_img->setGeometry(QRect(890, 160, 512, 384));
        label_result_img->setBaseSize(QSize(640, 480));
        label_result_img->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        label_FileList = new QLabel(centralwidget);
        label_FileList->setObjectName(QStringLiteral("label_FileList"));
        label_FileList->setGeometry(QRect(20, 330, 71, 21));
        label_fps = new QLabel(centralwidget);
        label_fps->setObjectName(QStringLiteral("label_fps"));
        label_fps->setGeometry(QRect(1280, 550, 121, 21));
        label_fps->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1497, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        cb_Sensor->clear();
        cb_Sensor->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "lidar", Q_NULLPTR)
         << QApplication::translate("MainWindow", "cam", Q_NULLPTR)
         << QApplication::translate("MainWindow", "can", Q_NULLPTR)
         << QApplication::translate("MainWindow", "imu", Q_NULLPTR)
         << QApplication::translate("MainWindow", "gps", Q_NULLPTR)
        );
        cb_Algorithm->clear();
        cb_Algorithm->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Lane Detection", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Object Detection", Q_NULLPTR)
        );
        label_Sensor->setText(QApplication::translate("MainWindow", "Sensor", Q_NULLPTR));
        label_Algorithm->setText(QApplication::translate("MainWindow", "Algorithm", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Result", Q_NULLPTR));
        pb_Play->setText(QApplication::translate("MainWindow", "play", Q_NULLPTR));
        pb_SelectDirectory->setText(QApplication::translate("MainWindow", "select directory", Q_NULLPTR));
        pb_SelectModel->setText(QApplication::translate("MainWindow", "select model", Q_NULLPTR));
        pb_SelectWeight->setText(QApplication::translate("MainWindow", "select weight", Q_NULLPTR));
        label_original_img->setText(QApplication::translate("MainWindow", "original Image Widget", Q_NULLPTR));
        label_result_img->setText(QApplication::translate("MainWindow", "result Image Widget", Q_NULLPTR));
        label_FileList->setText(QApplication::translate("MainWindow", "File list", Q_NULLPTR));
        label_fps->setText(QApplication::translate("MainWindow", "fps", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
