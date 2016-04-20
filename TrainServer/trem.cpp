#include <iostream>
#include "trem.h"

Trem::Trem(int id, int x, int y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    velocidade = 250;
    enable = true;
}

Trem::~Trem()
{
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

void Trem::run()
{
    while(true){
        switch(id){
        case 1:
            if (enable) {
                emit updateGUI(id, x, y);
                if (y == 10 && x < 150) {
                    std::cout << "A" << std::endl;
                    x += 10;
                }
                else if (x == 150 && y < 110) {
                    std::cout << "B" << std::endl;
                    y += 10;
                }
                else if (x > 10 && y == 110) {
                    std::cout << "C" << std::endl;
                    x -= 10;
                }
                else {
                    std::cout << "D" << std::endl;
                    y -= 10;
                }
            }
            break;
        case 2:
            if (enable) {
                emit updateGUI(id, x, y);
                if (y == 10 && x < 290)
                    x += 10;
                else if (x == 290 && y < 110)
                    y += 10;
                else if (x > 150 && y == 110)
                    x -= 10;
                else
                    y -= 10;
            }
            break;
        case 3:
            if (enable) {
                emit updateGUI(id, x, y);
                if (y == 10 && x < 430)
                    x += 10;
                else if (x == 430 && y < 110)
                    y += 10;
                else if (x > 290 && y == 110)
                    x -= 10;
                else
                    y -= 10;
            }
            break;
        case 4:
            if (enable) {
                emit updateGUI(id, x, y);
                if (y == 110 && x < 360)
                    x += 10;
                else if (x == 360 && y < 210)
                    y += 10;
                else if (x > 80 && y == 210)
                    x -= 10;
                else
                    y -= 10;
            }
            break;
        case 5:
            if (enable) {
                emit updateGUI(id, x, y);
                if (y == 210 && x < 430)
                    x += 10;
                else if (x == 430 && y < 310)
                    y += 10;
                else if (x > 220 && y == 310)
                    x -= 10;
                else
                    y -= 10;
            }
            break;
        case 6:
            if (enable) {
                emit updateGUI(id, x, y);
                if (y == 210 && x < 220)
                    x += 10;
                else if (x == 220 && y < 310)
                    y += 10;
                else if (x > 10 && y == 310)
                    x -= 10;
                else
                    y -= 10;
            }
            break;
        default:
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

