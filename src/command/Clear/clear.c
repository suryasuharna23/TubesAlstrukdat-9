#include <stdio.h>
#include <stdlib.h>

void clear() {
#ifdef _WIN32
    system("cls");  // Untuk Windows, menggunakan perintah cls
#else
    system("clear"); // Untuk Linux/macOS, menggunakan perintah clear
#endif
}
