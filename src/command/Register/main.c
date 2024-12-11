#include <stdio.h>
#include "../../ADT/User/user.h"
#include "../../ADT/Barang/barang.h"
#include "register.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../Load/load.h"
#include "../Save/save.h"

ListBarang listbarang; // Deklarasi dan definisi
ListUser users; // Deklarasi dan definisi

int main() {
    boolean flag = false;
    char filename[100];

    // Initialize user list
    CreateListUser(&users);

    // Prompt user for filename
    printf("Enter the filename to load users from: ");
    scanf("%s", filename);

    // Load users from configuration file
    Load(filename);

    // Register a new user
    RegisterUser(&users, &flag);

    // Save updated user list to configuration file
    printf("Enter the filename to save users to: ");
    Save();

    if (flag) {
        printf("User registration successful and saved.\n");
    } else {
        printf("User registration failed.\n");
    }

    return 0;
}