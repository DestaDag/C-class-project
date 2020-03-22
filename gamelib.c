/*
    DESTA DAGIM AYENEW
    MATRICOLA: 314650
    v: 0.1.0
*/

#include "gamelib.h"

static Cave_t* head_arvais = NULL;
static Cave_t* head_hartornen = NULL;

static Scava_t arvais;
static Scava_t hartornen;

#define r rand()%101
static void crea_cunicolo();
static void stampa_cunicolo(Cave_t* first);
static int chiudi_cunicolo();
static void avanza(Scava_t player);
static void abbatti(Scava_t player);
static void aggira(Cave_t **head);
static void esci();
static void ins_cunicolo(Cave_t **head, int t);
static void canc_caverna(Cave_t** head, int t);
// to check if creating map is done
static int counter_a = 1;
static int counter_h = 1;
//to check if canc_caverna() has been called
bool delete_check;

int MainMenu(int check){
    int choice = 0;
    clear;
    printf(KRED"\t******************\n");
    printf(KRED"\t*                *\n");
    printf(KRED"\t*BENVENUTO A DUNE*\n");
    printf(KRED"\t*                *\n");
    printf(KRED"\t******************\n\n\n");
    clear;
    
    printf(KMAG"--------MAIN-MENU--------\n");
    printf(KNRM"\t"KRED"1-"KBLU" CREA CUNICOLI\n\t"KRED"2-"KBLU" TERMINA GIOCO\n"KYEL"$ ");
    do{
        scanf("%d", &choice);
        if(choice != 1 && choice != 2){
            if(r <= 50){
               printf(KRED"Input sbagliato, riprova\n"KYEL"$ "); 
            }else{
                printf(KRED"Gli input devono essere '1' o '2', riprova\n"KYEL"$ ");
            }
        }    
    }while(choice != 1 && choice != 2);
    switch (choice){
        case 1:
            crea_cunicolo();
            check = 1;
        break;
        case 2:
            termina_gioco();
        break;
    }
    return check;
}

