#ifndef LOGIN_H
#define LOGIN_H

#include "boolean.h"
#include "../User/user.h"

#define MAX_LEN 100

// Fungsi untuk melakukan proses login
void Login(ListUser *users, char *currentUser);

#endif // LOGIN_H