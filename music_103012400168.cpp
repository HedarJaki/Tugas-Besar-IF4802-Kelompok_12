#include "header.h"
#include <iostream>

using namespace std;

adrMusic createMusic(music x){
    adrMusic p = new elemenMusic;
    p->infoMusic = x;
    p->next = nullptr;
    return p;
}

void insertFirstMusic(adrCom p, adrMusic q){
    q->next = p->firstMusic;
    p->firstMusic = q;
}

void insertLastMusic(adrCom p, adrMusic q){
    adrMusic x = p->firstMusic;
    while (x->next != nullptr){
        x = x->next;
    }
    x->next = q;
}

void insertAfterMusic(adrCom p, adrMusic prec, adrMusic q){
    q->next = prec->next;
    prec->next = q;
}

void insertByTitle(adrCom p, adrMusic q){
    if (p->firstMusic != nullptr){
        if (q->infoMusic.judul < p->firstMusic->infoMusic.judul){
            insertFirstMusic(p, q);
        }else {
            adrMusic temp = p->firstMusic;
            while (temp != nullptr && q->infoMusic.judul > temp->infoMusic.judul){
                temp = temp->next;
            }
            
            if (temp->next == nullptr){
                temp->next = q;
            }else{
                insertAfterMusic(p, temp, q);
            }
        }
    }else{
        p->firstMusic = q;
    }
}

int countMusic(adrCom p){
    adrMusic temp = p->firstMusic;
    int count = 0;
    while (temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}