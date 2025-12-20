#include <iostream>
#include "header.h"
#include "tampilan.cpp"
using namespace std;

int main(){
    listCom L;
    createListCom(L);
    
    createDataInput(L);
    int mainChoice = -1;

    while (mainChoice != 0) {
        cout << "\n========= MAIN MENU =========\n";
        cout << "1. Login as Admin\n";
        cout << "2. Login as User\n";
        cout << "0. Exit\n";
        cout << "=============================\n";
        cout << "Pilih menu: ";
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            adminMenu(L);
            break;
        case 2:
            userMenu(L);
            break;
        case 0:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}