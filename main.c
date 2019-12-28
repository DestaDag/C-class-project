#include "gamelib.h"

int main(){
    int check = 0;

    do{
        do{
            MainMenu(&check);
        } while (!check);
      // gioca();
        
    } while (1);
    
}