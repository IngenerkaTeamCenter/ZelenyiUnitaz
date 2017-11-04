#include <iostream>
#include "Lib\\TXLib.h"
#include "Lib\\lol.cpp"


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

int main()
{

    txCreateWindow(800,720);

    HDC tv = txLoadImage ("Icons\\tv.bmp");

    HDC chair = txLoadImage ("Icons\\tv.bmp");

    HDC  TV = txLoadImage ("Icons\\tv.bmp");
    HDC  Chair = txLoadImage ("Icons\\tv.bmp");
    HDC  Table = txLoadImage ("Icons\\tv.bmp");
    HDC  Bed = txLoadImage ("Icons\\tv.bmp");

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

        Level_1 (TV, Chair, Table, Bed) ;

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
    txDeleteDC (chair);
    txDeleteDC (TV);
    txDeleteDC (Chair);
    txDeleteDC (Table);
    txDeleteDC (Bed);

    return 0;
}
