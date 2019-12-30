#include "gamelib.h"

int main(){
    int check = 0;
    srand(time(NULL));
    do{
        do{
            MainMenu(&check);
        } while (!check);
      // gioca();
        
    } while (1);
    
}