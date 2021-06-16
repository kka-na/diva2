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
    QLabel *label_Result;
    QPushButton *pb_Play;
    QPushButton *pb_Select_Directory;
    QListWidget *list_FileList;
    QPushButton *pb_Select_DataFile;
    QPushButton *pb_Select_ConfigFile;
    QLabel *label_original_img;
    QLabel *label_result_img;
    QLabel *label_InputFiles;
    QLabel *label_fps;
    QPushButton *pb_Select_WeightFile;
    QLabel *label_DataFile;
    QLabel *label_ConfigFile;
    QLabel *label_WeightFile;
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
        cb_Sensor->setGeometry(QRect(90, 58, 191, 25));
        cb_Algorithm = new QComboBox(centralwidget);
        cb_Algorithm->setObjectName(QStringLiteral("cb_Algorithm"));
        cb_Algorithm->setGeometry(QRect(119, 88, 191, 25));
        label_Sensor = new QLabel(centralwidget);
        label_Sensor->setObjectName(QStringLiteral("label_Sensor"));
        label_Sensor->setGeometry(QRect(20, 60, 61, 21));
        label_Algorithm = new QLabel(centralwidget);
        label_Algorithm->setObjectName(QStringLiteral("label_Algorithm"));
        label_Algorithm->setGeometry(QRect(20, 90, 91, 21));
        label_Result = new QLabel(centralwidget);
        label_Result->setObjectName(QStringLiteral("label_Result"));
        label_Result->setGeometry(QRect(840, 30, 61, 21));
        pb_Play = new QPushButton(centralwidget);
        pb_Play->setObjectName(QStringLiteral("pb_Play"));
        pb_Play->setGeometry(QRect(100, 660, 89, 25));
        pb_Select_Directory = new QPushButton(centralwidget);
        pb_Select_Directory->setObjectName(QStringLiteral("pb_Select_Directory"));
        pb_Select_Directory->setGeometry(QRect(120, 210, 151, 21));
        QPalette palette;
        QBrush brush(QColor(0, 0, 128, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(0, 0, 128, 128));
        brush2.setStyle(Qt::NoBrush);
        // palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(0, 0, 128, 128));
        brush3.setStyle(Qt::NoBrush);
        // palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush4(QColor(0, 0, 128, 128));
        brush4.setStyle(Qt::NoBrush);
        // palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
        pb_Select_Directory->setPalette(palette);
        pb_Select_Directory->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 128);\n"
"\n"
""));
        list_FileList = new QListWidget(centralwidget);
        list_FileList->setObjectName(QStringLiteral("list_FileList"));
        list_FileList->setGeometry(QRect(20, 240, 256, 281));
        pb_Select_DataFile = new QPushButton(centralwidget);
        pb_Select_DataFile->setObjectName(QStringLiteral("pb_Select_DataFile"));
        pb_Select_DataFile->setGeometry(QRect(120, 120, 151, 21));
        pb_Select_DataFile->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 128);\n"
"\n"
""));
        pb_Select_ConfigFile = new QPushButton(centralwidget);
        pb_Select_ConfigFile->setObjectName(QStringLiteral("pb_Select_ConfigFile"));
        pb_Select_ConfigFile->setGeometry(QRect(120, 150, 151, 21));
        pb_Select_ConfigFile->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 128);\n"
"\n"
""));
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
        label_InputFiles = new QLabel(centralwidget);
        label_InputFiles->setObjectName(QStringLiteral("label_InputFiles"));
        label_InputFiles->setGeometry(QRect(20, 210, 90, 21));
        label_InputFiles->setAlignment(Qt::AlignCenter);
        label_fps = new QLabel(centralwidget);
        label_fps->setObjectName(QStringLiteral("label_fps"));
        label_fps->setGeometry(QRect(1280, 550, 121, 21));
        label_fps->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pb_Select_WeightFile = new QPushButton(centralwidget);
        pb_Select_WeightFile->setObjectName(QStringLiteral("pb_Select_WeightFile"));
        pb_Select_WeightFile->setGeometry(QRect(120, 180, 151, 21));
        pb_Select_WeightFile->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 128);\n"
"\n"
""));
        label_DataFile = new QLabel(centralwidget);
        label_DataFile->setObjectName(QStringLiteral("label_DataFile"));
        label_DataFile->setGeometry(QRect(20, 120, 90, 21));
        label_DataFile->setBaseSize(QSize(640, 480));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::NoBrush);
        // palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        QBrush brush6(QColor(255, 255, 255, 128));
        brush6.setStyle(Qt::NoBrush);
        // palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::NoBrush);
        // palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
        label_DataFile->setPalette(palette1);
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_DataFile->setFont(font);
        label_DataFile->setLayoutDirection(Qt::LeftToRight);
        label_DataFile->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 128);\n"
