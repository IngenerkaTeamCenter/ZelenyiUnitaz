#pragma once

#include "TXLib.h"
#include "menu.cpp"
#include "Mebel.cpp"
#include "Rounding.cpp"
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

            HDC pic = NULL;
            //Иногда надо копировать

        //    int nomer_kartinki = 0; nomer_kartinki < vsego_kartinok; nomer_kartinki++
            for ( int nomer_kartinki = 0; nomer_kartinki < nomer; nomer_kartinki++)
            {
                if (strcmp(KART1[nomer_kartinki].adress.c_str(), adress.c_str()) == 0)
                {
                    pic = KART1[nomer_kartinki].kartinka;
                }
            }
            if (pic == NULL)
            {
                pic = txLoadImage(adress.c_str());
            }
            HBITMAP hbm=(HBITMAP)Win32::GetCurrentObject(pic, OBJ_BITMAP);
            BITMAP bm;
            Win32::GetObject(hbm,sizeof(bm), (LPVOID)&bm);


            char* adress_as_char = new char[200];
            strcpy(adress_as_char, adress.c_str());

            KART1[nomer] = {atoi(x.c_str()), atoi(y.c_str()), bm.bmWidth, pic, "1", bm.bmHeight, true, adress_as_char};
            roundCoords (&KART1[nomer], KART1[nomer].x, KART1[nomer].y);

            nomer++;
        }
    }

    map_file.close();


    return nomer;
}

void save_map_massive(Mebel* massiv_mebeli, int vsego_kartinok)
{
    ofstream fout_save;
    fout_save.open("Files\\savefile.txt");

    for (int nomer_kartinki = 0; nomer_kartinki < vsego_kartinok; nomer_kartinki++)
    {
        if (massiv_mebeli[nomer_kartinki].risovat)
        {
            for (int nomer_knopki = 0; nomer_knopki < KOLVO_KNOPOK; nomer_knopki++)
            {
                if (strcmp( massiv_mebeli[nomer_kartinki].znak,
                            knopki_dlya_menu[nomer_knopki].znak) == 0)
                {
                    massiv_mebeli[nomer_kartinki].adress = knopki_dlya_menu[nomer_knopki].adress;
                }
            }

            fout_save <<    massiv_mebeli[nomer_kartinki].adress << ", " <<
                            massiv_mebeli[nomer_kartinki].x << ", " <<
                            massiv_mebeli[nomer_kartinki].y << endl;
        }
    }
    fout_save.close();
}
