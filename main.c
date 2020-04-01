/*
    DESTA DAGIM AYENEW
    MATRICOLA: 314650
*/

#include "gamelib.h"

int main(){
    int check = 0;
    srand(time(NULL));
    do{
        do{
            check = MainMenu(check);
        } while (!check);
        clear;
        if(check == 2)
        break;
        else
            check = gioca();
        if(check == 3)
            break;

    } while (1);
    
}