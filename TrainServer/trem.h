#ifndef TREM_H
#define TREM_H

#include <QObject>
#include <thread>
#include <chrono>
#include "semaforo.h"
using namespace std;

struct RegiaoCritica {
    public:
        int xi;
        int yi;
        int xf;
        int yf;
        Semaforo *semaforo;
        RegiaoCritica(int xi, int yi, int xf, int yf, Semaforo *semaforo){
            this->xi = xi;
            this->yi = yi;
            this->xf = xf;
            this->yf = yf;
            this->semaforo = semaforo;
        }
};

class Trem : public QObject{
    Q_OBJECT
public:
    //Trem(int id, int x,int y, int velocidade, int step, bool clockwise, int top,int left,int right,int bottom, vector<Semaforo*> semaforos);
    Trem(int id, int x,int y, int velocidade, int step, bool clockwise, int top,int left,int right,int bottom);

    ~Trem();
    void start();
    void run();
    void setVelocidade(int);
    void setEnable(bool);
    void addRegiaoCritica(RegiaoCritica *regiao1, RegiaoCritica *regiao2);
    void addRegiaoCritica(RegiaoCritica *regiao1, RegiaoCritica *regiao2, RegiaoCritica *regiao3);
//    void addSemaforo(Semaforo *semaforo1, Semaforo *semaforo2);
//    void addSemaforo(Semaforo *semaforo1, Semaforo *semaforo2, Semaforo *semaforo3);

signals:
    void updateGUI(int,int,int);

private:
   std::thread threadTrem;
   int id;
   int x;
   int y;
   int velocidade;
   int step;
   bool clockwise;
   int top;
   int left;
   int right;
   int bottom;

   bool enable;

   vector<RegiaoCritica*> regioesCriticas;
};

#endif // TREM_H



