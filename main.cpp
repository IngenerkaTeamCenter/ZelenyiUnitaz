#include "Lib\\TXLib.h"
#include "Lib\\Const.cpp"
#include "Lib\\Files.cpp"
#include "Lib\\Mebel.cpp"
#include "Lib\\Menu.cpp"

int main()
{
    txCreateWindow(1090,720);

    int nomer_kartinki = 0;
    Mebel pics[100];
    int nomer = 0;
    for (nomer = 0; nomer < 100; nomer++);
    {
        pics[nomer].risovat = false;
    }

    zapolnenie_menu();

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(RGB(112, 146, 190));
        txClear();

        //zapolnenie_kartinok();
        //read_file();

        for (int nomer_knopki = 0; nomer_knopki < KOLVO_KNOPOK; nomer_knopki++)
        {
            draw_button(knopki_dlya_menu[nomer_knopki]);
            btn_click (&knopki_dlya_menu[nomer_knopki], &pics[nomer_kartinki].kartinka);
            btn_navashdenie(&knopki_dlya_menu[nomer_knopki]);
        }

        if (txMouseButtons() & 1 && txMouseY() > VYSOTA_KNOPKI)
        {
            pics[nomer_kartinki].x = txMouseX();
            pics[nomer_kartinki].y = txMouseY();
            pics[nomer_kartinki].shirina = 30;
            pics[nomer_kartinki].vysota = 30;
            pics[nomer_kartinki].risovat = true;

            nomer_kartinki++;
            txSleep(1000);
        }

        for (nomer = 0; nomer < nomer_kartinki; nomer++);
        {
            if (pics[nomer].risovat)
            {
                txBitBlt (txDC(), pics[nomer].x, pics[nomer].y, pics[nomer].shirina, pics[nomer].vysota, pics[nomer].kartinka, 0, 0);
            }
        }

        txSleep (10);
        txEnd();
    }

    for (int nomer_knopki = 0; nomer_knopki < 100; nomer_knopki++)
    {
        txDeleteDC (knopki_dlya_menu[nomer_knopki].kartinka);
    }

    return 0;
}
