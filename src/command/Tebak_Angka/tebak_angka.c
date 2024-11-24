#include <stdio.h>
#include <math.h>
#include "tebak_angka.h"

int getInt(){
    int result = 0;

    STARTINPUTWORD();
    Word num = CurrentWord;

    return WordToInt(num); // mengubah word menjadi integer
}

void tebak_angka(){
    int try = MAX_TRIES;

    int digit = (randomNumber(3) % 3) + 1; // menentukan banyaknya digit angka akan ditebak
    int key_value = randomNumber(3) % (int)(pow(10, digit)); // merandom bilangan yang akan ditebak

    boolean win = false;

    while (try > 0 && !win){
        int value;
        
        // menerima masukan angka tebakam
        printf("Tebak angka: ");
        value = getInt();

        if (value < key_value){ // kalau nilai yang ditebak lebih kecil dari nilai sebenarnya
            printf("Tebakanmu lebih kecil!\n");
            printf("(kesempatanmu %d kali lagi untuk mencoba)\n", (try-1));
        } else if (value > key_value){ // kalau nilai yang ditebak lebih besar dari nilai sebenarnya
            printf("Tebakanmu lebih besar!\n");
            printf("(kesempatanmu %d kali lagi untuk mencoba)\n", (try-1));
        } else { // kalau nilai yang ditebak sama dengan nilai sebenarnya
            printf("Tebakanmu benar!");
            int poin = score(75, try);
            printf(" +%d rupiah telah ditambahkan ke akun anda.\n", poin);
            win = true;
        }
        try--;
    }

    if (!win){ // kalau kalah
        printf("Yahh kamu kalah \\(>A<)/\n");
        printf("Angkamu yang benar adalah %d", key_value);
    }
}
