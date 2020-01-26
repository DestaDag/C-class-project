#include "gamelib.h"

Cave_t* primo_cunicolo = NULL;
Cave_t* ultimo_cunicolo = NULL;

static void tail_add(Cave_t* first, Cave_t* last, int t);

static void tail_add(Cave_t* first, Cave_t* last, int t){
    Cave_t* new =(Cave_t*)malloc(sizeof(Cave_t));
    if(t == 1){
        new->avanti = NULL;
        if(first == NULL){
            first  = new;
            last = new;
        }else{
            last->avanti = new;
            last = new;
        }
    }else if(t == 2){
        new->sinistra = NULL;
        if(first == NULL){
            first = new;
            last = new;
        }else{
            last->sinistra = new;
            last = new;
        }
    }else if(t == 3){
        new->destra = NULL;
        if(first == NULL){
            first = new;
            last = new;
        }else{
            last->destra = new;
            last = new;
        }
    }
}
//
Cave_t* new = (Cave_t*)malloc(sizeof(Cave_t));
if(t == 1){
    new->avanti = NULL;
    if(head_arvais == NULL){
        head_arvais = new;
        last_arvais = new;
    }else{
        last_arvais->avanti = new;
        last_arvais = new;
    }
}else if(t == 2){
    new->sinistra = NULL;
    if(head_arvais == NULL){
        head_arvais = new;
        last_arvais = new;
    }else{
        last_arvais->sinistra = new;
        last_arvais = new;
    }
}else if(t == 3){
    new->destra = NULL;
    if(head_arvais == NULL){
        head_arvais = new;
        last_arvais = new;
    }else{
        last_arvais->destra = new;
        last_arvais = new;
    }
}
//
static void ins_caverna(Cave_t* first, Cave_t* last, int t){
    Cave_t* new = (Cave_t*)malloc(sizeof(Cave_t));

        switch(t){
        case 1:{
        new->avanti = NULL;
        if(first == NULL){
            first  = new;
            last = new;
        }else{
            last->avanti = new;
            last = new;
        }}
        break;
        case 2:{
        new->sinistra = NULL;
        if(first == NULL){
            first = new;
            last = new;
        }else{
            last->sinistra = new;
            last = new;
        }}
        break;
        case 3:{
        new->destra = NULL;
        if(first == NULL){
            first = new;
            last = new;
        }else{
            last->destra = new;
            last = new;
        }}
        break;
    }
    control = 1;
}
//print list
static void print(Cave_t* first){
    if(first == NULL){
        printf("No node in the list\n");
    }else{
        Cave_t* scan = first;
        int c = 0;
        do{
            printf("quantita melassa %d\n", scan->melassa);

    switch(scan->scelta[i]){
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


    switch(scan->scelta[i]){
        case 1: scan = scan->avanti;
        break;
        case 2: scan = scan->sinistra;
        break;
        case 3: scan = scan->destra;
        break;    
    }
}

static void ins_caverna(int t, Cave_t* first, Cave_t* last){
    Cave_t* new = (Cave_t*)malloc(sizeof(Cave_t));
   // int i = 0;
   /* do{
        new->scelta[i] = t;
    i++;
    } while (i <= 9);*/
    

    new->avanti = NULL;
    new->sinistra = NULL;
    new->destra = NULL;
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
    
        if(first == NULL){
            first = new;
            last = new;
        }else{        
            if(t == 1){
                last->avanti = new;
                last_ = new;    
            }else if(t == 2){
                last->sinistra = new;
                last = new;
            }else if(t == 3){
                last->destra = new;
                last = new;        
            }  
        }
    
}
//jhgf
static void ins_caverna(int t, bool b){
    Cave_t* new = (Cave_t*)malloc(sizeof(Cave_t));
   // int i = 0;
   /* do{
        new->scelta[i] = t;
    i++;
    } while (i <= 9);*/
    

    new->avanti = NULL;
    new->sinistra = NULL;
    new->destra = NULL;
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
//
{
            int counter = 1;
            printf(KGRN"i cunicoli per entrambe le famiglie saranno dieci\n");
            do{
                printf(KGRN"\nfaccciamo i cunicoli per la famiglia Arvais:\ndove vuoi inserire il %d cunicolo?\n", counter);
                printf(KNRM"\t"KRED"1-"KBLU" AVANTI\n\t"KRED"2-"KBLU" SINISTRA\n\t"KRED"3-"KBLU" DESTRA\n");                
                printf(KYEL"$ ");
                
                
                int c;
                do{
                    scanf("%d", &c);
                    if(c != 1 && c != 2 && c != 3)
                        if(r <= 50){
                            printf(KRED"input sbagliato, riprova\n"KYEL"$ ");
                            
                        }else{
                            printf(KRED"gli input devono essere '1' o '2' o '3'\n"KYEL"$ ");
                         
                         }
                }while(c != 1 && c != 2 && c != 3);
                bool b = true;
                ins_caverna(c, b);
                //head_arvais->scelta[counter] = c;
                counter++;
            }while(counter <= 10);
            
            counter = 1;
            do{
                printf(KGRN"\nfaccciamo i cunicoli per la famiglia Hartornen:\ndove vuoi inserire il %d cunicolo?\n", counter);
                printf(KNRM"\t"KRED"1-"KBLU" AVANTI\n\t"KRED"2-"KBLU" SINISTRA\n\t"KRED"3-"KBLU" DESTRA\n"); 
                printf(KYEL"$ ");
                
                int c;
                do{
                    scanf("%d", &c);
                    if(c != 1 && c != 2 && c != 3)
                        if(r <= 50){
                            printf(KRED"input sbagliato, riprova\n"KYEL"$ ");
                            
                        }else{
                            printf(KRED"gli input devono essere '1' o '2' o '3', riprova\n"KYEL"$ ");
        
                        }
                }while(c != 1 && c != 2 && c != 3);
                int b = false;
                ins_caverna(c, b);
                //head_hartornen->scelta[counter] = c;
                counter++;
            }while(counter <= 10);
        }
        //05/01/2020
//without a random number
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
//with random number
static void ins_cunicolo(bool b){
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
            if(r <= 33){
                last_arvais->avanti = new;
                last_arvais = new;    
            }else if(r > 34 && r <= 66){
                last_arvais->sinistra = new;
                last_arvais = new;
            }else if(r > 67 && r <= 100){
                last_arvais->destra = new;
                last_arvais = new;        
            }  
        }
    }else if(b == false){
            if(head_hartornen == NULL){
                head_hartornen = new;
                last_hartornen = new;
            }else{       
                 if(r <= 33){
                    last_hartornen->avanti = new;
                    last_hartornen = new;
                }else if(r > 34 && r <= 66){
                    last_hartornen->sinistra = new;
                    last_hartornen = new;
                }else if(r > 67 && r <= 100){
                    last_hartornen->destra = new;
                    last_hartornen = new;
                } 
            }        


    }
}

//without random
static void crea_cunicolo(){
    int choice = 0;
    do{
        clear;
        printf(KMAG"--------MAP-CREATION-MENU-------\n");
        printf(KNRM"\t"KRED"1-"KBLU" CREA CUNICOLI\n\t"KRED"2-"KBLU" STAMPA CUNICOLI\n\t"KRED"3-"KBLU" ELIMINA CUNICOLO\n\t"KRED"4-"KBLU" RITORNA AL MAIN MENU\n"KYEL"$ ");
        scanf("%d", &choice);
        switch(choice){
        case 1:{ 
            clear;
            int counter = 1;
            printf(KGRN"i cunicoli per entrambe le famiglie saranno dieci\n");
            do{
                printf(KGRN"\nfaccciamo i cunicoli per la famiglia Arvais:\ndove vuoi inserire il %d cunicolo?\n", counter);
                printf(KNRM"\t"KRED"1-"KBLU" AVANTI\n\t"KRED"2-"KBLU" SINISTRA\n\t"KRED"3-"KBLU" DESTRA\n");                
                printf(KYEL"$ ");
                int c;
                do{
                    scanf("%d", &c);
                    if(c != 1 && c != 2 && c != 3)
                        if(r <= 50){
                            printf(KRED"input sbagliato, riprova\n"KYEL"$ ");
                        }else{
                            printf(KRED"gli input devono essere '1' o '2' o '3'\n"KYEL"$ ");
                        }
                }while(c != 1 && c != 2 && c != 3);
                bool b = true;
                ins_cunicolo(c, b);
                //head_arvais->scelta[counter] = c;
                counter++;
            }while(counter <= 10);
            counter = 1;
            clear;
            do{
                
                printf(KGRN"\nfaccciamo i cunicoli per la famiglia Hartornen:\ndove vuoi inserire il %d cunicolo?\n", counter);
                printf(KNRM"\t"KRED"1-"KBLU" AVANTI\n\t"KRED"2-"KBLU" SINISTRA\n\t"KRED"3-"KBLU" DESTRA\n"); 
                printf(KYEL"$ ");
                int c;
                do{
                    scanf("%d", &c);
                    if(c != 1 && c != 2 && c != 3)
                        if(r <= 50){
                            printf(KRED"input sbagliato, riprova\n"KYEL"$ "); 
                        }else{
                            printf(KRED"gli input devono essere '1' o '2' o '3', riprova\n"KYEL"$ ");
                        }
                }while(c != 1 && c != 2 && c != 3);
                int b = false;
                ins_cunicolo(c, b);
                //head_hartornen->scelta[counter] = c;
                counter++;
            }while(counter <= 10);
            control = 1;
            }
        break;
        case 2:{
            printf(KGRN"\t\t\tecco i cunicoli creati per la famiglia arvais con le loro rispettive quantita di melassa\n");
            stampa_cunicolo(head_arvais);
            char c;
            printf(KBLU"\tper vedere i cunicoli della famiglia hartornen premere il tasto invio\n"KYEL"$");
            scanf("%c", &c);
            if(c == '\n'){
                printf(KGRN"\t\t\tecco i cunicoli creati per la famiglia hartornen con le loro rispettive quantita di melassa\n");
                stampa_cunicolo(head_hartornen);
            }
            //*check  = 1;
            }
        break;
        case 3:{
             printf("elimina cunicolo\n");
            }
        break;
        case 4:{
            choice =chiudi_cunicolo();
            printf("chiudi cunicolo\n");
            }
        }
    }while(choice !=3);
}
//with random
static void crea_cunicolo(){
    int choice = 0;
    do{
        clear;
        printf(KMAG"--------MAP-CREATION-MENU-------\n");
        printf(KNRM"\t"KRED"1-"KBLU" CREA CUNICOLI\n\t"KRED"2-"KBLU" STAMPA CUNICOLI\n\t"KRED"3-"KBLU" ELIMINA CUNICOLO\n\t"KRED"4-"KBLU" RITORNA AL MAIN MENU\n"KYEL"$ ");
        scanf("%d", &choice);
        switch(choice){
        case 1:{ 
            clear;
            int counter = 1;
            printf(KGRN"i cunicoli per entrambe le famiglie saranno dieci\n");
            do{
                printf(KGRN"\nfaccciamo i cunicoli per la famiglia Arvais:\ninserendo il %d cunicolo?\n", counter);
                bool b = true;
                ins_cunicolo(b);
                //head_arvais->scelta[counter] = c;
                counter++;
            }while(counter <= 10);
            counter = 1;
            clear;

            do{    
                printf(KGRN"\nfaccciamo i cunicoli per la famiglia Hartornen:\ninserendo il %d cunicolo?\n", counter);

                
                    bool b = false;
                    ins_cunicolo(b);
                    //head_hartornen->scelta[counter] = c;
                    counter++;
            }while(counter <= 10);
            control = 1;
        } 
        break;
        case 2:{
            printf(KGRN"\t\t\tecco i cunicoli creati per la famiglia arvais con le loro rispettive quantita di melassa\n");
            stampa_cunicolo(head_arvais);
            char c;
            printf(KBLU"\tper vedere i cunicoli della famiglia hartornen premere il tasto invio\n"KYEL"$");
            scanf("%c", &c);
            if(c == '\n'){
                printf(KGRN"\t\t\tecco i cunicoli creati per la famiglia hartornen con le loro rispettive quantita di melassa\n");
                stampa_cunicolo(head_hartornen);
            }
            //*check  = 1;
            }
        break;
        case 3:{
             printf("elimina cunicolo\n");
            }
        break;
        case 4:{
            choice =chiudi_cunicolo();
            printf("chiudi cunicolo\n");
            }
        }
    }while(choice !=3);
}

//CAMBIAMENTO di main menu
static void crea_cunicolo(){
    int choice = 0;
    do{
        clear;
        printf(KMAG"--------MAP-CREATION-MENU-------\n");
        printf(KNRM"\t"KRED"1-"KBLU" INSERISCI CUNICOLO\n\t"KRED"2-"KBLU" STAMPA CUNICOLO\n\t"KRED"3-"KBLU" ELIMINA CUNICOLO\n\t"KRED"4-"KBLU" RITORNA AL MAIN MENU\n"KYEL"$ ");
        scanf("%d", &choice);
        switch(choice){
        case 1:{ 
            clear;
            int counter_a= 1;
            //printf(KGRN"i cunicoli per entrambe le famiglie saranno dieci\n");
                printf(KGRN"\nfaccciamo i cunicoli per la famiglia Arvais:\ndove vuoi inserire il %d cunicolo?\n", counter);
                printf(KNRM"\t"KRED"1-"KBLU" AVANTI\n\t"KRED"2-"KBLU" SINISTRA\n\t"KRED"3-"KBLU" DESTRA\n");                
                printf(KYEL"$ ");
                int c;
                do{
                    scanf("%d", &c);
                    if(c != 1 && c != 2 && c != 3)
                        if(r <= 50){
                            printf(KRED"input sbagliato, riprova\n"KYEL"$ ");
                        }else{
                            printf(KRED"gli input devono essere '1' o '2' o '3'\n"KYEL"$ ");
                        }
                }while(c != 1 && c != 2 && c != 3);
                bool b = true;
                ins_cunicolo(c, b);
                //head_arvais->scelta[counter] = c;
                counter_h++;
            clear;
                int counter_h = 1;
                
                printf(KGRN"\nfaccciamo i cunicoli per la famiglia Hartornen:\ndove vuoi inserire il %d cunicolo?\n", counter);
                printf(KNRM"\t"KRED"1-"KBLU" AVANTI\n\t"KRED"2-"KBLU" SINISTRA\n\t"KRED"3-"KBLU" DESTRA\n"); 
                printf(KYEL"$ ");
                int c;
                do{
                    scanf("%d", &c);
                    if(c != 1 && c != 2 && c != 3)
                        if(r <= 50){
                            printf(KRED"input sbagliato, riprova\n"KYEL"$ "); 
                        }else{
                            printf(KRED"gli input devono essere '1' o '2' o '3', riprova\n"KYEL"$ ");
                        }
                }while(c != 1 && c != 2 && c != 3);
                int b = false;
                ins_cunicolo(c, b);
                //head_hartornen->scelta[counter] = c;
                counter++;
                if(counter_h == 10 && counter_a == 10){
                    counter = 1;
                }
                }
        break;
        case 2:{
            printf(KGRN"\t\t\tecco i cunicoli creati per la famiglia arvais con le loro rispettive quantita di melassa\n");
            stampa_cunicolo(head_arvais);
            char c;
            printf(KBLU"\tper vedere i cunicoli della famiglia hartornen premere il tasto invio\n"KYEL"$");
            scanf("%c", &c);
            if(c == '\n'){
                printf(KGRN"\t\t\tecco i cunicoli creati per la famiglia hartornen con le loro rispettive quantita di melassa\n");
                stampa_cunicolo(head_hartornen);
            }
            //*check  = 1;
            }
        break;
        case 3:{
             canc_caverna(head_arvais, last_hartornen, t);
            }
        break;
        case 4:{
            if(counter == 1){
             printf("chiudi cunicolo\n");   
            }else{
                if(r <= 50)
                    printf(KRED"non sono state creati tutti i cunicoli!\n");
                else
                    printf(KRED"ricordati che i cunicoli per entrambe le famiglie devono essere dieci!\n");
            }
            
            }
        }
    }while(choice !=3);
}

//main menu pre cambiamneto

static void crea_cunicolo(){
    int choice = 0;
    do{
        clear;
        printf(KMAG"--------MAP-CREATION-MENU-------\n");
        printf(KNRM"\t"KRED"1-"KBLU" INSERISCI CUNICOLO\n\t"KRED"2-"KBLU" STAMPA CUNICOLO\n\t"KRED"3-"KBLU" ELIMINA CUNICOLO\n\t"KRED"4-"KBLU" RITORNA AL MAIN MENU\n"KYEL"$ ");
        scanf("%d", &choice);
        switch(choice){
        case 1:{ 
            clear;
            int counter = 1;
            printf(KGRN"i cunicoli per entrambe le famiglie saranno dieci\n");
            do{
                printf(KGRN"\nfaccciamo i cunicoli per la famiglia Arvais:\ndove vuoi inserire il %d cunicolo?\n", counter);
                printf(KNRM"\t"KRED"1-"KBLU" AVANTI\n\t"KRED"2-"KBLU" SINISTRA\n\t"KRED"3-"KBLU" DESTRA\n");                
                printf(KYEL"$ ");
                int c;
                do{
                    scanf("%d", &c);
                    if(c != 1 && c != 2 && c != 3)
                        if(r <= 50){
                            printf(KRED"input sbagliato, riprova\n"KYEL"$ ");
                        }else{
                            printf(KRED"gli input devono essere '1' o '2' o '3'\n"KYEL"$ ");
                        }
                }while(c != 1 && c != 2 && c != 3);
                bool b = true;
                ins_cunicolo(c, b);
                //head_arvais->scelta[counter] = c;
                counter++;
            }while(counter <= 10);
            counter = 1;
            clear;
            do{
                
                printf(KGRN"\nfaccciamo i cunicoli per la famiglia Hartornen:\ndove vuoi inserire il %d cunicolo?\n", counter);
                printf(KNRM"\t"KRED"1-"KBLU" AVANTI\n\t"KRED"2-"KBLU" SINISTRA\n\t"KRED"3-"KBLU" DESTRA\n"); 
                printf(KYEL"$ ");
                int c;
                do{
                    scanf("%d", &c);
                    if(c != 1 && c != 2 && c != 3)
                        if(r <= 50){
                            printf(KRED"input sbagliato, riprova\n"KYEL"$ "); 
                        }else{
                            printf(KRED"gli input devono essere '1' o '2' o '3', riprova\n"KYEL"$ ");
                        }
                }while(c != 1 && c != 2 && c != 3);
                int b = false;
                ins_cunicolo(c, b);
                //head_hartornen->scelta[counter] = c;
                counter++;
            }while(counter <= 10);
            control = 1;
            }
        break;
        case 2:{
            printf(KGRN"\t\t\tecco i cunicoli creati per la famiglia arvais con le loro rispettive quantita di melassa\n");
            stampa_cunicolo(head_arvais);
            char c;
            printf(KBLU"\tper vedere i cunicoli della famiglia hartornen premere il tasto invio\n"KYEL"$");
            scanf("%c", &c);
            if(c == '\n'){
                printf(KGRN"\t\t\tecco i cunicoli creati per la famiglia hartornen con le loro rispettive quantita di melassa\n");
                stampa_cunicolo(head_hartornen);
            }
            //*check  = 1;
            }
        break;
        case 3:{
             canc_caverna(head_arvais, last_hartornen, t);
            }
        break;
        case 4:{
            choice =chiudi_cunicolo();
            printf("chiudi cunicolo\n");
            }
        }
    }while(choice !=3);
}