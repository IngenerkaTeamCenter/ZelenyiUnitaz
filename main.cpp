#include <iostream>
#include "TXLib.h"

using namespace std;

struct Object {
int x;   //расположение по x
int y;   //расположение по y
int o;   //объект
int v;   //вид
};

struct Mode {
int best;
int game;
};



int main()
{
    txCreateWindow(1280,720);

    int risovatKartinku = 0;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColor(TX_BLACK);
        txClear();

        txSetColour(RGB(255, 255, 255), 25);
        txSetFillColour(RGB(255, 255, 255));
        txRectangle(100,200,300,300);

        if (txMouseButtons() & 1
            && txMouseX() >= 100
            && txMouseX() <= 300
            && txMouseY() >= 200
            && txMouseY() <= 300)
            risovatKartinku = 1;
        if (txMouseButtons() & 2
            && txMouseX() >= 100
            && txMouseX() <= 300
            && txMouseY() >= 200
            && txMouseY() <= 300)
            risovatKartinku = 0;

        if (risovatKartinku == 1)
            txRectangle (400, 500, 600, 600);
        txSleep (10);
    }

    begin (0);



    return 0;
}
