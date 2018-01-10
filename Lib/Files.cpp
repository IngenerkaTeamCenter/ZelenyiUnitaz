#pragma once

#include "TXLib.h"
#include "menu.cpp"
#include "Mebel.cpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int read_map_file(Mebel* KART1)
{
    ifstream map_file;
    string stroka_s_kartinkoi = "1";
    map_file.open("Files\\map.txt");
    int nomer = 0;

    while (map_file.good() && strlen(stroka_s_kartinkoi.c_str()) > 0) {

        getline (map_file, stroka_s_kartinkoi);

        if (strlen(stroka_s_kartinkoi.c_str()) > 0)
        {
            int pos_adresa = stroka_s_kartinkoi.find(',');
            string adress = stroka_s_kartinkoi.substr(0, pos_adresa);

            stroka_s_kartinkoi = stroka_s_kartinkoi.substr(pos_adresa + 2);
            int pos_x = stroka_s_kartinkoi.find(',');
            string x = stroka_s_kartinkoi.substr(0, pos_x);

            stroka_s_kartinkoi = stroka_s_kartinkoi.substr(pos_x + 2);
            string y = stroka_s_kartinkoi;

            HDC pic = txLoadImage(adress.c_str());
            HBITMAP hbm=(HBITMAP)Win32::GetCurrentObject(pic, OBJ_BITMAP);
            BITMAP bm;
            Win32::GetObject(hbm,sizeof(bm), (LPVOID)&bm);

            //txBitBlt (txDC(), atoi(x.c_str()), atoi(y.c_str()), bm.bmWidth, bm.bmHeight, pic, 0, 0);
            KART1[nomer] = {atoi(x.c_str()), atoi(y.c_str()), bm.bmWidth, pic, "1", bm.bmHeight, true, adress.c_str()};

            nomer++;
        }
    }

    map_file.close();

    return nomer;
}

void save_map_massive(Mebel* KART1, int nomer_kartinki)
{
    ofstream fout_save;
    fout_save.open("Files\\savefile.txt");

    for (int i = 0; i< nomer_kartinki; i++)
    {
        if (KART1[i].risovat)
        {
            fout_save << /*KART1[i].adress << "," <<*/ KART1[i].x << "," << KART1[i].y << endl;
        }
    }
    fout_save.close();
}
