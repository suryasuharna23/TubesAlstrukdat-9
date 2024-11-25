#ifndef LOAD_H
#define LOAD_H

#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/User/user.h"


// Definisi Konstanta
#define MAX_NAME 50
#define MAX_PASSWORD 50

void LOAD(const char *filename, ArrayDinStore *store, ArrayDinUser *userList);

#endif
