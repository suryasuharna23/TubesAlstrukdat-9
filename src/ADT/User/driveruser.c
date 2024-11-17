#include <stdio.h>
#include "user.h"
#include "user.c"

int main() {
    // Contoh penggunaan
    User user1;
    User user2;
    User user3;
    CreateUser(&user1, "surya", "securepass", 500);
    CreateUser(&user2, "suharna", "securepass", 500);
    CreateUser(&user3, "surya suharna", "securepass", 500);

    printf("User created successfully:\n");
    PrintUser(&user2); //ngecek

    return 0;
}
