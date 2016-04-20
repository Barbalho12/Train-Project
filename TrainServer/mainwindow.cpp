#include "mainwindow.h"
#include "ui_mainwindow.h"

Trem *MainWindow::createTrem(int id, int velocidade, int step, QRect qtrem, QRect qtrilho){
    int x = qtrem.x();
    int y = qtrem.y();
    int top = qtrilho.y();
    int left = qtrilho.x();
    int right = left + qtrilho.width();
    int bottom = top + qtrilho.height();
    Trem *trem = new Trem(id, x, y, velocidade, step, top, left,right,bottom);

    return trem;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);

    trem1 = createTrem(1, 250, 10, ui->labelTrem01->geometry(), ui->labelTrilho01->geometry());
    trem2 = createTrem(2, 140, 10, ui->labelTrem02->geometry(), ui->labelTrilho02->geometry());
    trem3 = createTrem(3, 180, 10, ui->labelTrem03->geometry(), ui->labelTrilho03->geometry());
    trem4 = createTrem(4, 300, 10, ui->labelTrem04->geometry(), ui->labelTrilho04->geometry());
    trem5 = createTrem(5, 80, 10, ui->labelTrem05->geometry(), ui->labelTrilho05->geometry());
    trem6 = createTrem(6, 250, 10, ui->labelTrem06->geometry(), ui->labelTrilho06->geometry());

    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem1->start();
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem2->start();
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem3->start();
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem4->start();
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem5->start();
    connect(trem6,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem6->start();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateInterface(int id, int x, int y) {
    switch(id){
        case 1:
            ui->labelTrem01->setGeometry(x, y, 20, 20);
            break;
        case 2:
            ui->labelTrem02->setGeometry(x, y, 20, 20);
            break;
        case 3:
            ui->labelTrem03->setGeometry(x, y, 20, 20);
            break;
        case 4:
            ui->labelTrem04->setGeometry(x, y, 20, 20);
            break;
        case 5:
            ui->labelTrem05->setGeometry(x, y, 20, 20);
            break;
        case 6:
            ui->labelTrem06->setGeometry(x, y, 20, 20);
            break;
        default:
            break;
    }
}
