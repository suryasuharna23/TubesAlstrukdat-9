#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"
#include "logout.h"

User users[100];
int userCount = 0;

void loginUser() {
    if (strlen(loggedInUser) > 0) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", loggedInUser);
        return;
    }

    char username[50], password[50];
    
    printf("Username: "); //input username
    scanf("%s", username);
    
    printf("Password: "); //input password
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            strcpy(loggedInUser, username);
            printf("Anda telah login ke PURRMART sebagai %s.\n", username);
            return;
        }
    }
    
    printf("Username atau password salah.\n");
}

int main() {
    strcpy(users[userCount].username, "johndoe");
    strcpy(users[userCount++].password, "janedoe");

    loginUser();
    loginUser(); 
    logoutUser();
    loginUser(); 

    return 0;
}