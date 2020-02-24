/*
    DESTA DAGIM AYENEW
    MATRICOLA: 314650
*/
#include "gamelib.h"

//function for creating, deleting and printing linked list
static void crea_cunicolo();

//outputs the linked list
static void stampa_cunicolo(Cave_t** first);
//function for exiting from the map creation menu
static int chiudi_cunicolo();
//static void avanza();
//static void abbatti();
//static void aggira();
//static void esci();
//creates the two structures
static void ins_cunicolo(int t, Cave_t** head, Cave_t** last);
//deletes the last node
static void  canc_caverna(int t, Cave_t** first, Cave_t** last);
// to check if creating map is done
static int control = 0;
//pointers to the first and last node of the arvais linked list
static Cave_t* head_arvais = NULL;
static Cave_t* last_arvais = NULL;
//pointers to the first and last node of the hartornen linked list
static Cave_t* head_hartornen = NULL;
static Cave_t* last_hartornen = NULL;
//delays the next text printed
 static void delay(int number_of_seconds);
//seed for generating random numbers
#define r rand()%101
//! debug static Scava_t arvais;
//! debug static Scava_t hartornen;

/*
arvais.energia = 4;
hartornen.energia = 4;

arvais.raccolta = 0;
hartornen.raccolta = 0;
*/

static void delay(int number_of_seconds){
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while(clock() < start_time + milli_seconds);
}

void MainMenu(int *check){
    int choice = 0;
    clear;
    printf(KYEL"\n\nprima di iniziare regolare le dimensioni dello schermo\n");
    delay(3);
    clear;
    printf(KYEL"\n\nloading...\n\n");
    delay(3);
    clear;
    printf(KRED"\t******************\n");
    printf(KRED"\t*                *\n");
    printf(KRED"\t*BENVENUTO A DUNE*\n");
    printf(KRED"\t*                *\n");
    printf(KRED"\t******************\n");
    delay(3);
    clear;
    printf(KMAG"\n\n--------MAIN-MENU--------\n");
    printf(KNRM"\t"KRED"1-"KBLU" CREA CUNICOLI\n\t"KRED"2-"KBLU" GIOCA\n\t"KRED"3-"KBLU" TERMINA GIOCO\n"KYEL"$ ");
    scanf("%d", &choice);
    
    switch (choice){
    case 1:
            crea_cunicolo();
        break;
    case 2:
            printf("gioca\n");
        break;
    case 3:
            printf("termina gioco");
          //  termina_gioco();
        break;
    }
    
}

static void crea_cunicolo(){
    int choice = 0;
    int c;
    //bool b = true;
    int counter_a = 1;
    int counter_h = 1;
    do{
        clear;
        printf(KMAG"\n\n--------MAP-CREATION-MENU-------\n");
        printf(KNRM"\t"KRED"1-"KBLU" INSERISCI CUNICOLO\n\t"KRED"2-"KBLU" STAMPA CUNICOLO\n\t"KRED"3-"KBLU" ELIMINA CUNICOLO\n\t"KRED"4-"KBLU" RITORNA AL MAIN MENU\n"KYEL"$ ");
        scanf("%d", &choice);
        switch(choice){
        case 1: 
            clear;
            printf(KGRN"\n\nFaccciamo i cunicoli per la famiglia Arvais:\ndove vuoi inserire il %d cunicolo?\n", counter_a);
            ++counter_a;
            printf(KNRM"\t"KRED"1-"KBLU" AVANTI\n\t"KRED"2-"KBLU" SINISTRA\n\t"KRED"3-"KBLU" DESTRA\n");                
            printf(KYEL"$ ");
                
            do{            
                scanf("%d", &c);
                if(c != 1 && c != 2 && c != 3){
                    if(r <= 50){
                        printf(KRED"Input sbagliato, riprova\n"KYEL"$ ");
                    }else{
                        printf(KRED"Gli input devono essere '1' o '2' o '3'\n"KYEL"$ ");
                    }
                }
            }while(c != 1 && c != 2 && c != 3);
            //b = true;
            ins_cunicolo(c, &head_arvais, &last_arvais);
            //head_arvais->scelta[counter] = c;
            clear;                
            printf(KGRN"\n\nFaccciamo i cunicoli per la famiglia Hartornen:\ndove vuoi inserire il %d cunicolo?\n", counter_h);
            ++counter_h;
            printf(KNRM"\t"KRED"1-"KBLU" AVANTI\n\t"KRED"2-"KBLU" SINISTRA\n\t"KRED"3-"KBLU" DESTRA\n"); 
            printf(KYEL"$ ");
            do{
                scanf("%d", &c);
                if(c != 1 && c != 2 && c != 3){
                    if(r <= 50){
                        printf(KRED"Input sbagliato, riprova\n"KYEL"$ "); 
                    }else{
                        printf(KRED"Gli input devono essere '1' o '2' o '3', riprova\n"KYEL"$ ");
                    }
                }
            }while(c != 1 && c != 2 && c != 3);
            //b = false;
            ins_cunicolo(c, &head_hartornen, &last_hartornen);
            //head_hartornen->scelta[counter] = c;
            if(counter_h == 10 && counter_a == 10){
                control = 1;
                printf(KGRN"Sono state create 10 cunicoli per entrambe le famiglie\n");
            }       
        break;
        case 2:
            clear;
            printf(KGRN"Ecco i cunicoli creati per la famiglia arvais con le loro rispettive quantita di melassa\n");
            stampa_cunicolo(&head_arvais);
            delay(1);
            printf(KGRN"Ecco i cunicoli creati per la famiglia hartornen con le loro rispettive quantita di melassa\n");
            stampa_cunicolo(&head_hartornen);
            delay(5);
            
            //*check  = 1;
        break;
        case 3:
            clear;
            int x;
            printf(KGRN"Quale cunicolo vuoi eliminare?\n");
            printf("\t1---CUNICOLO FAMIGLIA ARVAIS\n\t2---CUNICOLO FAMIGLIA ARVAIS\n"KYEL"$");
            do{
                scanf("%d", &x);
                if(x != 1 && x != 2){
                    if(r <= 50){
                        printf(KRED"Input sbagliato, riprova\n"KYEL"$ "); 
                    }else{
                        printf(KRED"Gli input devono essere '1' o '2' , riprova\n"KYEL"$ ");
                    }
                }
            }while(c != 1 && c != 2 && c != 3);
            if(x == 1)
                canc_caverna(c, &head_arvais, &last_arvais);
            else
                canc_caverna(c, &head_hartornen, &last_hartornen);     
        break;
        case 4:
            if(control == 1){
            printf("Chiudi cunicolo\n");   
                }else{
                    if(r <= 50)
                        printf(KRED"Non sono state creati tutti i cunicoli!\n");
                    else
                        printf(KRED"Ricordati che i cunicoli per entrambe le famiglie devono essere dieci!\n");
            } 
        }
    }while(choice !=4);
}

