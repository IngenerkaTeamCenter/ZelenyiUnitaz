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

void Level_1 (HDC TV, HDC Chair, HDC Table, HDC Bed)
{
      txBitBlt (txDC(), 200, 200, 30, 30, TV);
      txBitBlt (txDC(), 200, 400, 30, 30, TV);
      txBitBlt (txDC(), 400, 200, 30, 30, TV);
      txBitBlt (txDC(), 300, 200, 30, 30, Chair);
      txBitBlt (txDC(), 200, 300, 30, 30, Chair);
      txBitBlt (txDC(), 300, 300, 30, 30, Chair);
      txBitBlt (txDC(), 600, 200, 30, 30, Table);
}



void btn_click (int x, int y, int xx, int yy, int* risovatKartinku)
{
    if (txMouseButtons() & 1
        && txMouseX() >= x
        && txMouseX() <= y
        && txMouseY() >= xx
        && txMouseY() <= yy)
    {
        *risovatKartinku = - *risovatKartinku;
        txSleep(100);
    }

}

int main()
{

    txCreateWindow(800,720);


    int risovatKartinku = -1;
    HDC tv = txLoadImage ("Icons\\телевизор.bmp");

    int risovatKartinku2 = 1;
    HDC chair = txLoadImage ("Icons\\стул.bmp");

    HDC  TV = txLoadImage ("Icons\\телевизор.bmp");
    HDC  Chair = txLoadImage ("Icons\\стул.bmp");
    HDC  Table = txLoadImage ("Icons\\стол.bmp");
    HDC  Bed = txLoadImage ("Icons\\кровать.bmp");

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
        draw_button(400, 0, "Стол");

        btn_click (0,200,0,100, &risovatKartinku);      //0 200 0 100
        btn_click(200,200,0,100, &risovatKartinku2 );

        Level_1 (TV, Chair, Table, Bed) ;

        if (risovatKartinku == 1)
        {
            txBitBlt (txDC(), 500, 500, 30, 30, tv, 0, 0);
        }

         if (risovatKartinku2 == 1)
        {
            txBitBlt (txDC(), 500, 600, 30, 30, chair, 0, 0);
        }

        txSleep (10);
        txEnd();
    }


    txDeleteDC (tv);
    txDeleteDC (chair);

    txDeleteDC (TV);
    txDeleteDC (Chair);
    txDeleteDC (Table);
    txDeleteDC (Bed);

    return 0;
}
