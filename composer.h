#ifndef COMPOSER_H_INCLUDED
#define COMPOSER_H_INCLUDED
#include <iostream>
#include "music.h"
using namespace std;

//ADT composer
typedef struct elemenComposer *adrCom;
struct composer{
    string nama;
    int tahunLahir;
    string genreUtama;
    string negaraAsal;
};

struct elemenComposer {
    composer infoCom;
    adrCom next;
    adrCom prev;
    adrMusic firstMusic;
};

struct listCom {
    adrCom first;
    adrCom last;
};

#endif
