#ifndef LOAD_H
#define LOAD_H

#include "../../src/ADT/Mesin/mesinkarakter.h"
#include "../../src/ADT/Mesin/mesinkata.h"

// Definisi Konstanta
#define MAX_NAME 50
#define MAX_PASSWORD 50

// Fungsi untuk memuat file konfigurasi
void loadFile(char *filename);

// Fungsi konversi Word ke integer
int wordToInt(Word word);

// Fungsi konversi Word ke array karakter
void wordToCharArray(Word word, char *str);

#endif
