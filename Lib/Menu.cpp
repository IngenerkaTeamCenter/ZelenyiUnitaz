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
    bool najata;
    Knopka2 knopki[15];
    int kolvo_knopok;
};

Knopka knopki_dlya_menu[KOLVO_KNOPOK];
Knopka2 vtor_knop[KOLVO_KNOPOK];

void zapolnenie_kartinok()
{
    HDC  TV = txLoadImage ("Icons\\tv.bmp");

    Mebel kartinci [8];
    kartinci[0] = {200, 200, 30, TV, 30};
    kartinci[1] = {200, 400, 30, TV, 30};
    kartinci[2] = {400, 200, 30, TV, 30};
    kartinci[3] = {300, 200, 30, TV, 30};
    kartinci[4] = {200, 300, 30, TV, 30};
    kartinci[5] = {300, 300, 30, TV, 30};
    kartinci[6] = {600, 200, 30, TV, 30};

    for (int nomer = 0; nomer < 7; nomer++)
    {
        txBitBlt(txDC(), kartinci[nomer].x, kartinci[nomer].y,
            kartinci[nomer].shirina, kartinci[nomer].vysota,
            kartinci[nomer].kartinka, 0, 0);
    }

    txDeleteDC (TV);
}

void draw_button(Knopka knop)
{
    txSetColour(RGB(0, 0, 0), 1);
    txSetFillColour(RGB( 195, 195, 195));
    txSelectFont("Times New Roman", 25);
    txRectangle(knop.x,knop.y,knop.x+SHIRINA_KNOPKI,knop.y+VYSOTA_KNOPKI);
    txDrawText(knop.x, knop.y + 40, knop.x + SHIRINA_KNOPKI, knop.y + VYSOTA_KNOPKI, knop.text, DT_CENTER);
}

void draw_button2(Knopka2 knop)
{
    txSetColour(RGB(0, 0, 0), 1);
    txSetFillColour(RGB( 195, 195, 195));
    txSelectFont("Times New Roman", 25);
    txRectangle(knop.x,knop.y,knop.x+SHIRINA_KNOPKI,knop.y+VYSOTA_KNOPKI);
    txDrawText(knop.x, knop.y + 40, knop.x + SHIRINA_KNOPKI, knop.y + VYSOTA_KNOPKI, knop.text, DT_CENTER);
}

void btn_click (Knopka* knop, HDC* kartinka)
{
    if (txMouseButtons() & 1
        && txMouseX() >= knop->x
        && txMouseX() <= knop->x + SHIRINA_KNOPKI
        && txMouseY() >= knop->y
        && txMouseY() <= knop->y + VYSOTA_KNOPKI)
    {
        knop->risovatKartinku = -knop->risovatKartinku;
        *kartinka = knop->kartinka;
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
    knopki_dlya_menu[0] = {0, 0, "vanna", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[1] = {SHIRINA_KNOPKI, 0, "zal", -1, txLoadImage ("Icons\\technology\\PC_1.bmp")};
    knopki_dlya_menu[2] = {2*SHIRINA_KNOPKI, 0, "kuxnua", -1, txLoadImage ("Icons\\table.bmp")};
    knopki_dlya_menu[3] = {3*SHIRINA_KNOPKI, 0, "spalnua", -1, txLoadImage ("Icons\\bad.bmp")};
    knopki_dlya_menu[4] = {4*SHIRINA_KNOPKI, 0, "spalnua", -1, txLoadImage ("Icons\\iPod_nano_6.bmp")};

    knopki_dlya_menu[0].knopki[0] = {0, 100, "vanna1", -1, txLoadImage ("Icons\\chair.bmp")};
    knopki_dlya_menu[0].knopki[1] = {0, 200, "vanna2", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[0].knopki[2] = {0, 300, "vanna3", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[0].knopki[3] = {0, 400, "vanna4", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[0].knopki[4] = {0, 500, "vanna5", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[0].kolvo_knopok = 5;

    knopki_dlya_menu[1].knopki[0] = {SHIRINA_KNOPKI,   200, "vanna", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[1].kolvo_knopok = 1;
    knopki_dlya_menu[2].knopki[0] = {2*SHIRINA_KNOPKI, 200, "vanna", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[3].knopki[0] = {3*SHIRINA_KNOPKI, 200, "vanna", -1, txLoadImage ("Icons\\tv.bmp")};
    knopki_dlya_menu[4].knopki[0] = {4*SHIRINA_KNOPKI, 200, "vanna", -1, txLoadImage ("Icons\\tv.bmp")};
}
