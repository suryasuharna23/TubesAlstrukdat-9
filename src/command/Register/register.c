#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "register.h"
#include "login.h"

void registerUser() {
    User newUser;
    
    printf("Username: "); // input username
    scanf("%s", newUser.username);
    
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", newUser.username);
            return;
        }
    }

    printf("Password: "); // input password
    scanf("%s", newUser.password);
    
    users[userCount++] = newUser;
    
    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", newUser.username);
}

int main() {
    registerUser(); 
    
    return 0;
}