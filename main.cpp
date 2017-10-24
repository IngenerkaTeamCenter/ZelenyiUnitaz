#include <iostream>
#include "Lib\\TXLib.h"

/*
1) Ñòðóêòóðà äëÿ êíîïêè (â êîòîðîé åñòü åù¸ è êàðòèíêà)
2) Íîðìàëüíîå ìåíþ
3) Ñäåëàòü íàæàòèå íà êíîïêó ôóíêöèåé
4) Âûâîäèòü ðàçíûå êàðòèíêè ïî íàæàòèþ íà ðàçíûå êíîïêè
*/

using namespace std;

struct Mebel {
    int x;   //ðàñïîëîæåíèå ïî x
    int y;   //ðàñïîëîæåíèå ïî y
    int o;   //òèï îáúåêòà (øêàô, ñòîë)
    int v;   //âèä îáúåêòà (êðàñíûé øêàô, ñëîìàííûé øêàô)
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

void btn_click (int x, int y, int xx, int yy, int risovatKartinku)
{
    if (txMouseButtons() == 1
        && txMouseX() >= x
        && txMouseX() <= y
        && txMouseY() >= xx
        && txMouseY() <= yy)
    {
        risovatKartinku = -risovatKartinku;
        txSleep(100);
    }
}

int main()
{
    txCreateWindow(800,720);

    int risovatKartinku = -1;
    HDC tv = txLoadImage ("Icons\\òåëåâèçîð.bmp");

    Knopka k = {0, 0, "Òåëåâèçîð"};

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        txSetColour(RGB(0, 0, 0), 1);
        txSetFillColour(RGB(255, 255, 255));
        txSelectFont("Times New Roman", 25);
        draw_button(k);
        
        btn_click (0,200,0,100, risovatKartinku);      //0 200 0 100

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
