#ifndef LOGIN_H
#define LOGIN_H

#include "../../Boolean/boolean.h"
#include "../../ADT/User/user.h"
#include "../../ADT/Mesin/mesinkata.h"

// fungsi untuk melakukan proses login
void Login(ListUser *users, User *CurrentUser, int *user_id);

#endif 