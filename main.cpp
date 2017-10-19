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
    int mx;   //расположение по x
    int my;   //расположение по y
    int mo;   //тип объекта (шкаф, стол)
    int mv;   //вид объекта (красный шкаф, сломанный шкаф)
};

struct Button {
    int bx;
    int by;
    int bt;
    int bp;


};

const int GAME_MODE = 1;
const int REDACTOR_MODE = 100;

int mode = GAME_MODE;

void draw_button(int x, int y, const char* text)
{
    txSetColour(RGB(0, 0, 0), 1);
    txSetFillColour(RGB(255, 255, 255));
    txSelectFont("Times New Roman", 25);
    txRectangle(x, y,400,100);
    txTextOut(x + 40, y + 40, text);
}

int main()
{
    txCreateWindow(800,720);

    int risovatKartinku = -1;
    HDC tv = txLoadImage ("Icons\\телевизор.bmp");


  //  int risovatKartinku = 1;
    HDC du = txLoadImage ("Icons\\духовка.bmp");

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        txSetColour(RGB(0, 0, 0), 1);
        txSetFillColour(RGB(255, 255, 255));
        txSelectFont("Times New Roman", 25);
        draw_button(0, 0, "Телевизор");
        draw_button(200, 0, "Стул");

        if (txMouseButtons() & 1
            && txMouseX() >= 0
            && txMouseX() <= 200
            && txMouseY() >= 0
            && txMouseY() <= 100)
        {
            risovatKartinku = -risovatKartinku;
            txSleep(100);
        }
        if (txMouseButtons() & 1
            && txMouseX() >= 200
            && txMouseX() <= 200
            && txMouseY() >= 0
            && txMouseY() <= 100)
        {
            risovatKartinku = risovatKartinku;
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
    txDeleteDC (du);

    return 0;
}
