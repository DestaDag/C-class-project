/*
    DESTA DAGIM AYENEW
    MATRICOLA: 314650
*/

#include "gamelib.h"

static Cave_t* head_arvais = NULL;
static Cave_t* head_hartornen = NULL;
static Scava_t arvais;
static Scava_t hartornen;

#define r rand()%101
static void crea_cunicolo();    //creation menu
static void stampa_cunicolo(Cave_t* first); //prints  created caves 
static int chiudi_cunicolo();   //closes the  creation menu
static void avanza(Cave_t **cave, Scava_t *player); //moves the player to the next cave
static void abbatti(Scava_t player, short count); //adds a cave with new properties in a new direction
static void abbatti_cunicolo(Cave_t **head, short count, int t);// adds nodes with the above properties
static void aggira(Scava_t player); //adds a node if the node gets destroyed
static void esci(Cave_t **cave, Scava_t *player);//player exit the cave structure
static void ins_cunicolo(Cave_t **head, int t); //adds a node
static void canc_caverna(Cave_t **head); //deletes a nodes
static bool scontro_finale(Scava_t*player); //handles the final battle
static void set(Cave_t **cave, Scava_t*player, Cave_t **cave2, Scava_t*player2); //sets default values
// to check if creating map is done
static int counter_a = 1;
static int counter_h = 1;
//to check if canc_caverna() has been called
bool delete_check;

static void set(Cave_t **cave, Scava_t*player, Cave_t **cave2, Scava_t*player2){
    player->energia = 4;
    player2->energia = 4;
    player->raccolta = 0;
    player2->raccolta = 0;
    (*cave) = head_arvais;
    (*cave2) = head_hartornen;
    for(int i = 0; i <= 10; i++){
        if(r <= 25){
            player->ammo += 1;
            player2->ammo += 1;
        }
    }
}

int MainMenu(int check){
    int choice = 0;
    clear; 
    printf(KRED"\t******************\n");
    printf(KRED"\t*                *\n");
    printf(KRED"\t*BENVENUTO A DUNE*\n");
    printf(KRED"\t*                *\n");
    printf(KRED"\t******************\n");
    if(check == 3)check = termina_gioco(arvais, hartornen);
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
            check = termina_gioco(arvais, hartornen);
        break;
    }
    return check;
    clear;
    pause;
}

static void crea_cunicolo(){
    int choice = 0;
    int c;
    do{
        clear;
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
                *   creates caves for ARVAIS character
                */
                if(counter_a >= 11){
                    printf(KRED"Sono state create 10 cunicoli per la famiglia ARVAIS\n");
                    pause;
                }else{
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
                *   creates caves for HARTORNEN character
                */
                if(counter_h >= 11){
                    printf(KRED"Sono state create 10 cunicoli per la famiglia HARTORNEN\n");
                    pause;
                }else{
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
                    canc_caverna(&head_arvais);
                    delete_check = false;
                }else{
                    canc_caverna(&head_hartornen);
                    delete_check = true; 
                }    
            break;
            case 3:
                clear;
                printf(KGRN"Ecco i cunicoli creati per la famiglia ARVAIS con le loro rispettive quantita di melassa\n");
                stampa_cunicolo(head_arvais);
                printf(KGRN"\nEcco i cunicoli creati per la famiglia HARTORNEN con le loro rispettive quantita di melassa\n");
                stampa_cunicolo(head_hartornen);
                pause;
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
                pause;
                clear;
            break; 
        }
    }while(choice != 5);  
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

static void canc_caverna(Cave_t **head){
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
            s = 5;
        }else{
            clear;
            printf("Valore non riconosciuto...reinserisci la tua risposta\n");
        }
    }while(temp != 2 && temp != 1);   
    return s;
}

