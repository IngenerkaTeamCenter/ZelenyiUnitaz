#include <iostream>
#include "Lib\\TXLib.h"
#include "Lib\\Const.cpp"

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

int mode = GAME_MODE;

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

    txCreateWindow(1000,720);

    HDC tv = txLoadImage ("Icons\\tv.bmp");

    HDC chair = txLoadImage ("Icons\\tv.bmp");

    HDC  TV = txLoadImage ("Icons\\tv.bmp");
    HDC  Chair = txLoadImage ("Icons\\tv.bmp");
    HDC  Table = txLoadImage ("Icons\\tv.bmp");
    HDC  Bed = txLoadImage ("Icons\\tv.bmp");

    Knopka knopki_dlya_menu[KOLVO_KNOPOK];
    knopki_dlya_menu[0] = {0, 0, "vanna", -1, tv};
    knopki_dlya_menu[1] = {200, 0, "zal", -1, tv};
    knopki_dlya_menu[2] = {400, 0, "kuxnua", -1, tv};
    knopki_dlya_menu[3] = {600, 0, "spalnua", -1, tv};
    knopki_dlya_menu[4] = {800, 0, "spalnua", -1, tv};

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(RGB(112, 146, 190));
        txClear();

        Level_1 (TV, Chair, Table, Bed) ;

        for (int nomer_knopki = 0;
             nomer_knopki < KOLVO_KNOPOK;
             nomer_knopki++)
        {
            draw_button(knopki_dlya_menu[nomer_knopki]);
            btn_click (&knopki_dlya_menu[nomer_knopki]);
        }

        for (int nomer_knopki = 0;
             nomer_knopki < KOLVO_KNOPOK;
             nomer_knopki++)
        {
            if (knopki_dlya_menu[nomer_knopki].risovatKartinku == 1)
            {
                txBitBlt (txDC(), 500, 500, 30, 30, knopki_dlya_menu[nomer_knopki].kartinka, 0, 0);
            }
        }

        txSleep (10);
        txEnd();
    }

    for (int nomer_knopki = 0; nomer_knopki < KOLVO_KNOPOK; nomer_knopki++)
    {
        txDeleteDC (knopki_dlya_menu[nomer_knopki].kartinka);
    }

    txDeleteDC (tv);
    txDeleteDC (chair);

    txDeleteDC (TV);
    txDeleteDC (Chair);
    txDeleteDC (Table);
    txDeleteDC (Bed);

    return 0;
}
