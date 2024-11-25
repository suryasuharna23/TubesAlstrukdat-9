#include <stdio.h>
#include "quit.h"

void Quit(boolean *isRunning) {
    Word response;

    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? ");
    STARTINPUTWORD();
    response = GetWord(CurrentWord, 1);

    char *stringresponse = WordToString(response);

    if (*stringresponse == 'Y' || *stringresponse == 'y') {
        Word filenameWord;
        ArrayDinUser listuserFDD;
        listBarang liststoreFDD;

        printf("Masukkan nama file untuk menyimpan: ");
        STARTINPUTWORD();
        filenameWord = GetWord(CurrentWord, 1);
        char *filename =WordToString(filenameWord);
        save(filename, &listuserFDD, &liststoreFDD);

    } else if (*stringresponse == 'N' || *stringresponse == 'n') {
        printf("Program akan keluar tanpa menyimpan.\n");
    } else {
        printf("Kamu keluar dari PURRMART.\n");
        printf("Dadah ^_^/\n");
    }

    *isRunning = 0;
}