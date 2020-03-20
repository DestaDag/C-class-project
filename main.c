/*
    DESTA DAGIM AYENEW
    MATRICOLA: 314650
    v: 0.1.0
*/

#include "gamelib.h"

int main(){
    int check = 0;
    srand(time(NULL));
    do{
        do{
            MainMenu(check);
        } while (!check);
        clear;
        gioca();
        
    } while (1);
    
}