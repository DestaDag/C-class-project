/**
 * @author DESTA DAGIM AYENEW
 * MATRCICOLA: 314650
*/
#include "gamelib.h"

//static void crea_cunicolo();
//static void stampa_caverna(/*parametro*/);
//static void chiudi_caverna();
//static void avanza();
//static void abbatti();
//static void aggira();
//static void esci();
//static void printftext(char* text);
/**
 * creates the two structures
 * @param t stores the users choice
 * @param b to tell which structure is
*/
static void ins_caverna(int t, bool b );
//static Cave_t* canc_caverna(Cave_t* cave, int t);//to delete the last node inserted
//static Cave_t* create(Cave_t* cave, int t);//to create a new node each time we want to insert a node to the list
//static Cave_t* append(Cave_t* cave, int t);//adds a node at the end of the linked list
//static void print(Cave_t* cave, int t);//to display the linked list
//static bool delete();
/**
 * outputs the linked list
 * @param first takes the linked list 
*/
static void print(Cave_t* first);
/**
 * to check if creating map is done
*/
static int control = 0;
/**
*pointers to the first and last node of the arvais linked list
*/
static Cave_t* head_arvais = NULL;
static Cave_t* last_arvais = NULL;
/**
*pointers to the first and last node of the hartornen linked list
*/
static Cave_t* head_hartornen = NULL;
static Cave_t* last_hartornen = NULL;
/**
*seed for generating random numbers
*/

#define r rand()%101
//! debug static Scava_t arvais;
//! debug static Scava_t hartornen;

/*
arvais.energia = 4;
hartornen.energia = 4;

arvais.raccolta = 0;
hartornen.raccolta = 0;
*/
/*
static bool delete(){
    int c;
    printf("vuoi eliminare l'ultima zona inserita?1- SI/2- NO\n");
    scanf("%d", &c);
    if(c == 1)
        return true;
    else return false;
}*/
/*
static void printftext(char* text){
    FILE* testo;
    int x;
    testo = fopen(text, "r");
    while(1){
        x = fgetc(testo);
        if(feof(testo)){
            break;
        }
    }
    printf("%c",x);
    fclose(testo);
}*/

void MainMenu(int *check){
    int choice = 0;
    
     //   FILE *txt;
      //  txt = fopen("test.txt", "r");
      //  fprintf("%s",txt);
        system("clear");
        printf(KNRM"--------MAIN-MENU--------\n");
        printf(KNRM"\t"KRED"1-"KNRM" CREA CUNICOLI\n\t"KRED"2-"KNRM" GIOCA\n\t"KRED"3-"KNRM" TERMINA GIOCO\n"KYEL"$ ");
        scanf("%d", &choice);
    

    switch (choice){
    case 1:{
            int counter = 0;
            do{
                printf(KNRM"\tfaccciamo i cunicoli per la famiglia Arvais\n\tdove vuoi inserire i cunicoli?\n"KYEL"$ ");
                int c;
                do{
                    scanf("%d", &c);
                }while(c != 1 && c != 2 && c != 3);
                bool f = true;
                ins_caverna(c, f);
                head_arvais->scelta[counter] = c;
                counter++;
            }while(counter <= 9);
            
            counter = 0;
            do{
                printf(KNRM"\tfaccciamo i cunicoli per la famiglia Hartornen\n\tdove vuoi inserire i cunicoli?\n"KYEL"$ ");
                int c;
                do{
                    scanf("%d", &c);
                }while(c != 1 && c != 2 && c != 3);
                
                
                bool g = false;
                ins_caverna(c, g);
                head_hartornen->scelta[counter] = c;
                counter++;
            }while(counter <= 9);
        }
        break;
    case 2:
            printf("arvais\n");
            print(last_arvais);
            printf("\n\nhartornen\n");
            print(last_hartornen);
            *check  = 1;
        break;
    case 3:
            printf("hello world");
          //  termina_gioco();
        break;
    }
    
}
/*
static void crea_cunicolo(){
            printf("hello, world\n");
            ins_caverna();

}*/