static void ins_cunicolo(int t, Cave_t** head, Cave_t** last){
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

        if(*head == NULL){
            *head = new;
            *last = new;
        }else{        
            if(t == 1){
                (*last)->avanti = new;
                *last = new;    
            }else if(t == 2){
                (*last)->sinistra = new;
                *last = new;
            }else if(t == 3){
                (*last)->destra = new;
                *last = new;        
            }  
            
        }
    
}

static void stampa_cunicolo(Cave_t** first){
    if(*first == NULL){
        printf(KRED"Non c'è nessun cunicolo\n");
    }else{
        Cave_t* scan = NULL;
        scan = *first;
        int c = 1;
            do{
                printf(KGRN"Quantita melassa:%d-------del cunicolo %d\n", scan->melassa, c);
            
                if(scan->destra == NULL && scan->sinistra == NULL){
                    scan = scan->avanti;
                }else if(scan->destra == NULL && scan->avanti == NULL){
                    scan = scan->sinistra;
                }else if(scan->avanti == NULL && scan->sinistra == NULL){
                    scan = scan->destra;
                }
                c++;  
            }while(scan != NULL);
            printf(KGRN"L'ultimo cunicolo è stato eliminato\n");
            delay(1);
        
    } 
}

static int chiudi_cunicolo(){
    clear;
    printf(KGRN"Sicuro? se esci dalla modalità--- CREA CUNICOLO ---non potrai più rientrare fino alla chiusura del gioco...\n");
    char temp='0';
    int s;
    do{
        printf(KGRN"(y/n)\n"KYEL"$ ");
        scanf(" %c",&temp);

        if(temp=='N'){
            s=1;
           // printf(KGRN"andando a crea inserisci cunicoli\n");
            clear;
            
        }else if(temp =='Y'){
            if(control != 1){
                clear;
                printf(KRED"Impossibile uscire, non tutti i cunicoli sono stati creati\n");
                s=1;
            }else{
                s= 3;
                clear;
                printf(KGRN"Chiusura modalità crea mondo...\n");

            }
        }else{
            clear;
            printf("Valore non riconosciuto...reinserisci la tua risposta\n");
        }

    }while((temp!='N')&&(temp!='Y'));
    return s;
}
    
static void canc_caverna(int t, Cave_t** first, Cave_t** last){
    if(*first == NULL){
        printf(KRED"Non è presente un cunicolo\n");
    }else{
        Cave_t* prev = NULL;
        Cave_t* scan = *first;

        if(scan->avanti == NULL && scan->sinistra == NULL && scan->destra == NULL){
            free(scan);
            first = NULL;
        }else{
            do{
                if(scan->avanti == *last || scan->sinistra == *last || scan->destra == *last){
                    prev = scan;
                    break;
                }else{
                    if(t == 1){
                        scan = scan->avanti;
                    }else if(t == 2){
                        scan = scan->sinistra;
                    }else if(t == 3){
                        scan = scan->destra;
                    }
                }
                    
            }while(scan != NULL);
        }
    }
}