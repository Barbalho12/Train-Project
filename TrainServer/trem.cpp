#include <iostream>
#include "trem.h"

Trem::Trem(int id, int x, int y, int velocidade ,int step, int top,int left,int right,int bottom){
    this->id = id;
    this->x = x;
    this->y = y;
    this->step = step;
    this->top = top;
    this->left = left;
    this->right = right;
    this->bottom = bottom;
    this->velocidade = velocidade;
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
        if (enable)
        {
            emit updateGUI(id,x,y);
            if (y+10 == top && x+10 < right){
                x+=step;
                std::cout << "a" << std::endl;
            }else if (x+10 == right && y+10 < bottom){
                y+=step;
                std::cout << "b" << std::endl;
            }else if (x+10 > left && y+10 == bottom){
                x-=step;
                std::cout << "c" << std::endl;
            }else if (x+10 == left && y+10 > top){
                y-=step;
                std::cout << "d" << std::endl;
            }else{
                std::cout << x <<" - " << y<< std::endl;
            }
        }
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}
