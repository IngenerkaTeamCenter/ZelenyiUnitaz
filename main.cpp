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

struct Knopka {
    int x;
    int y;
    const char* text;
    int risovatKartinku;
    HDC kartinka;
};

const int GAME_MODE = 1;
const int REDACTOR_MODE = 100;

int mode = GAME_MODE;

void draw_button(Knopka knopki_dlya_menu)
{
    txSetColour(RGB(0, 0, 0), 1);
    txSetFillColour(RGB(255, 255, 255));
    txSelectFont("Times New Roman", 25);
    txRectangle(knopki_dlya_menu.x,knopki_dlya_menu.y,knopki_dlya_menu.x+300,knopki_dlya_menu.y+100);
    txTextOut(knopki_dlya_menu.x, knopki_dlya_menu.y + 40, knopki_dlya_menu.text);
}

void btn_click (Knopka* knopki_dlya_menu)
{
    if (txMouseButtons() & 1
        && txMouseX() >= knopki_dlya_menu->x
        && txMouseX() <= knopki_dlya_menu->x + 300
        && txMouseY() >= knopki_dlya_menu->y
        && txMouseY() <= knopki_dlya_menu->y + 100)
    {
        knopki_dlya_menu->risovatKartinku = -knopki_dlya_menu->risovatKartinku;
        txSleep(100);
    }
}

int main()
{
    txCreateWindow(800,720);

    HDC tv = txLoadImage ("Icons\\tv.bmp");

    Knopka knopki_dlya_menu[10];
    knopki_dlya_menu[0] = {0, 0, "TV", -1, tv};

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        txSetColour(RGB(0, 0, 0), 1);
        txSetFillColour(RGB(255, 255, 255));
        txSelectFont("Times New Roman", 25);

        for (int nomer_knopki = 0; nomer_knopki < 1; nomer_knopki++)
        {
            draw_button(knopki_dlya_menu[nomer_knopki]);
            btn_click (&knopki_dlya_menu[nomer_knopki]);
        }

        if (knopki_dlya_menu[0].risovatKartinku == 1)
        {
            txBitBlt (txDC(), 500, 500, 30, 30, knopki_dlya_menu[0].kartinka, 0, 0);
        }

        txSleep (10);
        txEnd();
    }

    for (int nomer_knopki = 0; nomer_knopki < 1; nomer_knopki++)
    {
        txDeleteDC (knopki_dlya_menu[nomer_knopki].kartinka);
    }
    txDeleteDC (tv);

    return 0;
}
