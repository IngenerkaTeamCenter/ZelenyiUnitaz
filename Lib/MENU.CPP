#pragma once

#include "Const.cpp"
#include "Mebel.cpp"

struct Knopka2 {
    int x;
    int y;
    const char* text;
    int risovatKartinku;
    string adress;
    HDC kartinka;
    bool najata;
};


struct Knopka {
    int x;
    int y;
    const char* text;
    int risovatKartinku;
    string adress;
    HDC kartinka;
    const char* znak;
    bool najata;
    Knopka2 knopki[15];
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
    KOLVO_KNOPOK = 0;
        knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "bad",      -1, "Icons\\bad.bmp",  txLoadImage ("Icons\\bad.bmp"), "b"};   KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "bath",     -1, "Icons\\bath.bmp", txLoadImage ("Icons\\bath.bmp"), "l"};  KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "chair",    -1, "Icons\\chair.bmp", txLoadImage ("Icons\\chair.bmp"), "c"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "sofa",     -1, "Icons\\divan.bmp", txLoadImage ("Icons\\divan.bmp"), "v"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "oven",     -1, "Icons\\duxovka.bmp", txLoadImage ("Icons\\duxovka.bmp"), "i"};KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "cupboard", -1, "Icons\\schaf.bmp", txLoadImage ("Icons\\schaf.bmp"), "d"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "table",    -1, "Icons\\tabl.bmp", txLoadImage ("Icons\\table.bmp"), "s"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "TV",       -1, "Icons\\tv.bmp", txLoadImage ("Icons\\tv.bmp"), "t"};    KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "iPad",     -1, "Icons\\technology\\iPad.bmp", txLoadImage ("Icons\\technology\\iPad.bmp"), "w"};KOLVO_KNOPOK = KOLVO_KNOPOK + 1;
    knopki_dlya_menu[KOLVO_KNOPOK] = {KOLVO_KNOPOK * SHIRINA_KNOPKI, 0, "wall",     -1, "Icons\\wall.bmp", txLoadImage ("Icons\\wall.bmp"), "x"}; KOLVO_KNOPOK = KOLVO_KNOPOK + 1;

    SHIRINA_KNOPKI = txGetExtentX() / KOLVO_KNOPOK;
}
