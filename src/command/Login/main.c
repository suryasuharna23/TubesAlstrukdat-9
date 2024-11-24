#include <stdio.h>
#include "../User/user.h"
#include "login.h"

int main() {
    // Inisialisasi data pengguna
    ListUser users;
    users.count = 2;

    // Pengguna 1
    snprintf(users.users[0].name, MAX_LEN, "admin");
    snprintf(users.users[0].password, MAX_LEN, "alstrukdat");
    users.users[0].money = 1000;

    // Pengguna 2
    snprintf(users.users[1].name, MAX_LEN, "user");
    snprintf(users.users[1].password, MAX_LEN, "password");
    users.users[1].money = 500;

    // Variabel untuk pengguna yang sedang login
    char currentUser[MAX_LEN] = "";

    // Proses login
    Login(&users, currentUser);

    return 0;
}
