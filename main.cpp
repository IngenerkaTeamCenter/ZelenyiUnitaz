#include <iostream>
#include "Lib\\TXLib.h"

/*
1) Структура для кнопки (в которой есть ещё и картинка)
2) Нормальное меню
3) Сделать нажатие на кнопку функцией
4) Выводить разные картинки по нажатию на разные кнопки
*/

using namespace std;

struct Mebel {
    int x;   //расположение по x
    int y;   //расположение по y
    int o;   //тип объекта (шкаф, стол)
    int v;   //вид объекта (красный шкаф, сломанный шкаф)
};

struct Knopka{
    int x;
    int y;
    const char* text;

};

const int GAME_MODE = 1;
const int REDACTOR_MODE = 100;

int mode = GAME_MODE;

void draw_button(Knopka k)
{
    txSetColour(RGB(0, 0, 0), 1);
    txSetFillColour(RGB(255, 255, 255));
    txSelectFont("Times New Roman", 25);
    txRectangle(k.x,k.y,k.x+400,k.y+100);
    txTextOut(k.x, k.y + 40, k.text);
}

int main()
{
    txCreateWindow(800,720);

    int risovatKartinku = -1;
    HDC tv = txLoadImage ("Icons\\телевизор.bmp");

    Knopka k = {0, 0, "Телевизор"};

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        txSetColour(RGB(0, 0, 0), 1);
        txSetFillColour(RGB(255, 255, 255));
        txSelectFont("Times New Roman", 25);
        draw_button(k);
        //draw_button(k.x+200, k.y, "Стул");

        if (txMouseButtons() & 1
            && txMouseX() >= 0
            && txMouseX() <= 200
            && txMouseY() >= 0
            && txMouseY() <= 100)
        {
            risovatKartinku = -risovatKartinku;
            txSleep(100);
        }

        if (risovatKartinku == 1)
        {
            txBitBlt (txDC(), 500, 500, 30, 30, tv, 0, 0);
        }

        txSleep (10);
        txEnd();
    }

    txDeleteDC (tv);

    return 0;
}
