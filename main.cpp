#include <iostream>
#include "Lib\\TXLib.h"
#include "Lib\\Const.cpp"
#include "Lib\\lol.cpp"
#include "Lib\\lol.cpp"

int mode = GAME_MODE;

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
    knopki_dlya_menu[0] = {0, 0, "vanna", -1, tv, false};
    knopki_dlya_menu[1] = {200, 0, "zal", -1, tv, false};
    knopki_dlya_menu[2] = {400, 0, "kuxnua", -1, tv, false};
    knopki_dlya_menu[3] = {600, 0, "spalnua", -1, tv, false};
    knopki_dlya_menu[4] = {800, 0, "spalnua", -1, tv, false};

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
            btn_navashdenie(&knopki_dlya_menu[nomer_knopki]);
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
