/**
 * @author DESTA DAGIM AYENEW
 * MATRCICOLA: 314650
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

//! debug srand(time(NULL));
/**
 * principal function called by main() that displays the main menu of the game
 * @param *check to exit loop and enter command line
*/
void MainMenu(int *check);
//! debug void termina_gioco();
//! debug void gioca();

#define KNRM  "\x1B[0m"
#define KYEL  "\x1B[33m"
#define KRED  "\x1B[31m"

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
    int scelta[10];
    Qm_t melassa;
    Tp_t  stato;  
};

struct Scavatrice{
    struct Caverna* position;
    int energia;
    int raccolta;
    

};

typedef struct Caverna Cave_t;
typedef struct Scavatrice Scava_t;


