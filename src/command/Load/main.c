#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/User/user.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "load.h"

ListBarang listbarang; // Deklarasi dan definisi
ListUser users; // Deklarasi dan definisi

int StringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void RemoveNewline(char *str) {
    int length = StringLength(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

int main() {
    char filename[MAX_LEN];

    // Initialize the lists
    CreateListUser(&users);
    CreateListBarang(&listbarang);

    // Prompt user for filename
    printf("Enter the configuration file name (or press Enter to use default): ");
    fgets(filename, MAX_LEN, stdin);

    // Remove newline character from filename
    RemoveNewline(filename);

    // Debugging: Print the filename being passed to Load
    printf("Filename: %s\n", filename);

    // Load data from the specified file or default file
    printf("Loading data...\n");
    Load(StringLength(filename) > 0 ? filename : NULL);
    printf("Data loaded.\n");

    printf("Barang List:\n");
    for (int i = 0; i < listbarang.count; i++) {
        printf("Barang %d: %s, Harga: %d\n", i + 1, listbarang.items[i].name, listbarang.items[i].price);
    }

    printf("\nUser List:\n");
    for (int i = 0; i < users.count; i++) {
        printf("Username: %s, Password: %s, Money: %d\n", users.users[i].name, users.users[i].password, users.users[i].money);
    }

    return 0;
}