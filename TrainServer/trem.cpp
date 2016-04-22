#include <iostream>
#include "trem.h"

Trem::Trem(int id, int x, int y, int velocidade ,int step, bool clockwise, int top,int left,int right,int bottom){
    this->id = id;
    this->x = x;
    this->y = y;
    this->step = step;
    this->top = top;
    this->left = left;
    this->right = right;
    this->bottom = bottom;
    this->velocidade = velocidade;
    this->clockwise = clockwise;
    enable = true;
}

Trem::~Trem(){
    threadTrem.join();
}

void Trem::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

void Trem::setEnable(bool enable)
{
    this->enable = enable;
}

void Trem::start()
{
    threadTrem = std::thread(&Trem::run,this);
}

void Trem::run(){
    while(true){
        if (enable){
            emit updateGUI(id,x,y);
            if (clockwise){
                if (y+10 == top && x+10 < right){
                    x+=step;
                }else if (x+10 == right && y+10 < bottom){
                    y+=step;
                }else if (x+10 > left && y+10 == bottom){
                    x-=step;
                }else if (x+10 == left && y+10 > top){
                    y-=step;
                }else{
                    std::cout << x <<" Error " << y<< std::endl;
                }
            }else{
                if (y+10 == top && x+10 > left){
                    x-=step;
                }else if (x+10 == right && y+10 > top){
                    y-=step;
                }else if (x+10 < right && y+10 == bottom){
                    x+=step;
                }else if (x+10 == left && y+10 < bottom){
                    y+=step;
                }else{
                    std::cout << x <<" Error " << y<< std::endl;
                }
            }
        }
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}
