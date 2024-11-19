#include "mesinkata.h"
//#include "mesinkarakter.h"
#include <stdio.h>

int main(){
    
    char *file = "teks.txt";

    printf("----TES MESIN KATA----\n");

    printf("Tes START dari file\n");
    STARTWORD(file);
    while (!EndWord) {
        PrintCurrentWord();
        ADVWORD();
    }

    printf("Tes START dari INPUT\n");
    STARTINPUTWORD();
    PrintCurrentWord();

    return 0;
}