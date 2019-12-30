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