#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    //
    ui->setupUi(this);
    //

    // Criando o trem
    trem1 = new Trem(1, 30, 10);
    connect(trem1, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    trem1->start();
    // Criando o trem
    trem2 = new Trem(2, 180, 10);
    connect(trem2, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    trem2->start();
    // Criando o trem
    trem3 = new Trem(3, 330, 10);
    connect(trem3, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    trem3->start();
    // Criando o trem
    trem4 = new Trem(4, 360, 160);
    connect(trem4, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    trem4->start();
    trem4->setVelocidade(20);
    // Criando o trem
    trem5 = new Trem(5, 430, 270);
    connect(trem5, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
    trem5->start();
    // Criando o trem
    trem6 = new Trem(6, 10, 260);
    connect(trem6, SIGNAL(updateGUI(int, int, int)), SLOT(updateInterface(int, int, int)));
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
