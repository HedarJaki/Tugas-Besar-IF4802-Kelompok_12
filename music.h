#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include <iostream>
using namespace std;
//ADT music
typedef struct elemenMusic* adrMusic;
struct music{
    string judul;
    string penyanyi;
    string genre;
    int tahunTerbit;
};

struct elemenMusic {
    music infoMusic;
    adrMusic next;
};

#endif
