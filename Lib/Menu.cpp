#pragma once

#include "Const.cpp"
#include "Mebel.cpp"

struct Knopka2 {
    int x;
    int y;
    const char* text;
    int risovatKartinku;
    HDC kartinka;
    bool najata;
};


struct Knopka {
    int x;
    int y;
    const char* text;
    int risovatKartinku;
    HDC kartinka;
    const char* znak;
    bool najata;
    Knopka2 knopki[15];
    int kolvo_knopok;
};

Knopka knopki_dlya_menu[KOLVO_KNOPOK];
Knopka2 vtor_knop[KOLVO_KNOPOK];

void zapolnenie_kartinok()
{


    for (int nomer = 0; nomer < 7; nomer++)
    {
        txBitBlt(txDC(), pics[nomer].x, pics[nomer].y,
            pics[nomer].shirina, pics[nomer].vysota,
            pics[nomer].kartinka, 0, 0);
    }


}

void draw_button(Knopka knop)
{
    txSetColour(RGB(0, 0, 0), 1);
    txSetFillColour(RGB( 195, 195, 195));
    txSelectFont("Times New Roman", 25);
    txRectangle(knop.x,knop.y,knop.x+SHIRINA_KNOPKI,knop.y+VYSOTA_KNOPKI);
    txDrawText(knop.x, knop.y + VYSOTA_KNOPKI / 3, knop.x + SHIRINA_KNOPKI, knop.y + VYSOTA_KNOPKI, knop.text, DT_CENTER);
}

void draw_button2(Knopka2 knop)
{
    txSetColour(RGB(0, 0, 0), 1);
    txSetFillColour(RGB( 195, 195, 195));
    txSelectFont("Times New Roman", 25);
    txRectangle(knop.x,knop.y,knop.x+SHIRINA_KNOPKI,knop.y+VYSOTA_KNOPKI);
    txDrawText(knop.x, knop.y + VYSOTA_KNOPKI / 3, knop.x + SHIRINA_KNOPKI, knop.y + VYSOTA_KNOPKI, knop.text, DT_CENTER);
}

void btn_click (Knopka* knop, int nomer_kartinki)
{
    if (txMouseButtons() & 1
        && txMouseX() >= knop->x
        && txMouseX() <= knop->x + SHIRINA_KNOPKI
        && txMouseY() >= knop->y
        && txMouseY() <= knop->y + VYSOTA_KNOPKI)
    {
        knop->risovatKartinku = -knop->risovatKartinku;
        //meb->kartinka = knop->kartinka;
        for (int nom_kart = nomer_kartinki; nom_kart < COL_VO_KART; nom_kart++)
             {
                pics[nom_kart].kartinka = knop->kartinka;
            pics[nom_kart].znak = knop->znak;
            }
//        meb->risovat = false;
        txSleep(100);
    }
}

void btn_navashdenie (Knopka* knop)
{
    if (txMouseX() >= knop->x
        && txMouseX() <= knop->x + SHIRINA_KNOPKI
        && txMouseY() >= knop->y
        && txMouseY() <= knop->y + VYSOTA_KNOPKI)
    {
        knop->najata = true;
    }

    if (knop->najata)
    {
        txRectangle(knop->x, knop->y + VYSOTA_KNOPKI, knop->x + SHIRINA_KNOPKI, knop->y + VYSOTA_KNOPKI + VYSOTA_MENU);

        for (int i = 0; i < knop->kolvo_knopok; i++)
        {
            draw_button2(knop->knopki[i]);
        }
    }
    if (txMouseX() < knop->x
    || txMouseX() > knop->x + SHIRINA_KNOPKI
    || txMouseY() > knop->y + VYSOTA_KNOPKI + VYSOTA_MENU)
    {
        knop->najata = false;
    }
}

void zapolnenie_menu()
{
    knopki_dlya_menu[0] = {0, 0, "bad", -1, txLoadImage ("Icons\\bad.bmp"), "b"};
    knopki_dlya_menu[1] = {SHIRINA_KNOPKI, 0, "batch", -1, txLoadImage ("Icons\\bath.bmp"), "q"};
    knopki_dlya_menu[2] = {2*SHIRINA_KNOPKI, 0, "chair", -1, txLoadImage ("Icons\\chair.bmp"), "c"};
    knopki_dlya_menu[3] = {3*SHIRINA_KNOPKI, 0, "sofa", -1, txLoadImage ("Icons\\divan.bmp"), "b"};
    knopki_dlya_menu[4] = {4*SHIRINA_KNOPKI, 0, "oven", -1, txLoadImage ("Icons\\duxovka.bmp"), "i"};
    knopki_dlya_menu[5] = {5*SHIRINA_KNOPKI, 0, "cupboard", -1, txLoadImage ("Icons\\schaf.bmp"), "d"};
    knopki_dlya_menu[6] = {6*SHIRINA_KNOPKI, 0, "table", -1, txLoadImage ("Icons\\table.bmp"), "s"};
    knopki_dlya_menu[7] = {7*SHIRINA_KNOPKI, 0, "TV", -1, txLoadImage ("Icons\\tv.bmp"), "q"};
    knopki_dlya_menu[8] = {8*SHIRINA_KNOPKI, 0, "iPad", -1, txLoadImage ("Icons\\technology\\iPad.bmp"), "w"};
    knopki_dlya_menu[9] = {9*SHIRINA_KNOPKI, 0, "iPhone_x", -1, txLoadImage ("Icons\\technology\\iPhone_x.bmp"), "x"};



    int x = 0;
    int y = 0;

    int nomer_knopki = 0;
    knopki_dlya_menu[0].knopki[nomer_knopki++] = {x, y += VYSOTA_KNOPKI, "chair", -1, txLoadImage ("Icons\\chair.bmp")};
    knopki_dlya_menu[0].knopki[nomer_knopki++] = {x, y += VYSOTA_KNOPKI, "tv", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[0].knopki[nomer_knopki++] = {x, y += VYSOTA_KNOPKI, "tv", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[0].knopki[nomer_knopki++] = {x, y += VYSOTA_KNOPKI, "tv", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[0].knopki[nomer_knopki++] = {x, y += VYSOTA_KNOPKI, "tv", -1, txLoadImage ("Icons\\tv.bmp")};

    knopki_dlya_menu[0].kolvo_knopok = 5;

    y = 0;
    x += SHIRINA_KNOPKI;
    nomer_knopki = 0;
    knopki_dlya_menu[1].knopki[nomer_knopki++] = {x, y += VYSOTA_KNOPKI, "tv", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[1].kolvo_knopok = 1;
    knopki_dlya_menu[2].knopki[0] = {2*SHIRINA_KNOPKI, 200, "tv", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[2].kolvo_knopok = 0;
    knopki_dlya_menu[3].knopki[0] = {3*SHIRINA_KNOPKI, 200, "tv", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[3].kolvo_knopok = 0;
    knopki_dlya_menu[4].knopki[0] = {4*SHIRINA_KNOPKI, 200, "tv", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[4].kolvo_knopok = 0;
}
