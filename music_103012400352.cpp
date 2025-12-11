#include "header.h"
#include <iostream>

using namespace std;

void deleteFirstMusic(adrCom c, adrMusic &m){
    if (c->firstMusic == nullptr){
        cout << "tidak ada data yang dihapus";
    }else{
        m = c->firstMusic;
        c->firstMusic = m->next;
        m->next = nullptr;
    }
}

void deleteLastMusic(adrCom c, adrMusic &m){
    if (c->firstMusic == nullptr){
        cout << "tidak ada data yang dihapus";
    }
    else if (c->firstMusic->next == nullptr){
        m = c->firstMusic;
        c->firstMusic = nullptr;
    }
    else{
        adrMusic q = c->firstMusic;
        while (q->next->next != nullptr){
            q = q->next;
        }
        m = q->next;
        q->next = nullptr;
    }
}

void deleteAfterMusic(adrCom c, adrMusic prec, adrMusic &m){
     if (c->firstMusic == nullptr){
        cout << "tidak ada data yang dihapus";
    }else{
        m = prec->next;
        prec->next = m->next;
        m->next = nullptr; 
    }
}

adrMusic findElemenMusic(adrCom c, string judul){
    adrMusic p = c->firstMusic;
    while (p != nullptr){
        if (p->infoMusic.judul == judul){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void viewMusicByGenre(adrCom c, string genre){
    if (c->firstMusic == nullptr){
        cout << "Musik tidak ada." << endl;
    }

    adrMusic p = c->firstMusic;
    bool found = false;
    while (p != nullptr){
        if (p->infoMusic.genre == genre){
            cout << "Musik ditemukan." << endl;
            cout << "Judul : " << p->infoMusic.judul << endl;
            cout << "Penyanyi: " << p->infoMusic.penyanyi << endl;
            cout << "Tahun: " << p->infoMusic.tahunTerbit << endl;
            found = true;
        }
        p = p->next;
    }

    if (!found){
        cout << "Tidak ada music dengan genre " << genre << "." << endl;
    }
}

void deleteMusicByJudul(adrCom c, string judul){
    adrMusic m = findElemenMusic(c, judul);
    if (m != nullptr){
        if (m == c->firstMusic){
            deleteFirstMusic(c, m);
            delete m;
        } else {
            adrMusic q = c->firstMusic;
            while (q->next != m){
                q = q->next;
            }
            if (m->next == nullptr){ 
                deleteLastMusic(c, m);
                delete m;
            } else { 
                deleteAfterMusic(c, q, m);
                delete m;
            }
        }
        m = nullptr;
    }else{
        cout << "Music dengan judul '" << judul << "' tidak ditemukan." << endl;
    }
}

int countMusicByGenre(adrCom c, string genre){
    int total = 0;
    adrMusic p = c->firstMusic;

    while (p != nullptr){
        if (p->infoMusic.genre == genre){
            total++;
        }
        p = p->next;
    }
    return total;
}