#pragma once

#include "Const.cpp"
#include "Mebel.cpp"

struct Knopka {
    int x;
    int y;
    const char* text;
    int risovatKartinku;
    string adress;
    HDC kartinka;
    const char* znak;
    bool najata;
    int kolvo_knopok;
};

Knopka knopki_dlya_menu[KOLVO_KNOPOK_MAX];

void draw_button(Knopka knop)
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

        for (int nom_kart = nomer_kartinki; nom_kart < COL_VO_KART; nom_kart++)
        {
            pics[nom_kart].kartinka = knop->kartinka;
            pics[nom_kart].znak = knop->znak;
        }

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
    KOLVO_KNOPOK = 0;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "kirpich",  -1, "Icons\\kirpich.bmp",  txLoadImage ("Icons\\kirpich.bmp"),  "x"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "kirpich2", -1, "Icons\\kirpich2.bmp", txLoadImage ("Icons\\kirpich2.bmp"), "l"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "kirpich3", -1, "Icons\\kirpich3.bmp", txLoadImage ("Icons\\kirpich3.bmp"), "c"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "kirpich4", -1, "Icons\\kirpich4.bmp", txLoadImage ("Icons\\kirpich4.bmp"), "v"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "kirpich5", -1, "Icons\\kirpich5.bmp", txLoadImage ("Icons\\kirpich5.bmp"), "i"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "kirpich6", -1, "Icons\\kirpich6.bmp", txLoadImage ("Icons\\kirpich6.bmp"), "d"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "kirpich7", -1, "Icons\\kirpich7.bmp", txLoadImage ("Icons\\kirpich7.bmp"), "s"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "kirpich8", -1, "Icons\\kirpich8.bmp", txLoadImage ("Icons\\kirpich8.bmp"), "t"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "kirpich9", -1, "Icons\\kirpich9.bmp", txLoadImage ("Icons\\kirpich9.bmp"), "w"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "kirpich10",-1, "Icons\\kirpich10.bmp",txLoadImage ("Icons\\kirpich10.bmp"), "w"};KOLVO_KNOPOK = KOLVO_KNOPOK + 1;


    SHIRINA_KNOPKI = txGetExtentX() / KOLVO_KNOPOK;
}
