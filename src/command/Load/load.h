#ifndef LOAD_H
#define LOAD_H

#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/User/user.h"

boolean Load(char *filename);

extern ListUser users;
extern ListBarang barangs;

#endif
