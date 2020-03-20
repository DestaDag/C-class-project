/*
    DESTA DAGIM AYENEW
    MATRICOLA: 314650
    v: 0.1.0
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
static void  canc_caverna(int t, Cave_t* head, Cave_t* tail);
// to check if creating map is done
static int control = 0;
static int counter_a = 1;
static int counter_h = 1;
//to check if canc_caverna() has been called
bool delete_check;
//pointers to the first and last node of the arvais linked list
static Cave_t* head_arvais = NULL;
static Cave_t* last_arvais = NULL;
//pointers to the first and last node of the hartornen linked list
static Cave_t* head_hartornen = NULL;
static Cave_t* last_hartornen = NULL;
//seed for generating random numbers
#define r rand()%101
static Scava_t arvais;
static Scava_t hartornen;

void MainMenu(int check){
    int choice = 0;
    clear;
    printf(KRED"\t******************\n");
    printf(KRED"\t*                *\n");
    printf(KRED"\t*BENVENUTO A DUNE*\n");
    printf(KRED"\t*                *\n");
    printf(KRED"\t******************\n\n\n");
   
    printf(KMAG"--------MAIN-MENU--------\n");
    printf(KNRM"\t"KRED"1-"KBLU" CREA CUNICOLI\n\t"KRED"2-"KBLU" GIOCA\n\t"KRED"3-"KBLU" TERMINA GIOCO\n"KYEL"$ ");
    scanf("%d", &choice);
    
    switch (choice){
    case 1:
        crea_cunicolo();
        check = 1;
        break;
    case 2:
        clear;
        gioca();
        break;
    case 3:
        termina_gioco();
        break;
    }
}

static void crea_cunicolo(){
    int choice = 0;
    int c;
    bool b = true;

    do{
        //clear;
        printf(KMAG"\n\n--------MAP-CREATION-MENU-------\n");
        printf(KNRM"\t"KRED"1-"KBLU" INSERISCI CUNICOLO\n\t"KRED"2-"KBLU" ELIMINA CUNICOLO\n\t"KRED"3-"KBLU" STAMPA CUNICOLO\n\t"KRED"4-"KBLU" RITORNA AL MAIN MENU\n"KYEL"$ ");
        scanf("%d", &choice);
        if(choice  == 2){
            if(delete_check == false){
                if(counter_a == 1)
                    counter_a = 1;
                else
                    --counter_a;
            }else if(delete_check == true){
                if(counter_h == 1)
                    counter_h = 1;
                else
                    --counter_h;
            }
        }
        switch(choice){
        case 1:
            /*
                PER CREARE CUNICOLI PER LA FAMIGLIA ARVAIS
            */
            if(counter_a >= 11)
                printf(KRED"Sono state create 10 cunicoli per la famiglia ARVAIS\n");
            do{
                clear;
                printf(KGRN"\n\nFaccciamo i cunicoli per la famiglia ARVAIS:\ndove vuoi inserire il"KMAG" %d"KGRN" cunicolo?\n", counter_a);
                ++counter_a;
            
                printf(KNRM"\t"KRED"1-"KBLU" AVANTI\n\t"KRED"2-"KBLU" SINISTRA\n\t"KRED"3-"KBLU" DESTRA\n");
              
                printf(KYEL"$ ");
                
                do{            
                    scanf("%d", &c);
                    if(c != 1 && c != 2 && c != 3){
                        if(r <= 50){
                            printf(KRED"Input sbagliato, riprova.\n"KYEL"$ ");
                        }else{
                            printf(KRED"Gli input devono essere '1', '2', '3'\n"KYEL"$ ");
                        }
                    }
                }while(c != 1 && c != 2 && c != 3);
                b = true;
                ins_cunicolo(c, b);
            }while(counter_a <= 10);
            
            /*
                PER CREARE CUNICOLI PER LA FAMIGLIA HARTORNEN
            */

            if(counter_h >= 11)
                printf(KRED"Sono state create 10 cunicoli per la famiglia HARTORNEN\n");
            do{
                clear;
                printf(KGRN"\n\nFaccciamo i cunicoli per la famiglia HARTORNEN:\ndove vuoi inserire il"KMAG" %d"KGRN" cunicolo?\n", counter_h);
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
            }while(counter_h <= 10);
            
            control = 1;            
            if(counter_h == 11 && counter_a == 1){
                clear;
                printf(KGRN"Sono state create 10 cunicoli per entrambe le famiglie\nSi puo` proseguire con il gioco\n");
            }
            break;
        case 2:
            clear;
            int x;
            printf(KGRN"Quale cunicolo vuoi eliminare?\n");
            printf(KMAG"\t1"KYEL"-------CUNICOLO FAMIGLIA ARVAIS\n"KMAG"\t2"KYEL"-------CUNICOLO FAMIGLIA HARTORNEN\n"KYEL"$ ");
            do{
                scanf("%d", &x);
                if(x != 1 && x != 2){
                    if(r <= 50){
                        printf(KRED"Input sbagliato, riprova\n"KYEL"$ "); 
                    }else{
                        printf(KRED"Gli input devono essere '1' o '2' , riprova\n"KYEL"$ ");
                    }
                }
            }while(x != 1 && x != 2 && x != 3);
            
            if(x == 1){
                canc_caverna(c, head_arvais, last_arvais);
                delete_check = false;
            }else{
                canc_caverna(c, head_hartornen, last_hartornen);
                delete_check = true; 
            }    
            break;
        case 3:
            clear;
            printf(KGRN"Ecco i cunicoli creati per la famiglia ARVAIS con le loro rispettive quantita di melassa\n");
            stampa_cunicolo(head_arvais);

            printf(KGRN"\nEcco i cunicoli creati per la famiglia HARTORNEN con le loro rispettive quantita di melassa\n");
            stampa_cunicolo(head_hartornen);

        break;
        case 4:
            if(counter_h == 11 && counter_a == 11){
                choice = chiudi_cunicolo();
                }else{
                    if(r <= 50){
                        clear;
                        printf(KRED"Non sono state creati tutti i cunicoli!\n");
                    }else{
                        clear;
                        printf(KRED"Ricordati che i cunicoli per entrambe le famiglie devono essere dieci!\n");
                    }
            } 
        }
    }while(choice !=4);
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
        new->stato = 1;
    }else if(r > 86 && r <= 100){
        new->stato = 2;
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
                printf(KYEL"Quantita melassa:"KMAG"%d"KYEL"-------del cunicolo"KMAG" %d\n", scan->melassa, c);
            
                if(scan->destra == NULL && scan->sinistra == NULL){
                    scan = scan->avanti;
                }else if(scan->destra == NULL && scan->avanti == NULL){
                    scan = scan->sinistra;
                }else if(scan->avanti == NULL && scan->sinistra == NULL){
                    scan = scan->destra;
                }
                c++;
                if(c > 10)
                    break;
            }while(scan != NULL);
    } 
}

