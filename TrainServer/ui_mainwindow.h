/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *labelTrilho01;
    QLabel *labelTrilho03;
    QLabel *labelTrilho02;
    QLabel *labelTrilho04;
    QLabel *labelTrilho06;
    QLabel *labelTrilho05;
    QLabel *labelTrem01;
    QLabel *labelTrem02;
    QLabel *labelTrem03;
    QLabel *labelTrem04;
    QLabel *labelTrem06;
    QLabel *labelTrem05;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(457, 390);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelTrilho01 = new QLabel(centralWidget);
        labelTrilho01->setObjectName(QStringLiteral("labelTrilho01"));
        labelTrilho01->setGeometry(QRect(20, 20, 140, 100));
        labelTrilho01->setStyleSheet(QLatin1String("background-color: yellow;\n"
"border: 3px dashed black"));
        labelTrilho03 = new QLabel(centralWidget);
        labelTrilho03->setObjectName(QStringLiteral("labelTrilho03"));
        labelTrilho03->setGeometry(QRect(300, 20, 140, 100));
        labelTrilho03->setStyleSheet(QLatin1String("background-color: yellow;\n"
"border: 3px dashed black"));
        labelTrilho02 = new QLabel(centralWidget);
        labelTrilho02->setObjectName(QStringLiteral("labelTrilho02"));
        labelTrilho02->setGeometry(QRect(160, 20, 140, 100));
        labelTrilho02->setStyleSheet(QLatin1String("background-color: orange;\n"
"border: 3px dashed black"));
        labelTrilho04 = new QLabel(centralWidget);
        labelTrilho04->setObjectName(QStringLiteral("labelTrilho04"));
        labelTrilho04->setGeometry(QRect(90, 120, 280, 100));
        labelTrilho04->setStyleSheet(QLatin1String("background-color: red;\n"
"border: 3px dashed black"));
        labelTrilho06 = new QLabel(centralWidget);
        labelTrilho06->setObjectName(QStringLiteral("labelTrilho06"));
        labelTrilho06->setGeometry(QRect(230, 220, 210, 100));
        labelTrilho06->setStyleSheet(QLatin1String("background-color: yellow;\n"
"border: 3px dashed black"));
        labelTrilho05 = new QLabel(centralWidget);
        labelTrilho05->setObjectName(QStringLiteral("labelTrilho05"));
        labelTrilho05->setGeometry(QRect(20, 220, 210, 100));
        labelTrilho05->setStyleSheet(QLatin1String("background-color: orange;\n"
"border: 3px dashed black"));
        labelTrem01 = new QLabel(centralWidget);
        labelTrem01->setObjectName(QStringLiteral("labelTrem01"));
        labelTrem01->setGeometry(QRect(30, 10, 20, 20));
        labelTrem01->setStyleSheet(QStringLiteral("background-color:  blue"));
        labelTrem02 = new QLabel(centralWidget);
        labelTrem02->setObjectName(QStringLiteral("labelTrem02"));
        labelTrem02->setGeometry(QRect(180, 10, 20, 20));
        labelTrem02->setStyleSheet(QStringLiteral("background-color:  brown"));
        labelTrem03 = new QLabel(centralWidget);
        labelTrem03->setObjectName(QStringLiteral("labelTrem03"));
        labelTrem03->setGeometry(QRect(330, 10, 20, 20));
        labelTrem03->setStyleSheet(QStringLiteral("background-color:  purple"));
        labelTrem04 = new QLabel(centralWidget);
        labelTrem04->setObjectName(QStringLiteral("labelTrem04"));
        labelTrem04->setGeometry(QRect(80, 140, 20, 20));
        labelTrem04->setStyleSheet(QStringLiteral("background-color:  darkblue"));
        labelTrem06 = new QLabel(centralWidget);
        labelTrem06->setObjectName(QStringLiteral("labelTrem06"));
        labelTrem06->setGeometry(QRect(430, 230, 20, 20));
        labelTrem06->setStyleSheet(QStringLiteral("background-color:  green"));
        labelTrem05 = new QLabel(centralWidget);
        labelTrem05->setObjectName(QStringLiteral("labelTrem05"));
        labelTrem05->setGeometry(QRect(10, 230, 20, 20));
        labelTrem05->setStyleSheet(QStringLiteral("background-color:  darkgreen"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 457, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        labelTrilho01->setText(QString());
        labelTrilho03->setText(QString());
        labelTrilho02->setText(QString());
        labelTrilho04->setText(QString());
        labelTrilho06->setText(QString());
        labelTrilho05->setText(QString());
        labelTrem01->setText(QString());
        labelTrem02->setText(QString());
        labelTrem03->setText(QString());
        labelTrem04->setText(QString());
        labelTrem06->setText(QString());
        labelTrem05->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
