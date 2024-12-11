#include <stdio.h>
#include "../ADT/User/user.h"
#include "../ADT/Barang/barang.h"
#include "../ADT/Mesin/mesinkata.h"
#include "../ADT/Mesin/mesinkarakter.h"
#include "../Load/load.h"
#include "../Save/save.h"
#include "register.h"

void execute_command() {
    printf(">>> ");
    STARTINPUTWORD();
    Word command = CurrentWord;
    char commandStr[MAX_LEN];
    strcpy(commandStr, WordToString(command));
    upper_string(commandStr);

    if (isEqual(command, "HELP")) {
        help();
    } else if (isEqual(command, "LOAD")) {
        printf("Enter filename to load: ");
        STARTINPUTWORD();
        Load(WordToString(CurrentWord));
    } else if (isEqual(command, "START")) {
        start_command();
    } else if (isEqual(command, "LOGIN")) {
        handle_login();
    } else if (isEqual(command, "LOGOUT")) {
        handle_logout();
    } else if (isEqual(command, "REGISTER")) {
        boolean flag = false;
        RegisterUser(&users, &flag);
        if (flag) {
            printf("Pendaftaran pengguna berhasil.\n");
        } else {
            printf("Pendaftaran pengguna gagal.\n");
        }
    } else if (isEqual(command, "WORK")) {
        handle_work(&CurrentUser);
    } else if (isEqual(command, "WORK CHALLENGE")) {
        challenge();
    } else if (isEqual(command, "STORE REQUEST")) {
        store_request_main();
    } else if (isEqual(command, "STORE SUPPLY")) {
        store_supply_main();
    } else if (isEqual(command, "STORE REMOVE")) {
        store_remove_main();
    } else if (isEqual(command, "STORE LIST")) {
        store_list_main();
    } else if (isEqual(command, "SAVE")) {
        printf("Enter filename to save: ");
        STARTINPUTWORD();
        Save(WordToString(CurrentWord));
    } else if (isEqual(command, "QUIT")) {
        printf("Kamu keluar dari PURRMART.\n");
        quit();
    } else if (isEqual(command, "BIO WEAPON")) {
        bioweapon_main();
    } else {
        printf("Unknown command: %s\n", commandStr);
    }
    execute_command();
}

int main() {
    printf("___       __      ______                                       _____               ________ _____  __________ ________ ______  __________ ________ ________\n");
    printf("__ |     / /_____ ___  /_____________ _______ ___ _____        __  /_______        ___  __ \\__  / / /___  __ \\___  __ \\___   |/  /___    |___  __ \\___  __/\n");
    printf("__ | /| / / _  _ \\__  / _  ___/_  __ \\__  __ `__ \\_  _ \\       _  __/_  __ \\       __  /_/ /_  / / / __  /_/ /__  /_/ /__  /|_/ / __  /| |__  /_/ /__  /   \n");
    printf("__ | /| / / _  _ \\__  / _  ___/_  __ \\__  __ `__ \\_  _ \\       _  __/_  __ \\       __  /_/ /_  / / / __  /_/ /__  /_/ /__  /|_/ / __  /| |__  /_/ /__  /   \n");
    printf("__ |/ |/ /  /  __/_  /  / /__  / /_/ /_  / / / / //  __/       / /_  / /_/ /       _  ____/ / /_/ /  _  _, _/ _  _, _/ _  /  / /  _  ___ |_  _, _/ _  /    \n");
    printf("____/|__/   \\___/ /_/   \\___/  \\____/ /_/ /_/ /_/ \\___/        \\__/  \\____/        /_/      \\____/   /_/ |_|  /_/ |_|  /_/  /_/   /_/  |_|/_/ |_|  /_/     \n");
    printf("\n");
    printf("\n");
    printf("****************************************\n");
    printf("*      Selamat Datang di PURRMART      *\n");
    printf("****************************************\n");
    printf("*   1. START                           *\n");
    printf("*   2. LOAD                            *\n");
    printf("*   3. QUIT                            *\n");
    printf("****************************************\n");
    printf("*   Pilih Command atau ketik 'HELP'!   *\n");
    printf("****************************************\n");
    execute_command();
    return 0;
}