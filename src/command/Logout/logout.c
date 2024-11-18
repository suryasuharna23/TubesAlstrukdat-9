#include <stdio.h>
#include <string.h>
#include "logout.h"

char loggedInUser[50] = ""; 

void logoutUser() {
    if (strlen(loggedInUser) == 0) {
        printf("Anda belum login.\n");
        return;
    }
    
    printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", loggedInUser);
    strcpy(loggedInUser, "");
}