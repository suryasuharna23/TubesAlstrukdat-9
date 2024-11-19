#include <stdio.h>
#include "load.h"

int main() {
    char filename[MAX_NAME];
    char c;
    int i = 0;

    printf("Masukkan nama file yang ingin dimuat (contoh: savefile.txt): ");
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < MAX_NAME - 1) {
            filename[i] = c;
            i++;
        }
    }
    filename[i] = '\0'; // Null-terminator untuk mengakhiri string

    loadFile(filename);
    return 0;
}
