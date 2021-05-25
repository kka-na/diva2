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
#include <QtWidgets/QGraphicsView>
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
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label;
    QLabel *label_2;
    QGraphicsView *graphicsView_2;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_select;
    QListWidget *listDir;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1512, 776);
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
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 130, 191, 25));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(20, 210, 191, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 100, 61, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 180, 91, 21));
        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(340, 70, 1041, 581));
        graphicsView_2->setStyleSheet(QStringLiteral(""));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(840, 30, 61, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 660, 89, 25));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 330, 71, 20));
        pushButton_select = new QPushButton(centralwidget);
        pushButton_select->setObjectName(QStringLiteral("pushButton_select"));
        pushButton_select->setGeometry(QRect(20, 290, 131, 21));
        listDir = new QListWidget(centralwidget);
        listDir->setObjectName(QStringLiteral("listDir"));
        listDir->setGeometry(QRect(20, 360, 256, 281));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 250, 101, 21));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(130, 250, 111, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1512, 22));
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
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "lidar", Q_NULLPTR)
         << QApplication::translate("MainWindow", "cam", Q_NULLPTR)
         << QApplication::translate("MainWindow", "can", Q_NULLPTR)
         << QApplication::translate("MainWindow", "imu", Q_NULLPTR)
         << QApplication::translate("MainWindow", "gps", Q_NULLPTR)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Lane Detection", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Object Detection", Q_NULLPTR)
        );
        label->setText(QApplication::translate("MainWindow", "Sensor", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Algorithm", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Result", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "play", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "File list", Q_NULLPTR));
        pushButton_select->setText(QApplication::translate("MainWindow", "select directory", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "select model", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "select weight", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