int gioca(){
    set(&arvais.position, &arvais, &hartornen.position, &hartornen);
    short turn;
    short count = 1;
    int choice;
    
    clear;
    if(count == 1){
        if(r <= 50){
            printf(KGRN"Il gioco lo inizia ARVAIS\n");
            turn = 1;
        }else{ 
            printf(KGRN"Il gioco lo inizia HARTORNEN\n");
            turn = 2;
        }
    }
    do{
        int s = 3;
        if(r <= s){
            clear;
            printf(KGRN"Vi siete Sbattuti nella stessa caverna, dovete combattere 1v1!!!");
            turn = 1;
            arvais.energia += arvais.raccolta;
            hartornen.energia += hartornen.raccolta;
            do{
                clear;
                printf(KRED"-------ARVAIS-------\n");
                printf(KWHT"%d: \t"KRED"ENERGIA\n"KWHT"%d: \t"KRED"AMMO\n\n",arvais.energia, arvais.ammo);
                printf(KBLU"-------HARTORNEN-------\n");
                printf(KWHT"%d: \t"KBLU"ENERGIA\n"KWHT"%d: \t"KBLU"AMMO\n", hartornen.energia, hartornen.ammo);
                printf(KYEL"Premere enter per sparare\n$ ");
                getchar();
                if(turn % 2 != 0){
                    if(scontro_finale(&arvais)){
                        printf(KGRN"Hai colpito HARTORNEN\n");
                        pause;
                        arvais.ammo -= 1;
                        hartornen.energia -= 2;
                    }else{ 
                        printf(KGRN"Non hai colpito il tuo avversario\n");
                        pause;
                    } 
                }else{
                    if(scontro_finale(&hartornen)){
                        arvais.energia -= 2;
                        hartornen.ammo -= 1;
                        printf(KGRN"Hai colpito ARVAIS\n");
                        pause;
                    }else{
                        printf(KGRN"Non hai colpito il tuo arriversario\n");
                        pause;
                    }
                }
                if(arvais.ammo <= 0){
                    break;
                }else if(hartornen.ammo <= 0){
                    break;
                }
                turn++;
            }while(arvais.energia >= 0 || hartornen.energia >= 0);
            break;
        }
        s += 3;
        printf(KWHT"È il turno di: \n");
        if(turn % 2 != 0){
            printf(KRED"-------ARVAIS-------\n");
            printf(KWHT"%d: \t"KRED"ENERGIA\n"KWHT"%d: \t"KRED"RACCOLTA\n",arvais.energia, arvais.raccolta);
            printf(KGRN"Cosa vuoi fare ARVAIS?\n\n");
        }else{
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
                    avanza(&arvais.position, &arvais);
                }else{
                    avanza(&hartornen.position, &hartornen);
                }
            break;
            case 2:
                if(turn % 2 != 0){
                    if(arvais.position == NULL){
                        printf(KRED"Non puoi più inserire un nuvo cunicolo\n");
                    }else{
                        arvais.energia--;
                        abbatti(arvais, count);
                    }
                }else{
                    if(hartornen.position == NULL){
                        printf(KRED"Non puoi più inserire un nuvo cunicolo\n");
                    }else{
                        hartornen.energia--;
                        abbatti(hartornen, count);
                    }
                }
            break;
            case 3:
                if(turn % 2 != 0){
                    if(arvais.position == NULL){
                        printf(KRED"Non puoi più inserire un nuvo cunicolo\n");
                    }else{
                        aggira(arvais);
                    }
                }else{
                    if(hartornen.position == NULL){
                        printf(KRED"Non puoi più inserire un nuvo cunicolo\n");
                    }else{
                        aggira(hartornen);
                    }
                }
                clear;
            break;
            case 4:
                if(turn % 2 != 0){
                    if(arvais.position->stato == 3)
                        esci(&arvais.position, &arvais);
                    else{
                        printf(KGRN"Non puoi uscire\n");
                    }
                }else{
                    if(hartornen.position->stato == 3)
                        esci(&hartornen.position, &hartornen);
                    else{
                        printf(KGRN"Non puoi uscire\n");
                    }
                }
                free(arvais.position);
                arvais.position = NULL;
                free(hartornen.position);
                hartornen.position = NULL;                   
            break;
        }        
        turn++;
        count++;
        int w = 3;
        if(arvais.energia < 0){
            return w;
            printf(KYEL"!!!CONGRATULAZIONI HAI VINTO TU HARTORNEN!!!\n");
            break;
        }else if(hartornen.energia < 0){
            return w;
            printf(KYEL"!!!CONGRATULAZIONI HAI VINTO TU ARVAIS!!!\n");
            break; 
        }
    }while(arvais.position != NULL && hartornen.position != NULL);
    
    if(arvais.energia > 0 && arvais.raccolta > 0){
        if(arvais.raccolta > hartornen.raccolta){
            int w = 3;
            return w;
            printf(KYEL"!!!CONGRATULAZIONI HAI VINTO TU ARVAIS!!!\n");
        }else if(arvais.raccolta < hartornen.raccolta){
            int w = 3;
            return w;
            printf(KYEL"!!!CONGRATULAZIONI HAI VINTO TU HARTORNEN!!!\n");
        }else if(arvais.raccolta == hartornen.raccolta){
            int w = 3;
            return w;
            printf(KYEL"IL GIOCO È FINITO IN PAREGGIO");
        }
    }else if(arvais.energia > hartornen.energia){
        int w = 3;
        printf(KYEL"!!!CONGRATULAZIONI HAI VINTO TU ARVAIS!!!\n");
        pause;    
        return w;
    }else if(arvais.energia < hartornen.energia){
        int w = 3;
        printf(KYEL"!!!CONGRATULAZIONI HAI VINTO TU HARTORNEN!!!\n");
        pause;    
        return w;
    }else {
        int w = 3;
        printf(KYEL"!!!IL GIOCO FINISCE IN PAREGGIO!!!\n");
        pause;    
        return w;
    }

    return 0;
}

