#include <stdio.h>
#include <math.h>
#include "tebak_angka.h"

int readInt(){
    int result = 0;

    STARTINPUTWORD();

    for (int i = 0; i < CurrentWord.Length; i++){
        if (CurrentWord.TabWord[i] >= '0' && CurrentWord.TabWord[i] <= '9'){
            result = result * 10 + (CurrentWord.TabWord[i] - '0');
        }
    }

    return result;
}

void tebak_angka(){
    int try = MAX_TRIES;

    int digit = (randomNumber(10) % 3) + 1;
    int key_value = randomNumber(10) % (int)(pow(10, digit));

    boolean win = false;

    while (try > 0 && !win){
        int value;

        printf("Tebak angka: ");
        value = readInt();

        if (value < key_value){
            printf("Tebakanmu lebih kecil!\n");
        } else if (value > key_value){
            printf("Tebakanmu lebih besar!\n");
        } else {
            printf("Tebakanmu benar!");
            int score = try * 75;
            printf(" +%d rupiah telah ditambahkan ke akun anda.\n", score);
            win = true;
        }
        try--;
    }

    if (!win){
        printf("Anda kalah.\n");
    }
}
