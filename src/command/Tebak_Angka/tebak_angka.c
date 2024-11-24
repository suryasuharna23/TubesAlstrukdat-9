#include <stdio.h>
#include <math.h>
#include "tebak_angka.h"

int getInt(){
    int result = 0;

    STARTINPUTWORD();
    Word num = CurrentWord;

    return WordToInt(num);
}

int tebak_angka(){
    int try = MAX_TRIES;
    int poin = 0; //score pemain

    int digit = (randomNumber(3) % 3) + 1;
    int key_value = randomNumber(3) % (int)(pow(10, digit));

    boolean win = false;

    while (try > 0 && !win){
        int value;

        printf("Tebak angka: ");
        value = getInt();

        if (value < key_value){
            printf("Tebakanmu lebih kecil!\n");
            printf("(kesempatanmu %d kali lagi untuk mencoba)\n", (try-1));
        } else if (value > key_value){
            printf("Tebakanmu lebih besar!\n");
            printf("(kesempatanmu %d kali lagi untuk mencoba)\n", (try-1));
        } else {
            printf("Tebakanmu benar!");
            poin = score(75, try);
            printf(" +%d rupiah telah ditambahkan ke akun anda.\n", poin);
            win = true;
        }
        try--;
    }

    if (!win){
        printf("Yahh kamu kalah \\(>A<)/\n");
        printf("Angkamu yang benar adalah %d", key_value);
    }

    return poin;
}
