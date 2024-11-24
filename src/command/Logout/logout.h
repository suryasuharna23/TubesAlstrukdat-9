#ifndef LOGOUT_H
#define LOGOUT_H

#include "../../ADT/Mesin/boolean.h"

// Struktur data untuk User
typedef struct
{
    char name[50];
    char password[50];
    int money;
    boolean is_logged_in; // Menyimpan status login pengguna
} User;

// Fungsi LOGOUT
void logout(User *current_user);
#endif