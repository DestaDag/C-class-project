/*
    DESTA DAGIM AYENEW
    MATRICOLA: 314650
*/
#include "gamelib.h"

//function for creating, deleting and printing linked list
static void crea_cunicolo();

//outputs the linked list
static void stampa_cunicolo(Cave_t* first);
//function for exiting from the map creation menu
static int chiudi_cunicolo();
//static void avanza();
//static void abbatti();
//static void aggira();
//static void esci();
//creates the two structures
static void ins_cunicolo(int t, bool b);
//deletes the last node
static void  canc_caverna(Cave_t* first, Cave_t* last, int t);
//static void print(Cave_t* cave, int t);//to display the linked list
//outputs the linked list
static void stampa_cunicolo(Cave_t* first);
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
    printf(KYEL"prima di iniziare regolare le dimensioni dello schermo\n");
    delay(3);
    clear;
    printf(KYEL"loading...\n");
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
    bool b = true;
    int counter_a = 1;
    int counter_h = 1;
    do{
        clear;
        printf(KMAG"--------MAP-CREATION-MENU-------\n");
        printf(KNRM"\t"KRED"1-"KBLU" INSERISCI CUNICOLO\n\t"KRED"2-"KBLU" STAMPA CUNICOLO\n\t"KRED"3-"KBLU" ELIMINA CUNICOLO\n\t"KRED"4-"KBLU" RITORNA AL MAIN MENU\n"KYEL"$ ");
        scanf("%d", &choice);
        switch(choice){
        case 1: 
            clear;
            printf(KGRN"\nFaccciamo i cunicoli per la famiglia Arvais:\ndove vuoi inserire il %d cunicolo?\n", counter_a);
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
            b = true;
            ins_cunicolo(c, b);
            //head_arvais->scelta[counter] = c;
            clear;                
            printf(KGRN"\nFaccciamo i cunicoli per la famiglia Hartornen:\ndove vuoi inserire il %d cunicolo?\n", counter_h);
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
            b = false;
            ins_cunicolo(c, b);
            //head_hartornen->scelta[counter] = c;
            if(counter_h == 10 && counter_a == 10){
                control = 1;
                printf(KGRN"Sono state create 10 cunicoli per entrambe le famiglie\n");
            }       
        break;
        case 2:
            clear;
            printf(KGRN"Ecco i cunicoli creati per la famiglia arvais con le loro rispettive quantita di melassa\n");
            stampa_cunicolo(head_arvais);
            delay(1);
            printf(KGRN"Ecco i cunicoli creati per la famiglia hartornen con le loro rispettive quantita di melassa\n");
            stampa_cunicolo(head_hartornen);
            delay(5);
            
            //*check  = 1;
        break;
        case 3:
             canc_caverna(head_arvais, last_hartornen, c);     
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
    }while(choice !=3);
}

static void ins_cunicolo(int t, bool b){
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
        if(head_arvais == NULL){
            head_arvais = new;
            last_arvais = new;
        }else{        
            if(t == 1){
                last_arvais->avanti = new;
                last_arvais = new;    
            }else if(t == 2){
                last_arvais->sinistra = new;
                last_arvais = new;
            }else if(t == 3){
                last_arvais->destra = new;
                last_arvais = new;        
            }  
        }
    }else if(b == false){
            if(head_hartornen == NULL){
                head_hartornen = new;
                last_hartornen = new;
            }else{       
                 if(t == 1){
                    last_hartornen->avanti = new;
                    last_hartornen = new;
                }else if(t == 2){
                    last_hartornen->sinistra = new;
                    last_hartornen = new;
                }else if(t == 3){
                    last_hartornen->destra = new;
                    last_hartornen = new;
                } 
            }        


    }
}

static void stampa_cunicolo(Cave_t* first){
    if(first == NULL){
        printf(KRED"Non c'è nessun cunicolo\n");
    }else{
        Cave_t* scan = first;
        int c = 1;
            do{
                printf(KGRN"Quantita melassa:%d\tdel cunicolo %d\n", scan->melassa, c);
            
                if(scan->destra == NULL && scan->sinistra == NULL){
                    scan = scan->avanti;
                }else if(scan->destra == NULL && scan->avanti == NULL){
                    scan = scan->sinistra;
                }else if(scan->avanti == NULL && scan->sinistra == NULL){
                    scan = scan->destra;
                }
                c++;  
            }while(scan != NULL);
        
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
    
static void canc_caverna(Cave_t* first, Cave_t* last, int t){
    if(first == NULL){
        printf(KRED"Non è presente un cunicolo\n");
    }else{
        Cave_t* prev = NULL;
        Cave_t* scan = first;

        if(scan->avanti == NULL && scan->sinistra == NULL && scan->destra == NULL){
            free(scan);
            first = NULL;
        }else{
            do{
                if(scan->avanti == last || scan->sinistra == last || scan->destra == last){
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