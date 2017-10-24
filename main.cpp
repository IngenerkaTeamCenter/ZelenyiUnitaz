#include <iostream>
#include "Lib\\TXLib.h"

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

void draw_button(Knopka knop)
{
    txSetColour(RGB(0, 0, 0), 1);
    txSetFillColour(RGB( 195, 195, 195));
    txSelectFont("Times New Roman", 25);

    txRectangle(knop.x,knop.y,knop.x+200,knop.y+100);
    txDrawText(knop.x, knop.y + 40, knop.x + 200, knop.y + 100, knop.text, DT_CENTER);
}

void btn_click (Knopka* knop)
{
    if (txMouseButtons() & 1
        && txMouseX() >= knop->x
        && txMouseX() <= knop->x + 200
        && txMouseY() >= knop->y
        && txMouseY() <= knop->y + 100)
    {
        knop->risovatKartinku = -knop->risovatKartinku;
        txSleep(100);
    }
}

int main()
{
    txCreateWindow(800,720);

    HDC tv = txLoadImage ("Icons\\tv.bmp");

    Knopka knopki_dlya_menu[10];
    knopki_dlya_menu[0] = {0, 0, "vanna", -1, tv};
    knopki_dlya_menu[1] = {200, 0, "zal", -1, tv};
    knopki_dlya_menu[2] = {400, 0, "kuxnua", -1, tv};
    knopki_dlya_menu[3] = {600, 0, "spalnua", -1, tv};

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(RGB(112, 146, 190));
        txClear();

        for (int nomer_knopki = 0;
             nomer_knopki < 4;
             nomer_knopki++)
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