#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"

#define PORTNUM 4325
#define IP_SERV "192.168.0.102"

struct Mensagem {
    public:
        int trainID;
        float speed;
        bool travado;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Trem *createTrem(int id, int velocidade, int step, bool clockwise, QRect qtrem, QRect qtrilho);
    ~MainWindow();

public slots:
    void updateInterface(int, int, int);
    void socketHandler(int socketDescriptor, Mensagem mensagem);
    void server();

private:
    Ui::MainWindow *ui;
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
    Trem *trem6;
    std::thread threadServer;
    std::thread threadStartServer;
    Mensagem mensagem;
    void updateTrains();
    //std::thread initServer;
};

#endif // MAINWINDOW_H
