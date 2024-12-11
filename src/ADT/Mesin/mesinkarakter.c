#include <stdio.h>
#include "mesinkarakter.h"

char CurrentChar; // Deklarasi dan definisi
boolean EOP;

static FILE *pita;
static int retval; 

void START(char *FILE) {
    if (FILE != NULL) {
        pita = fopen(FILE, "r");
        if (pita == NULL) {
            printf("File gagal dibuka '%s'.\n", FILE);
            EOP = true;
            return;
        }
    } else {
        pita = stdin;
    }
    ADV();
}

void ADV() {
    retval = fscanf(pita, "%c", &CurrentChar);
    if (retval == EOF) {
        EOP = true;
    } else {
        EOP = (CurrentChar == MARK);
    }
    if (EOP) {
        fclose(pita);
    }
}

char GetCC() {
    return CurrentChar;
}

boolean IsEOP() {
    return EOP;
}

void ADVIgnoreNL() {
    int result = fscanf(pita, "%c", &CurrentChar);
    EOP = (result == EOF);
    if (EOP) {
        fclose(pita);
    }
}