"color:rgb(255, 255, 255);\n"
""));
        label_DataFile->setAlignment(Qt::AlignCenter);
        label_ConfigFile = new QLabel(centralwidget);
        label_ConfigFile->setObjectName(QStringLiteral("label_ConfigFile"));
        label_ConfigFile->setGeometry(QRect(20, 150, 90, 21));
        label_ConfigFile->setBaseSize(QSize(640, 480));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::NoBrush);
        // palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
        QBrush brush9(QColor(255, 255, 255, 128));
        brush9.setStyle(Qt::NoBrush);
        // palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush10(QColor(255, 255, 255, 128));
        brush10.setStyle(Qt::NoBrush);
        // palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
        label_ConfigFile->setPalette(palette2);
        label_ConfigFile->setFont(font);
        label_ConfigFile->setLayoutDirection(Qt::LeftToRight);
        label_ConfigFile->setStyleSheet(QLatin1String("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
"<ui version=\"4.0\">\n"
" <widget name=\"__qt_fake_top_level\">\n"
"  <widget class=\"QLabel\" name=\"label_ConfigFile_3\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>20</x>\n"
"     <y>120</y>\n"
"     <width>90</width>\n"
"     <height>21</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"baseSize\">\n"
"    <size>\n"
"     <width>640</width>\n"
"     <height>480</height>\n"
"    </size>\n"
"   </property>\n"
"   <property name=\"palette\">\n"
"    <palette>\n"
"     <active>\n"
"      <colorrole role=\"WindowText\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Button\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"  "
                        "       <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Text\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"ButtonText\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Base\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Window\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
""
                        "         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"PlaceholderText\">\n"
"       <brush brushstyle=\"NoBrush\">\n"
"        <color alpha=\"128\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>0</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"     </active>\n"
"     <inactive>\n"
"      <colorrole role=\"WindowText\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Button\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole ro"
                        "le=\"Text\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"ButtonText\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Base\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Window\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"   "
                        "    </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"PlaceholderText\">\n"
"       <brush brushstyle=\"NoBrush\">\n"
"        <color alpha=\"128\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"     </inactive>\n"
"     <disabled>\n"
"      <colorrole role=\"WindowText\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Button\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Text\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"    "
                        "     <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"ButtonText\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Base\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Window\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"PlaceholderText\">\n"
"       <brush b"
                        "rushstyle=\"NoBrush\">\n"
"        <color alpha=\"128\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>0</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"     </disabled>\n"
"    </palette>\n"
"   </property>\n"
"   <property name=\"font\">\n"
"    <font>\n"
"     <pointsize>-1</pointsize>\n"
"     <weight>75</weight>\n"
"     <italic>true</italic>\n"
"     <bold>true</bold>\n"
"    </font>\n"
"   </property>\n"
"   <property name=\"layoutDirection\">\n"
"    <enum>Qt::LeftToRight</enum>\n"
"   </property>\n"
"   <property name=\"styleSheet\">\n"
"    <string notr=\"true\">background-color: rgb(0, 0, 128);\n"
"color:rgb(255, 255, 255);\n"
"</string>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string>Data File</string>\n"
"   </property>\n"
"   <property name=\"alignment\">\n"
"    <set>Qt::AlignCenter</set>\n"
"   </property>\n"
"  </widget>\n"
" </widget>\n"
" <resources/>\n"
"</ui>\n"
""));
        label_ConfigFile->setAlignment(Qt::AlignCenter);
        label_WeightFile = new QLabel(centralwidget);
        label_WeightFile->setObjectName(QStringLiteral("label_WeightFile"));
        label_WeightFile->setGeometry(QRect(20, 180, 90, 21));
        label_WeightFile->setBaseSize(QSize(640, 480));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush11(QColor(255, 255, 255, 128));
        brush11.setStyle(Qt::NoBrush);
        // palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        QBrush brush12(QColor(255, 255, 255, 128));
        brush12.setStyle(Qt::NoBrush);
        // palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush13(QColor(255, 255, 255, 128));
        brush13.setStyle(Qt::NoBrush);
        // palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
        label_WeightFile->setPalette(palette3);
        label_WeightFile->setFont(font);
        label_WeightFile->setLayoutDirection(Qt::LeftToRight);
        label_WeightFile->setStyleSheet(QLatin1String("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
"<ui version=\"4.0\">\n"
" <widget name=\"__qt_fake_top_level\">\n"
"  <widget class=\"QLabel\" name=\"label_ConfigFile_3\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>20</x>\n"
"     <y>120</y>\n"
"     <width>90</width>\n"
"     <height>21</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"baseSize\">\n"
"    <size>\n"
"     <width>640</width>\n"
"     <height>480</height>\n"
"    </size>\n"
"   </property>\n"
"   <property name=\"palette\">\n"
"    <palette>\n"
"     <active>\n"
"      <colorrole role=\"WindowText\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Button\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"  "
                        "       <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Text\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"ButtonText\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Base\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Window\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
""
                        "         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"PlaceholderText\">\n"
"       <brush brushstyle=\"NoBrush\">\n"
"        <color alpha=\"128\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>0</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"     </active>\n"
"     <inactive>\n"
"      <colorrole role=\"WindowText\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Button\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole ro"
                        "le=\"Text\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"ButtonText\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Base\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Window\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"   "
                        "    </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"PlaceholderText\">\n"
"       <brush brushstyle=\"NoBrush\">\n"
"        <color alpha=\"128\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"     </inactive>\n"
"     <disabled>\n"
"      <colorrole role=\"WindowText\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Button\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Text\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"    "
                        "     <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"ButtonText\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>255</red>\n"
"         <green>255</green>\n"
"         <blue>255</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Base\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"Window\">\n"
"       <brush brushstyle=\"SolidPattern\">\n"
"        <color alpha=\"255\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>128</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"      <colorrole role=\"PlaceholderText\">\n"
"       <brush b"
                        "rushstyle=\"NoBrush\">\n"
"        <color alpha=\"128\">\n"
"         <red>0</red>\n"
"         <green>0</green>\n"
"         <blue>0</blue>\n"
"        </color>\n"
"       </brush>\n"
"      </colorrole>\n"
"     </disabled>\n"
"    </palette>\n"
"   </property>\n"
"   <property name=\"font\">\n"
"    <font>\n"
"     <pointsize>-1</pointsize>\n"
"     <weight>75</weight>\n"
"     <italic>true</italic>\n"
"     <bold>true</bold>\n"
"    </font>\n"
"   </property>\n"
"   <property name=\"layoutDirection\">\n"
"    <enum>Qt::LeftToRight</enum>\n"
"   </property>\n"
"   <property name=\"styleSheet\">\n"
"    <string notr=\"true\">background-color: rgb(0, 0, 128);\n"
"color:rgb(255, 255, 255);\n"
"</string>\n"
"   </property>\n"
"   <property name=\"text\">\n"
"    <string>Data File</string>\n"
"   </property>\n"
"   <property name=\"alignment\">\n"
"    <set>Qt::AlignCenter</set>\n"
"   </property>\n"
"  </widget>\n"
" </widget>\n"
" <resources/>\n"
"</ui>\n"
""));
        label_WeightFile->setAlignment(Qt::AlignCenter);
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
        label_Result->setText(QApplication::translate("MainWindow", "Result", Q_NULLPTR));
        pb_Play->setText(QApplication::translate("MainWindow", "play", Q_NULLPTR));
        pb_Select_Directory->setText(QApplication::translate("MainWindow", "select directory", Q_NULLPTR));
        pb_Select_DataFile->setText(QApplication::translate("MainWindow", "select file", Q_NULLPTR));
        pb_Select_ConfigFile->setText(QApplication::translate("MainWindow", "select file", Q_NULLPTR));
        label_original_img->setText(QApplication::translate("MainWindow", "original Image Widget", Q_NULLPTR));
        label_result_img->setText(QApplication::translate("MainWindow", "result Image Widget", Q_NULLPTR));
        label_InputFiles->setText(QApplication::translate("MainWindow", "input files", Q_NULLPTR));
        label_fps->setText(QApplication::translate("MainWindow", "fps", Q_NULLPTR));
        pb_Select_WeightFile->setText(QApplication::translate("MainWindow", "select file", Q_NULLPTR));
        label_DataFile->setText(QApplication::translate("MainWindow", "Data File", Q_NULLPTR));
        label_ConfigFile->setText(QApplication::translate("MainWindow", "Config File", Q_NULLPTR));
        label_WeightFile->setText(QApplication::translate("MainWindow", "Weight File", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