static void crea_cunicolo(){
    int choice = 0;
    int c;
    do{
        printf(KMAG"\n\n--------MAP-CREATION-MENU-------\n");
        printf(KNRM"\t"KRED"1-"KBLU" INSERISCI CUNICOLO\n\t"KRED"2-"KBLU" ELIMINA CUNICOLO\n\t"KRED"3-"KBLU" STAMPA CUNICOLO\n\t"KRED"4-"KBLU" RITORNA AL MAIN MENU\n"KYEL"$ ");
        do{
            scanf("%d", &choice);
            if(choice != 1 && choice != 2 && choice != 3 && choice != 4){
                if(r <= 50){
                    printf(KRED"Input sbagliato, riprova\n"KYEL"$ "); 
                }else{
                    printf(KRED"Gli input devono essere '1' o '2' o '3' o '4', riprova\n"KYEL"$ ");
                }
            }    
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
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
                *   PER CREARE CUNICOLI PER LA FAMIGLIA ARVAIS
                */
                if(counter_a >= 11)
                    printf(KRED"Sono state create 10 cunicoli per la famiglia ARVAIS\n");
                else{
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
                    ins_cunicolo(&head_arvais, c);
                }
                /*
                *   PER CREARE CUNICOLI PER LA FAMIGLIA HARTORNEN
                */
                if(counter_h >= 11)
                    printf(KRED"Sono state create 10 cunicoli per la famiglia HARTORNEN\n");
                else{
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
                    ins_cunicolo(&head_hartornen, c);
                }          
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
                    canc_caverna(&head_arvais, x);
                    delete_check = false;
                }else{
                    canc_caverna(&head_hartornen, x);
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
    }while(choice != 4);  
}

static void ins_cunicolo(Cave_t **head, int t){
    Cave_t *new = (Cave_t*)malloc(sizeof(Cave_t));

    if(r <= 50){
        new->melassa = 0; 
    }else if(r > 51 && r <= 70){
        new->melassa = 1;
    }else if(r > 71 && r <= 100){
        new->melassa = 2;
    }
    
    if(r <= 50){
        new->imprevisto = 0;
    }else if(r > 51 && r <= 85){
        new->imprevisto = 1;
    }else if(r > 86 && r <= 100){
        new->imprevisto = 2;
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

    if(*head == NULL)
        *head = new;
    else{
        if(t == 1){
            new->avanti = *head;
            *head = new;
        }else if(t == 2){
            new->sinistra = *head;
            *head = new;
        }else if(t == 3){
            new->destra = *head;
            *head = new;      
        }            
    }    
}

static void stampa_cunicolo(Cave_t *first){
    Cave_t* scan = first;
    if(first == NULL){
        printf(KRED"Non c'è nessun cunicolo\n");
    }else{
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

static void canc_caverna(Cave_t **head, int t){
    Cave_t* first = *head;
    if(*head == NULL){
        printf(KRED"Non c'e` un cunicolo da eliminare");
    }else{
        if(first->destra == NULL && first->sinistra == NULL){
            Cave_t* temp = first->avanti;
            free(*head);
            *head = temp;
        }else if(first->avanti == NULL && first->destra == NULL){
            Cave_t* temp = first->sinistra;
            free(*head);
            *head = temp;
        }else if(first->avanti == NULL && first->sinistra == NULL){
            Cave_t* temp = first->destra;
            free(*head);
            *head = temp;    
        }
        printf(KGRN"Il cunicolo e` stato eliminato");
    }
}

static int chiudi_cunicolo(){
    clear;
    printf(KGRN"Sicuro? se esci dalla modalità--- CREA CUNICOLO ---non potrai più rientrare fino alla chiusura del gioco...\n");
    int temp = 0;
    int s;
    do{
        printf(KGRN"premere '1' per proseguire, premere '2' per ritornare al menu\n"KYEL"$ ");
        scanf("%d", &temp);
        if(temp == 2){
            clear;
            printf(KGRN"Cosa vuoi effettuare?\n");
            printf(KMAG"1-"KYEL" ELIMINA CUNICOLO\n"KMAG"2-"KYEL" STAMPA CUNICOLO\n");
            scanf("%d", &s);
            return s;
            clear;
        }else if(temp == 1){
            s = 4;
        }else{
            clear;
            printf("Valore non riconosciuto...reinserisci la tua risposta\n");
        }
    }while(temp != 2 && temp != 1);   
    return s;
}

void gioca(){
    arvais.energia = 4;
    hartornen.energia = 4;
    arvais.raccolta = 0;
    hartornen.raccolta = 0;
    arvais.position = head_arvais;
    hartornen.position = head_hartornen;
    short turn;
    int choice;
    
    clear;
    if(r <= 50){
        printf(KGRN"Il gioco lo inizia ARVAIS\n");
        turn = 1;
    }else{ 
        printf(KGRN"Il gioco lo inizia HARTORNEN\n");
        turn = 2;
    }

    do{
        if(turn % 2 != 0){
            clear;
            printf(KRED"-------ARVAIS-------\n");
            printf(KWHT"%d: \t"KRED"ENERGIA\n"KWHT"%d: \t"KRED"RACCOLTA\n",arvais.energia, arvais.raccolta);
            printf(KGRN"Cosa vuoi fare ARVAIS?\n\n");
        }else{
            clear;
            printf(KBLU"-------HARTORNEN-------\n");
            printf(KWHT"%d: \t"KBLU"ENERGIA\n"KWHT"%d: \t"KBLU"RACCOLTA\n",hartornen.energia, hartornen.raccolta);
            printf(KGRN"Cosa vuoi fare HARTORNEN?\n\n");
        }
            printf(KNRM"\t"KRED"1-"KBLU" AVANZA\n\t"KRED"2-"KBLU" ABBATTI\n\t"KRED"3-"KBLU" AGGIRA\n\t"KRED"4-"KBLU" ESCI\n"KYEL"$ ");
            do{
                scanf("%d", &choice);
                if(choice != 1 && choice != 2 && choice != 3 && choice != 4){
                    if(r <= 50){
                        printf(KRED"Input sbagliato, riprova\n"KYEL"$ "); 
                    }else{
                        printf(KRED"Gli input devono essere '1' o '2' o '3' o '4', riprova\n"KYEL"$ ");
                    }
                }    
            }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
            switch(choice){
                case 1:
                    if(turn % 2 != 0){
                        avanza(arvais);
                    }else{
                        avanza(hartornen);
                    }
                break;
                case 2:
                    if(turn % 2 != 0){
                        abbatti(arvais);
                    }else{
                        abbatti(hartornen);
                    }
                break;
                case 3:
                    if(turn % 2 != 0){
                        aggira(&arvais.position);
                    }else{
                        aggira(&hartornen.position);
                    }
                break;
                case 4:
                    if(turn % 2 != 0){
                        if(arvais.position->stato == 3)
                            esci();
                        else{
                            printf(KGRN"Non puoi uscire");
                        }
                    }else{
                        if(hartornen.position->stato == 3)
                            esci();
                        else{
                            printf(KGRN"Non puoi uscire");
                        }
                    }
                break;
            }        
        turn++;
    }while(arvais.energia > 0 && hartornen.energia > 0);
}

void termina_gioco(){
    clear;
    printf(KNRM"Termina gioco\n");
}

static void avanza(Scava_t player){
    printf(KGRN"In questo cunicolo c'è %d di melassa ", player.position->melassa);
    printf(KGRN"Dove vuoi inserirlo?\n");
    printf(KMAG"1-"KYEL" RACCOLTA ENERGIA\n"KMAG"2-"KYEL" RACCOLTA MELASSA\n");
    int s;
    do{
        scanf("%d", &s);
        if(s != 1 && s != 2){
            if(r <= 50){
                printf(KRED"Input sbagliato, riprova\n"KYEL"$ "); 
            }else{
                printf(KRED"Gli input devono essere '1' o '2', riprova\n"KYEL"$ ");
            }
        }    
    }while(s != 1 && s != 2);

    if(s == 1){
        player.energia += player.position->melassa;
    }else{
        if(player.raccolta == 10){
            printf(KGRN"Il serbatoio di energia è pieno, la melassa è messa nella raccolta\n");
            player.energia += player.position->melassa;        
        }
        player.raccolta += player.position->melassa;
    }

    if(player.position->stato ==  0){//normale
        printf(KGRN"Sei in un cunicolo normale\n");
    }else if(player.position->stato == 1){
        printf(KGRN"Questo cunicolo irradia melassa, hai ottenuto 1 unità di melassa\n");
        player.energia++;          
    }else if(player.position->stato == 2){
        printf(KGRN"Questo cunicolo ti ha perso 1 unità di melassa\n");
        player.energia--;           
    }

    switch(player.position->imprevisto){
        case 0://nessun imprevisto
            printf(KGRN"Non c'è nessun pericolo in questo cunicolo\n");
        break;
        case 1://crollo
            printf(KGRN"Accidenti ti si è crollato addosso il cunicolo, hai cosumato 1 unità di melassa e sei uscito dalle macerie\n");
            player.energia--;
        break;
        case 2://baco
            player.energia = 0;
            player.raccolta = 0;
            printf(KGRN"Il baco ha divorato tutta la tua melassa\n");
        break;
    }
    if(r <= 25){
        printf(KGRN"Il prossimo cunicolo è crollato, devi iserire uno nuovo\n");
    //moves the player one cave ahead
    if(player.position->destra == NULL && player.position->sinistra == NULL){
        printf("Ti sei spostato di un cunicolo in avanti\n");
        player.position = player.position->avanti;
    }else if(player.position->destra == NULL && player.position->avanti == NULL){
        printf(KGRN"Ti sei spostato di un cunicolo a sinistra\n");
        player.position = player.position->sinistra;
    }else if(player.position->avanti == NULL && player.position->sinistra == NULL){
        printf(KGRN"Ti sei spostato di un cunicolo a destra\n");
        player.position = player.position->destra;
    }
    }
}

static void abbatti(Scava_t player){
    printf("hello\n");   
}

static void aggira(Cave_t **head){
    Cave_t *new = (Cave_t*)malloc(sizeof(Cave_t));

    if(r <= 50){
        new->melassa = 0; 
    }else if(r > 51 && r <= 70){
        new->melassa = 1;
    }else if(r > 71 && r <= 100){
        new->melassa = 2;
    }

    if(r <= 50){
        new->imprevisto = 0;
    }else if(r > 51 && r <= 85){
        new->imprevisto = 1;
    }else if(r > 86 && r <= 100){
        new->imprevisto = 2;
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

    //finish

}

static void esci(Scava_t player){
    printf("hello\n");
    
}