int termina_gioco(Scava_t player1, Scava_t player2){
    clear;
    printf(KNRM"GAME OVER\n");
    free(head_arvais);
    head_arvais = NULL;
    free(head_hartornen);
    head_hartornen = NULL;
    free(player1.position);
    player1.position = NULL;
    free(player2.position);
    player2.position = NULL;
    int c = 2;
    return c;
}

static void avanza(Cave_t **cave, Scava_t *player){
    int s;
    clear;
    if((*cave)->melassa  != 0){
        printf(KGRN"In questo cunicolo c'è %d di melassa ", (*cave)->melassa);
        printf(KGRN"Dove vuoi inserirlo?\n");
        printf(KMAG"1-"KYEL" RACCOLTA ENERGIA\n"KMAG"2-"KYEL" RACCOLTA MELASSA\n"KYEL"$ ");

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
    }else printf(KGRN"Non c'è melassa nel cunicolo\n");

    if(s == 1){
        player->energia += (*cave)->melassa;
    }else{
        if(player->raccolta == 10){
            printf(KGRN"Il serbatoio di energia è pieno, la melassa è messa nella raccolta\n");
            player->energia += (*cave)->melassa;        
        }
        player->raccolta += (*cave)->melassa;
    }

    if((*cave)->stato ==  0){//normale
        printf(KGRN"Sei in un cunicolo normale\n");
    }
    if((*cave)->stato == 1){
        printf(KGRN"Questo cunicolo irradia melassa, hai ottenuto 1 unità di melassa\n");
        player->energia += 1;          
    }
    if((*cave)->stato == 2){
        printf(KGRN"Questo cunicolo ti ha perso 1 unità di melassa\n");
        player->energia -= 1;           
    }

    if((*cave)->imprevisto == 0){
        printf(KGRN"Non c'è nessun pericolo in questo cunicolo\n");
    }
    if((*cave)->imprevisto == 1){
        printf(KGRN"Accidenti ti si è crollato addosso il cunicolo, hai cosumato 1 unità di melassa e sei uscito dalle macerie\n");
        player->energia -= 1;
    }
    if((*cave)->imprevisto == 2){
            player->energia = 0;
            player->raccolta = 0;
            printf(KGRN"Il baco ha divorato tutta la tua melassa\n");
    }

    if(r <= 25){
        printf(KGRN"IL CUNICOLO SUCCESSIVO È CROLLATO,NEL TUO PROSSIMO TURNO INSERISCI UNO NUOVO CUNICOLO SCEGLIENDO L' OPZIONE '4- AGGIRA'\n\n");
    }else{
        //moves the player one cave ahead
        if((*cave)->destra == NULL && (*cave)->sinistra == NULL){
            printf("Ti sei spostato di un cunicolo in avanti\n\n");
            (*cave) = (*cave)->avanti;
        }else if((*cave)->destra == NULL && (*cave)->avanti == NULL){
            printf(KGRN"Ti sei spostato di un cunicolo a sinistra\n\n");
            (*cave)= (*cave)->sinistra;
        }else if((*cave)->avanti == NULL && (*cave)->sinistra == NULL){
            printf(KGRN"Ti sei spostato di un cunicolo a destra\n\n");
            (*cave) = (*cave)->destra;
        }
    }
    clear;
    pause;
}

