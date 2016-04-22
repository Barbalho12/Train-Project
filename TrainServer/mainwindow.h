#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"

#define PORTNUM 4325
#define IP_SERV "10.5.30.75"

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
};

#endif // MAINWINDOW_H
