#include <iostream>
#include "Lib\\TXLib.h"
#include "Lib\\Const.cpp"
#include "Lib\\lol.cpp"
#include "Lib\\Menu.cpp"

int mode = GAME_MODE;

int main()
{
    txCreateWindow(1000,720);

    HDC  TV = txLoadImage ("Icons\\tv.bmp");
    HDC  Chair = txLoadImage ("Icons\\tv.bmp");
    HDC  Table = txLoadImage ("Icons\\tv.bmp");
    HDC  Bed = txLoadImage ("Icons\\tv.bmp");

    HDC kartinka = NULL;
    bool risovat = false;
    int x = 0;
    int y = 0;

    zap();

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
            btn_click (&knopki_dlya_menu[nomer_knopki], &kartinka);
            btn_navashdenie(&knopki_dlya_menu[nomer_knopki]);
        }

        for (int nomer_knopki = 0;
             nomer_knopki < KOLVO_KNOPOK;
             nomer_knopki++)
        {
            if (knopki_dlya_menu[nomer_knopki].risovatKartinku == 1)
            {
                txBitBlt (txDC(), knopki_dlya_menu[nomer_knopki].x, knopki_dlya_menu[nomer_knopki].y, 30, 30, knopki_dlya_menu[nomer_knopki].kartinka, 0, 0);
            }
        }
        if (txMouseButtons() & 1
            && txMouseY() > 100)
            {
                risovat = true;
                x = txMouseX();
                y = txMouseY();
             }
        if (risovat)
        {
            txBitBlt (txDC(), x, y, 30, 30, kartinka, 0, 0);
        }

        txSleep (10);
        txEnd();
    }

    for (int nomer_knopki = 0; nomer_knopki < KOLVO_KNOPOK; nomer_knopki++)
    {
        txDeleteDC (knopki_dlya_menu[nomer_knopki].kartinka);
    }

    txDeleteDC (TV);
    txDeleteDC (Chair);
    txDeleteDC (Table);
    txDeleteDC (Bed);

    return 0;
}
