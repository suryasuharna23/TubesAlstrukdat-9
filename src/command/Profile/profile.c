#include <stdio.h>
#include "profile.h"
#include "../../ADT/User/user.h"
#include "../../ADT/Mesin/mesinkata.h"

void Profile(User *CurrentUser) {
    if (CurrentUser->name[0] == '\0') {
        printf("Tidak ada pengguna yang sedang login.\n");
    } else {
        printf("\n+----------------------------------------+\n");
        printf("|             Profil Pengguna            |\n");
        printf("+----------------------------------------+\n");
        printf("| Nama  : %-30s |\n", CurrentUser->name);
        printf("| Saldo : %-30d |\n", CurrentUser->money);
        printf("+----------------------------------------+\n");
    }

    while (1) {
        printf("Ketik 'BACK' untuk kembali: \n");
        printf(">>> ");
        STARTINPUTWORD();

        if (isEqual(CurrentWord, "BACK")) {
            break;
        } else {
            printf("Input tidak valid. \n");
        }
    }
}