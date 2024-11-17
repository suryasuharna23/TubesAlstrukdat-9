#include "mesinkata.h"
#include <stdio.h>

int main(){
    
    STARTWORD();
    while (!EndWord) {
        PrintCurrentWord();
        printf("Panjang kata: %d\n", CurrentWord.Length);
        ADVWORD();
    }

    return 0;



}