#include "Lib\\TXLib.h"
#include "Lib\\Const.cpp"
#include "Lib\\Files.cpp"
#include "Lib\\Mebel.cpp"
#include "Lib\\Menu.cpp"

int main()
{
    txCreateWindow(1000,720);

    Mebel kartinki [8];
    kartinki[0] = {-200,200,30,NULL,30};

    zapolnenie_menu();

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(RGB(112, 146, 190));
        txClear();

        //zapolnenie_kartinok();
        read_file();

        for (int nomer_knopki = 0; nomer_knopki < KOLVO_KNOPOK; nomer_knopki++)
        {
            draw_button(knopki_dlya_menu[nomer_knopki]);
            btn_click (&knopki_dlya_menu[nomer_knopki], &kartinki[0].kartinka);
            btn_navashdenie(&knopki_dlya_menu[nomer_knopki]);
        }

        if (txMouseButtons() & 1 && txMouseY() > VYSOTA_KNOPKI)
        {
            kartinki[0].x = txMouseX();
            kartinki[0].y = txMouseY();
            kartinki[0].shirina = 30;
            kartinki[0].vysota = 30;
        }

        if (kartinki[0].kartinka != NULL)
        {
            txBitBlt (txDC(), kartinki[0].x, kartinki[0].y, kartinki[0].shirina, kartinki[0].vysota, kartinki[0].kartinka, 0, 0);
        }

        txSleep (10);
        txEnd();
    }

    for (int nomer_knopki = 0; nomer_knopki < KOLVO_KNOPOK; nomer_knopki++)
    {
        txDeleteDC (knopki_dlya_menu[nomer_knopki].kartinka);
    }

    return 0;
}
