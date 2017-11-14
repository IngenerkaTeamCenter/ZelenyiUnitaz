#include "Const.cpp"


struct Knopka {
    int x;
    int y;
    const char* text;
    int risovatKartinku;
    HDC kartinka;
    bool najata;
};

struct Knopka2 {
    int x;
    int y;
    const char* text;
    int risovatKartinku;
    HDC kartinka;
    bool najata;
};

Knopka knopki_dlya_menu[KOLVO_KNOPOK];

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
    txRectangle(knop.x,knop.y,knop.x+SHIRINA_KNOPKI,knop.y+VYSOTA_KNOPKI);
    txDrawText(knop.x, knop.y + 40, knop.x + SHIRINA_KNOPKI, knop.y + VYSOTA_KNOPKI, knop.text, DT_CENTER);
}

void btn_click (Knopka* knop)
{
    if (txMouseButtons() & 1
        && txMouseX() >= knop->x
        && txMouseX() <= knop->x + SHIRINA_KNOPKI
        && txMouseY() >= knop->y
        && txMouseY() <= knop->y + VYSOTA_KNOPKI)
    {
        knop->risovatKartinku = -knop->risovatKartinku;
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
        txRectangle(knop->x, knop->y + VYSOTA_KNOPKI, knop->x + SHIRINA_KNOPKI, knop->y + VYSOTA_KNOPKI + VYSOTA_MENU);

    if (txMouseX() < knop->x
    || txMouseX() > knop->x + SHIRINA_KNOPKI
    || txMouseY() > knop->y + VYSOTA_KNOPKI + VYSOTA_MENU)
    {
        knop->najata = false;
    }
}

void zap()
{
    knopki_dlya_menu[0] = {0, 0, "vanna", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[1] = {SHIRINA_KNOPKI, 0, "zal", -1, txLoadImage ("Icons\\technology\\PC_1.bmp")};
    knopki_dlya_menu[2] = {2*SHIRINA_KNOPKI, 0, "kuxnua", -1, txLoadImage ("Icons\\table.bmp")};
    knopki_dlya_menu[3] = {3*SHIRINA_KNOPKI, 0, "spalnua", -1, txLoadImage ("Icons\\bad.bmp")};
    knopki_dlya_menu[4] = {4*SHIRINA_KNOPKI, 0, "spalnua", -1, txLoadImage ("Icons\\iPod_nano_6.bmp")};
}

