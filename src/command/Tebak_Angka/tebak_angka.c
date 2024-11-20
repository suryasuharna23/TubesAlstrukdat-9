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

    int digit = (randomNumber(3) % 3) + 1;
    int key_value = randomNumber(3) % (int)(pow(10, digit));

    boolean win = false;

    while (try > 0 && !win){
        int value;

        printf("Tebak angka: ");
        value = readInt();

        if (value < key_value){
            printf("Tebakanmu lebih kecil!\n");
            printf("(kesempatanmu %d kali lagi untuk mencoba)\n", (try-1));
        } else if (value > key_value){
            printf("Tebakanmu lebih besar!\n");
            printf("(kesempatanmu %d kali lagi untuk mencoba)\n", (try-1));
        } else {
            printf("Tebakanmu benar!");
            int poin = score(75, try);
            printf(" +%d rupiah telah ditambahkan ke akun anda.\n", poin);
            win = true;
        }
        try--;
    }

    if (!win){
        printf("Anda kalah.\n");
        printf("Angkamu yang benar adalah %d", key_value);
    }
}