static void abbatti(Scava_t player, short count){
    Cave_t *new = (Cave_t*)malloc(sizeof(Cave_t));

    switch(count){
        case 1:if(r <= 5)new->stato = 3; break;
        case 2:if(r <= 10)new->stato = 3; break;
        case 3:if(r <= 15)new->stato = 3; break;
        case 4:if(r <= 20)new->stato = 3; break;
        case 5:if(r <= 25)new->stato = 3; break;
        case 6:if(r <= 30)new->stato = 3; break;
        case 7:if(r <= 35)new->stato = 3; break;
        case 8:if(r <= 40)new->stato = 3; break;
        case 9:if(r <= 45)new->stato = 3; break;
        case 10:if(r <= 50)new->stato = 3; break;
    }

    if(r <= 40){
        new->melassa = 0; 
    }else if(r > 41 && r <= 80){
        new->melassa = 1;
    }else if(r > 81 && r <= 100){
        new->melassa = 2;
    }

    if(r <= 40){
        new->imprevisto = 0;
    }else if(r > 41 && r <= 80){
        new->imprevisto = 1;
    }else if(r > 81 && r <= 100){
        new->imprevisto = 2;
    }

    if(r <= 50){
        new->stato = 0;
    }else if(r > 51 && r <= 100){
        new->stato = 1;
    }
    if(r > 81 && r <= 100){
        new->stato = 2;
    }

    new->avanti = NULL;
    new->sinistra = NULL;
    new->destra = NULL;

    if(player.position->destra == NULL && player.position->sinistra == NULL){
        if(r <= 50)
            player.position->destra = new;
        else 
            player.position->sinistra = new;
    }else if(player.position->destra == NULL && player.position->avanti == NULL){
        if(r <= 50)
            player.position->destra = new;
        else 
            player.position->avanti = new;
    }else if(player.position->avanti == NULL && player.position->sinistra == NULL){
        if(r <= 50)
            player.position->avanti = new;
        else 
            player.position->sinistra = new;
    }

    int diff = 10 - count;
    if(diff == 10 || diff == 9)
        diff = 2;
    int d = 1;
    do{
        int c;
        clear;
        printf(KGRN"Dove vuoi inserire il %d cunicolo?\n", d);
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
            abbatti_cunicolo(&player.position, count, c);
        d++;        
    }while(d <= diff);
}

static void abbatti_cunicolo(Cave_t **head, short count, int t){
    Cave_t *new = (Cave_t*)malloc(sizeof(Cave_t));

    switch(count){
        case 1:if(r <= 5)new->stato = 3; break;
        case 2:if(r <= 10)new->stato = 3; break;
        case 3:if(r <= 15)new->stato = 3; break;
        case 4:if(r <= 20)new->stato = 3; break;
        case 5:if(r <= 25)new->stato = 3; break;
        case 6:if(r <= 30)new->stato = 3; break;
        case 7:if(r <= 35)new->stato = 3; break;
        case 8:if(r <= 40)new->stato = 3; break;
        case 9:if(r <= 45)new->stato = 3; break;
        case 10:if(r <= 50)new->stato = 3; break;
    }

    if(r <= 40){
        new->melassa = 0; 
    }else if(r > 41 && r <= 80){
        new->melassa = 1;
    }else if(r > 81 && r <= 100){
        new->melassa = 2;
    }

    if(r <= 40){
        new->imprevisto = 0;
    }else if(r > 41 && r <= 80){
        new->imprevisto = 1;
    }else if(r > 81 && r <= 100){
        new->imprevisto = 2;
    }

    if(r <= 50){
        new->stato = 0;
    }else if(r > 51 && r <= 100){
        new->stato = 1;
    }
    if(r > 81 && r <= 100){
        new->stato = 2;
    }

    new->avanti = NULL;
    new->sinistra = NULL;
    new->destra = NULL;

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

static void aggira(Scava_t player){
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

    Cave_t* toDelete;
    Cave_t* next;
    if(player.position->destra == NULL && player.position->sinistra == NULL){
        toDelete = player.position->avanti;
    }else if(player.position->destra == NULL && player.position->avanti == NULL){
        toDelete = player.position->sinistra;
    }else if(player.position->avanti == NULL && player.position->sinistra == NULL){
        toDelete = player.position->destra;
    }
    if(toDelete->destra == NULL && toDelete->sinistra == NULL){
       next = toDelete->avanti;
       free(toDelete);
       new->avanti = next; 
    }else if(toDelete->destra == NULL && toDelete->avanti == NULL){
       next = toDelete->sinistra;
       free(toDelete);
       new->sinistra = next; 
    }else if(toDelete->avanti == NULL && toDelete->sinistra == NULL){
       next = toDelete->destra;
       free(toDelete);
       new->destra = next; 
    }
    if(player.position->destra == NULL && player.position->sinistra == NULL){
        player.position->avanti = new;
    }else if(player.position->destra == NULL && player.position->avanti == NULL){
        player.position->sinistra = new;
    }else if(player.position->avanti == NULL && player.position->sinistra == NULL){
        player.position->destra = new;
    }
}

static void esci(Cave_t **cave, Scava_t *player){
    clear;
    pause;
    printf(KNRM"GAME OVER\n");
    free(head_arvais);
    head_arvais = NULL;
    free(head_hartornen);
    head_hartornen = NULL;
}

static bool scontro_finale(Scava_t*player){
    if(r <= 50){
        return true;
    }else{
        return false;

    }    
}