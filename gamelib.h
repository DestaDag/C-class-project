/*
    DESTA DAGIM AYENEW
    MATRICOLA: 314650
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>

//define macros
#define pause  sleep(2)
#define clear  printf("\e[1;1H\e[2J")
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

enum Tipo_imprevisto {
    nessun_imprevisto,
    crollo,
    baco,
};

enum Quantita_melassa{
    nessuna,
    poca,
    molta = 3,
};

enum Tipo_caverna{
    normale, 
    speciale,
    accidentata,
    uscita,
};

typedef enum Tipo_imprevisto Ti_t;
typedef enum Quantita_melassa Qm_t;
typedef enum Tipo_caverna Tp_t;

struct Caverna{
    struct Caverna *avanti;
    struct Caverna *sinistra;
    struct Caverna *destra;
    Qm_t melassa;
    Tp_t  stato;
    Ti_t imprevisto;  
};

struct Scavatrice{
    struct Caverna* position;
    int energia;
    int raccolta;
    int ammo;
};

typedef struct Caverna Cave_t;
typedef struct Scavatrice Scava_t;

int MainMenu(int check);
int termina_gioco(Scava_t player1, Scava_t player2);
int gioca();