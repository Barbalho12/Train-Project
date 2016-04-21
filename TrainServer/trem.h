#ifndef TREM_H
#define TREM_H

#include <QObject>
#include <thread>
#include <chrono>

using namespace std;

class Trem : public QObject{
    Q_OBJECT
public:
    Trem(int id, int x,int y, int velocidade, int step, bool clockwise, int top,int left,int right,int bottom);
    ~Trem();
    void start();
    void run();
    void setVelocidade(int);
    void setEnable(bool);

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
};

#endif // TREM_H



