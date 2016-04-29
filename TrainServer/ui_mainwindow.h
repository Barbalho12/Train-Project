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
    QLabel *lsem1;
    QLabel *lpanelsem;
    QLabel *lsem2;
    QLabel *lsem3;
    QLabel *lsem4;
    QLabel *lsem5;
    QLabel *lsem6;
    QLabel *lsem7;
    QLabel *lsem8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(540, 390);
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
"border: 3px solid black"));
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
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelTrem01->setFont(font);
        labelTrem01->setStyleSheet(QLatin1String("background-color:  blue;\n"
"color:white;"));
        labelTrem02 = new QLabel(centralWidget);
        labelTrem02->setObjectName(QStringLiteral("labelTrem02"));
        labelTrem02->setGeometry(QRect(180, 10, 20, 20));
        labelTrem02->setFont(font);
        labelTrem02->setStyleSheet(QLatin1String("background-color:  brown;\n"
"color:white;"));
        labelTrem03 = new QLabel(centralWidget);
        labelTrem03->setObjectName(QStringLiteral("labelTrem03"));
        labelTrem03->setGeometry(QRect(330, 10, 20, 20));
        labelTrem03->setFont(font);
        labelTrem03->setStyleSheet(QLatin1String("background-color:  purple;\n"
"color:white;"));
        labelTrem04 = new QLabel(centralWidget);
        labelTrem04->setObjectName(QStringLiteral("labelTrem04"));
        labelTrem04->setGeometry(QRect(80, 140, 20, 20));
        labelTrem04->setFont(font);
        labelTrem04->setStyleSheet(QLatin1String("background-color:  darkblue;\n"
"color:white;"));
        labelTrem06 = new QLabel(centralWidget);
        labelTrem06->setObjectName(QStringLiteral("labelTrem06"));
        labelTrem06->setGeometry(QRect(430, 230, 20, 20));
        labelTrem06->setFont(font);
        labelTrem06->setStyleSheet(QLatin1String("background-color:  black;\n"
"color:white;"));
        labelTrem05 = new QLabel(centralWidget);
        labelTrem05->setObjectName(QStringLiteral("labelTrem05"));
        labelTrem05->setGeometry(QRect(10, 230, 20, 20));
        labelTrem05->setFont(font);
        labelTrem05->setStyleSheet(QLatin1String("background-color:  darkgreen;\n"
"color:white;"));
        lsem1 = new QLabel(centralWidget);
        lsem1->setObjectName(QStringLiteral("lsem1"));
        lsem1->setGeometry(QRect(490, 80, 16, 16));
        lsem1->setStyleSheet(QLatin1String("background-color: red;\n"
"border-radius:8px;"));
        lpanelsem = new QLabel(centralWidget);
        lpanelsem->setObjectName(QStringLiteral("lpanelsem"));
        lpanelsem->setGeometry(QRect(477, 70, 41, 181));
        lpanelsem->setStyleSheet(QLatin1String("background-color: black;\n"
"border-radius: 2px;"));
        lsem2 = new QLabel(centralWidget);
        lsem2->setObjectName(QStringLiteral("lsem2"));
        lsem2->setGeometry(QRect(490, 100, 16, 16));
        lsem2->setStyleSheet(QLatin1String("background-color: red;\n"
"border-radius:8px;"));
        lsem3 = new QLabel(centralWidget);
        lsem3->setObjectName(QStringLiteral("lsem3"));
        lsem3->setGeometry(QRect(490, 120, 16, 16));
        lsem3->setStyleSheet(QLatin1String("background-color: red;\n"
"border-radius:8px;"));
        lsem4 = new QLabel(centralWidget);
        lsem4->setObjectName(QStringLiteral("lsem4"));
        lsem4->setGeometry(QRect(490, 140, 16, 16));
        lsem4->setStyleSheet(QLatin1String("background-color: red;\n"
"border-radius:8px;"));
        lsem5 = new QLabel(centralWidget);
        lsem5->setObjectName(QStringLiteral("lsem5"));
        lsem5->setGeometry(QRect(490, 160, 16, 16));
        lsem5->setStyleSheet(QLatin1String("background-color: red;\n"
"border-radius:8px;"));
        lsem6 = new QLabel(centralWidget);
        lsem6->setObjectName(QStringLiteral("lsem6"));
        lsem6->setGeometry(QRect(490, 180, 16, 16));
        lsem6->setStyleSheet(QLatin1String("background-color: red;\n"
"border-radius:8px;"));
        lsem7 = new QLabel(centralWidget);
        lsem7->setObjectName(QStringLiteral("lsem7"));
        lsem7->setGeometry(QRect(490, 200, 16, 16));
        lsem7->setStyleSheet(QLatin1String("background-color: red;\n"
"border-radius:8px;"));
        lsem8 = new QLabel(centralWidget);
        lsem8->setObjectName(QStringLiteral("lsem8"));
        lsem8->setGeometry(QRect(490, 220, 16, 16));
        lsem8->setStyleSheet(QLatin1String("background-color: red;\n"
"border-radius:8px;"));
        MainWindow->setCentralWidget(centralWidget);
        lpanelsem->raise();
        labelTrilho01->raise();
        labelTrilho03->raise();
        labelTrilho02->raise();
        labelTrilho04->raise();
        labelTrilho06->raise();
        labelTrilho05->raise();
        labelTrem01->raise();
        labelTrem02->raise();
        labelTrem03->raise();
        labelTrem04->raise();
        labelTrem06->raise();
        labelTrem05->raise();
        lsem1->raise();
        lsem2->raise();
        lsem3->raise();
        lsem4->raise();
        lsem5->raise();
        lsem6->raise();
        lsem7->raise();
        lsem8->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 540, 25));
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
        labelTrem01->setText(QApplication::translate("MainWindow", "01", 0));
        labelTrem02->setText(QApplication::translate("MainWindow", "02", 0));
        labelTrem03->setText(QApplication::translate("MainWindow", "03", 0));
        labelTrem04->setText(QApplication::translate("MainWindow", "04", 0));
        labelTrem06->setText(QApplication::translate("MainWindow", "06", 0));
        labelTrem05->setText(QApplication::translate("MainWindow", "05", 0));
        lsem1->setText(QString());
        lpanelsem->setText(QString());
        lsem2->setText(QString());
        lsem3->setText(QString());
        lsem4->setText(QString());
        lsem5->setText(QString());
        lsem6->setText(QString());
        lsem7->setText(QString());
        lsem8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