static void ins_caverna(int t, bool b){
    Cave_t* new = (Cave_t*)malloc(sizeof(Cave_t));
    if(r <= 50){
        new->melassa = 0; 
    }else if(r > 51 && r <= 70){
        new->melassa = 1;
    }else if(r > 71 && r <= 100){
        new->melassa = 2;
    }
    if(r <= 50){
        new->stato = 0;
    }else if(r > 51 && r <= 85){
        new->stato = 2;
    }else if(r > 86 && r <= 100){
        new->stato = 3;
    }
    new->avanti = NULL;
    new->sinistra = NULL;
    new->destra = NULL;
    if(b == true){
        if(t == 1){
            //new->avanti = NULL;
            if(head_arvais == NULL){
                head_arvais = new;
                last_arvais = new;
            }else{
                last_arvais->avanti = new;
                last_arvais = new;
            }
        }else if(t == 2){
            //new->sinistra = NULL;
            if(head_arvais == NULL){
                head_arvais = new;
                last_arvais = new;
            }else{
                last_arvais->sinistra = new;
                last_arvais = new;
            }
            }else if(t == 3){
                //new->destra = NULL;
                if(head_arvais == NULL){
                    head_arvais = new;
                    last_arvais = new;
                }else{
                    last_arvais->destra = new;
                    last_arvais = new;
                }
            }  
    }else if(b == false){
        if(t == 1){
            //new->avanti = NULL;
            if(head_hartornen == NULL){
                head_hartornen = new;
                last_hartornen = new;
        }else{
            last_hartornen->avanti = new;
            last_hartornen = new;
        }
        }else if(t == 2){
            //new->sinistra = NULL;
            if(head_hartornen == NULL){
                head_hartornen = new;
                last_hartornen = new;
            }else{
                last_hartornen->sinistra = new;
                last_hartornen = new;
            }
            }else if(t == 3){
                //new->destra = NULL;
                if(head_hartornen == NULL){
                    head_hartornen = new;
                    last_hartornen = new;
                }else{
                    last_hartornen->destra = new;
                    last_hartornen = new;
                }
            } 

    }
}
void print(Cave_t* first){
    if(first == NULL){
        printf(KNRM"No node in the list\n");
    }else{
        Cave_t* scan = first;
        int c = 0;
        do{
            printf(KNRM"quantita melassa %d\n", scan->melassa);

            switch(scan->scelta[c]){
                case 1: scan = scan->avanti;
                    break;
                case 2: scan = scan->sinistra;
                    break;
                case 3: scan = scan->destra;
                    break;    
            }
            c++;
        } while (c <= 9);
        
    } 
}
    
/*
static Cave_t* canc_caverna(Cave_t* cave, int t){
    if(cave == NULL)
        return NULL;

    Cave_t* cursor = cave;
    Cave_t* back = NULL;
    switch(t){
        case 1:
            while(cursor->avanti != NULL){
                back = cursor;
                cursor = cursor->avanti;
            }
            if(back != NULL)
                back->avanti = NULL;

            if(cursor == cave)
                cave = NULL;

            free(cursor);

         //   return cave;
            break;
        case 2:
            while(cursor->sinistra != NULL){
                back = cursor;
                cursor = cursor->sinistra;
            }
            if(back != NULL)
                back->avanti = NULL;

            if(cursor == cave)
                cave = NULL;

            free(cursor);

         //   return cave;
            break;
        case 3:
            while(cursor->destra != NULL){
                back = cursor;
                cursor = cursor->destra;
            }
            if(back != NULL)
                back->destra = NULL;

            if(cursor == cave)
                cave = NULL;

            free(cursor);

          //  return cave;
            break;
    }
    return cave;
}*/
/*
static Cave_t* append(Cave_t* cave, int t){
   if(cave == NULL)
        return NULL;
    Cave_t* cursor = cave;
    switch (t){
    case 1:
            while (cursor->avanti != NULL){
                cursor = cursor->avanti;
            }
        break;
    case 2:
            while(cursor->sinistra != NULL){
                cursor = cursor->sinistra;
            }
        break;
    case 3:
            while(cursor->destra != NULL){
                cursor = cursor->destra;
            }
        break;
    }
    Cave_t* new_node = create(NULL, t);
    switch (t){
    case 1:
            cursor->avanti = new_node;
        break;
    case 2:
            cursor->sinistra = new_node;
        break;
    case 3:
            cursor->destra = new_node;
        break;
    }
    return cave;
}*/
/*
static Cave_t* create(Cave_t* cave, int t){
    Cave_t* new_node = (Cave_t*)malloc(sizeof(Cave_t));
    if (new_node == NULL){
        printf("Error creating a node\n");
        exit(0);
    }
    if(t == 1){
        new_node->avanti = cave;
    }else if(t == 2){
        new_node->sinistra = cave;
    }else if(t == 3){
        new_node->destra = cave;
    }
    if((rand()%101) < 20){
        new_node->melassa = 2; 
    }else if((rand()%101) >= 20 && (rand()%101) < 50){
        new_node->melassa  = 1;
    }else if((rand()%101) > 50){
        new_node->melassa = 0;
    }



    return new_node;
}*/
/*
static void print(Cave_t* cave, int t){
    Cave_t* node = cave;
    while (node != NULL){
        switch (t){
        case 1:
                printf(" avanti quantià melassa %d\n", node->melassa);
                node = node->avanti;
            break;
        case 2:
                printf(" sinistra quantià melassa %d\n", node->melassa);
                node = node->sinistra;
            break;
        case 3:
                printf(" destra quantià melassa %d\n", node->melassa);
                node = node->destra;
            break;
        }
    }
    
}*/
