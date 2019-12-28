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
 * @param fisrt takes the head node of the linked list
 * @param last takes the last node of the linked list
 * @param t stores the users choice
*/
static void ins_caverna(Cave_t* first, Cave_t* last, int t);
//static Cave_t* canc_caverna(Cave_t* cave, int t);//to delete the last node inserted
//static Cave_t* create(Cave_t* cave, int t);//to create a new node each time we want to insert a node to the list
//static Cave_t* append(Cave_t* cave, int t);//adds a node at the end of the linked list
//static void print(Cave_t* cave, int t);//to display the linked list
//static bool delete();
/**
 * outputs the linked list
 * @param cave takes the linked list 
*/
static void print(Cave_t* cave);
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
        printf("--------MAIN-MENU--------\n");
        printf("\t1- CREA CUNICOLI\n\t2- GIOCA\n\t3- TERMINA GIOCO\n");
        scanf("%d", &choice);
    

    switch (choice){
    case 1:{
            int counter = 0;
            do{
                printf("faccciamo i cunicoli per la famiglia Arvais\ndove vuoi inserire i cunicoli?\n");
                int c;
                scanf("%d", &c);
                head_arvais->scelta[counter] = c; 
                ins_caverna(head_arvais, last_arvais, c);
                counter++;
            }while(counter <= 9);
            
            counter = 0;
            do{
                printf("faccciamo i cunicoli per la famiglia Hartornen\ndove vuoi inserire i cunicoli?\n");
                int c;
                scanf("%d", &c);
                head_hartornen->scelta[counter] = c; 
                ins_caverna(head_hartornen, last_hartornen, c);
                counter++;
            }while(counter <= 9);
        }
        break;
    case 2:
            printf("arvais\n");
            print(head_arvais);
            printf("\n\nhartornen\n");
            print(head_hartornen);
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

static void ins_caverna(Cave_t* first, Cave_t* last, int t){
    Cave_t* new = (Cave_t*)malloc(sizeof(Cave_t));
        if(t == 1){
        new->avanti = NULL;
        if(first == NULL){
            first = (Cave_t*)malloc(sizeof(Cave_t));
            last = (Cave_t*)malloc(sizeof(Cave_t));
            first  = new;
            last = new;
        }else{
            last->avanti = new;
            last = new;
        }
    }else if(t == 2){
        new->sinistra = NULL;
        if(first == NULL){
            first = (Cave_t*)malloc(sizeof(Cave_t));
            last = (Cave_t*)malloc(sizeof(Cave_t));
            first = new;
            last = new;
        }else{
            last->sinistra = new;
            last = new;
        }
    }else if(t == 3){
        new->destra = NULL;
        if(first == NULL){
            first = (Cave_t*)malloc(sizeof(Cave_t));
            last = (Cave_t*)malloc(sizeof(Cave_t));
            first = new;
            last = new;
        }else{
            last->destra = new;
            last = new;
        }
    }
    control = 1;
}

void print(Cave_t* cave){
    Cave_t* current_node = cave;
 
        for(int i = 0; i < 10; i++){
            printf("quantita melassa %d %d\n", current_node->melassa, i);
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
