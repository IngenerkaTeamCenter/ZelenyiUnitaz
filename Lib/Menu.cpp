
struct Knopka {
    int x;
    int y;
    const char* text;
    int risovatKartinku;
    HDC kartinka;
};

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
    txRectangle(knop.x,knop.y,knop.x+200,knop.y+100);
    txDrawText(knop.x, knop.y + 40, knop.x + 200, knop.y + 100, knop.text, DT_CENTER);
}