static int chiudi_cunicolo(){
    clear;
    printf(KGRN"Sicuro? se esci dalla modalità--- CREA CUNICOLO ---non potrai più rientrare fino alla chiusura del gioco...\n");
    int  temp=0;
    int s;
    do{
        printf(KGRN"premere '1' per proseguire, premere '2' per ritornare al menu\n"KYEL"$ ");
        scanf("%d",&temp);
        if(temp==2){
            clear;
            printf(KGRN"Cosa vuoi effettuare?\n");
            printf(KMAG"1-"KYEL" ELIMINA CUNICOLO\n"KMAG"2-"KYEL" STAMPA CUNICOLO\n");
            scanf("%d", &s);
            return s;
            clear;
        }else if(temp ==1){
            s = 4;
        }else{
            clear;
            printf("Valore non riconosciuto...reinserisci la tua risposta\n");
        }
    }while((temp!=2)&&(temp!=1));   
    return s;
}
    
static void canc_caverna(int t, Cave_t* head, Cave_t * tail){
    if(head == NULL)
        printf(KRED"Non c'e` nessun cunicolo da eliminare!\n");
    else{
        Cave_t* pPrev = NULL;
        Cave_t* pScan  = head;

        if(pScan->avanti == NULL && pScan->sinistra == NULL && pScan->destra == NULL){//abbiamo solo un cunicolo
            free(pScan);
            head = NULL;
        }
        else{
            do{
                if(((pScan->avanti) == tail) || ((pScan->sinistra) == tail) || ((pScan->destra) == tail)){
                    pPrev = pScan;
                    break;
                }else{
                    if(pScan->destra == NULL && pScan->sinistra == NULL){
                        pScan = pScan->avanti;
                    }else if(pScan->destra == NULL && pScan->avanti == NULL){
                        pScan = pScan->sinistra;
                    }else if(pScan->avanti == NULL && pScan->sinistra == NULL){
                        pScan = pScan->destra;
                    }
                }
            }while(pScan != NULL);
            
    
            free(pPrev->avanti);
            //pPrev = NULL;
            pPrev->avanti = NULL;
            pPrev->sinistra = NULL;
            pPrev->destra = NULL;
            pScan->avanti = pPrev;
            pScan->sinistra = NULL;
            pScan->destra = NULL;
            tail = pPrev;
            free(pPrev->sinistra);
            pPrev->sinistra = NULL;
            pScan->sinistra = NULL;
            tail = pPrev;
            free(pPrev->destra);
            pPrev->destra = NULL;
            pScan->sinistra = NULL;
            tail = pPrev;
            printf(KGRN"Il cunicolo e` stato rimosso!\n");
            //free(pPrev);
            //pPrev->avanti = pPrev->sinistra = pPrev->destra = NULL;
            //tail = pPrev;
            head = pPrev;
        }
    }
}

void gioca(){
    clear;
    printf(KGRN"Gioca!\n");

}

void termina_gioco(){
    clear;
    printf(KNRM"Termina gioco\n");
}