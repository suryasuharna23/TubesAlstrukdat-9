#include <stdio.h>

void Quit(int *isRunning) {
    char response;

    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    scanf(" %c", &response);

    if (response == 'Y' || response == 'y') {
        // ke save
    } else if (response == 'N' || response == 'n') {
        printf("Program akan keluar tanpa menyimpan.\n");
    } else {
        printf("Kamu keluar dari PURRMART.\n");
        printf("Dadah ^_^/\n");
    }

    *isRunning = 0;
}