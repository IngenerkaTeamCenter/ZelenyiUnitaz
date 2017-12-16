#include "Lib\\TXLib.h"
#include "Lib\\Const.cpp"
#include "Lib\\Files.cpp"
#include "Lib\\Mebel.cpp"
#include "Lib\\Menu.cpp"
#include "Lib\\Rounding.cpp"

int main()
{
    txCreateWindow(1090,720);

    int nomer_kartinki = 0;
    int nomer = 0;
    for (nomer = 0; nomer < COL_VO_KART; nomer++);
    {
        pics[nomer].risovat = false;
        pics[nomer].kartinka = NULL;
    }

    //zapolnenie_menu();
    nomer_kartinki = read_file(pics);

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(RGB(112, 146, 190));
        txClear();

        //Sterka
        if(txMouseButtons() &2)
        {
            for (int nomer = 0; nomer < nomer_kartinki; nomer++)
            {
                if (pics[nomer].x >= txMouseX() - 15 and
                    pics[nomer].x <= txMouseX() + pics[nomer].shirina - 15 and
                    pics[nomer].y >= txMouseY() - 15 and
                    pics[nomer].y <= txMouseY() + pics[nomer].vysota - 15)
                {
                    pics[nomer].risovat = false;
                    pics[nomer].kartinka = NULL;
                }
            }
        }

        //zapolnenie_kartinok();
        for (int nomer_knopki = 0; nomer_knopki < KOLVO_KNOPOK; nomer_knopki++)
        {
            draw_button(knopki_dlya_menu[nomer_knopki]);
            btn_click (&knopki_dlya_menu[nomer_knopki], nomer_kartinki);
            btn_navashdenie(&knopki_dlya_menu[nomer_knopki]);
        }

        if (txMouseY() > VYSOTA_KNOPKI && nomer_kartinki < COL_VO_KART && !pics[nomer_kartinki].risovat &&
            txMouseButtons() &1 && pics[nomer_kartinki].kartinka != NULL)
        {
            HBITMAP hbm=(HBITMAP)Win32::GetCurrentObject(pics[nomer_kartinki].kartinka, OBJ_BITMAP);
            BITMAP bm;
            Win32::GetObject(hbm,sizeof(bm), (LPVOID)&bm);

            pics[nomer_kartinki].shirina = bm.bmWidth;
            pics[nomer_kartinki].vysota = bm.bmHeight;

            bool many = false;

            for (int p = 0; p < nomer_kartinki; p++)
            {
                if (pics[nomer_kartinki].x == pics[p].x &&
                     abs(pics[nomer_kartinki].y - pics[p].y) < pics[p].vysota)
                {
                    many = true;
                }
            }

            if (!many)
            {
                pics [nomer_kartinki].risovat = true;
            }

            roundCoords (&pics[nomer_kartinki], txMouseX(), txMouseY());
        }

        for (nomer = 0; nomer < COL_VO_KART; nomer++)
        {
            if (pics[nomer].risovat == true && pics[nomer].kartinka != NULL)
            {
                txBitBlt (txDC(), pics[nomer].x, pics[nomer].y, pics[nomer].shirina, pics[nomer].vysota, pics[nomer].kartinka, 0, 0);
                nomer_kartinki = nomer + 1;
            }
        }

        txSleep (10);
        txEnd();
    }

    //Save to file
    saveMassive(pics, nomer_kartinki);

    for (int nomer_knopki = 0; nomer_knopki < KOLVO_KNOPOK; nomer_knopki++)
    {
        txDeleteDC (knopki_dlya_menu[nomer_knopki].kartinka);
    }

    return 0;
}
