#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;
#include "music.h"
#include "composer.h"

void createListCom(listCom &L);
adrCom createComposer(string nama, int tahun, string genre, string negara);
void insertFirstCom(listCom &L, adrCom p);
void insertLastCom(listCom &L, adrCom p);
void insertAfterCom(listCom &L, adrCom prec, adrCom p);
void viewComNegara(listCom L, string negara);
void deleteFirstCom(listCom &L, adrCom &p);
void deleteLastCom(listCom &L, adrCom &p);
void deleteAfterCom(listCom &L, adrCom q, adrCom &p);
adrCom findComp(listCom L, string namaComp);
void deleteComp(listCom &L, string namaComp);
void viewCompGenre(listCom L, string genre);
adrMusic createMusic(music x);
void insertFirstMusic(adrCom p, adrMusic q);
void insertLastMsuic(adrCom p, adrMusic q);
void insertAfterMusic(adrCom p, adrMusic prec, adrMusic q);
void insertByTitle(adrCom p, adrMusic q);
int countMusic(adrCom p);
void deleteFirstMusic(adrCom c, adrMusic &m);
void deleteLastMusic(adrCom c, adrMusic &m);
void deleteAfterMusic(adrCom c, adrMusic prec, adrMusic &m);
adrMusic findElemenMusic(adrCom c, string judul);
void viewMusicByGenre(adrCom c, string genre);
void deleteMusicByJudul(adrCom c, string judul);
int countMusic(adrCom p);
adrCom mostMadeMusic(listCom L);
void viewList(listCom L);
#endif