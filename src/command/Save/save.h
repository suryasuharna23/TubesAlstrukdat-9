#ifndef SAVE_H
#define SAVE_H

#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/User/user.h"

#define MAX_USER_COUNT 100
#define MAX_BARANG_COUNT 100

void Save(char *filename, ListBarang *listbarang, ListUser *users);

#endif