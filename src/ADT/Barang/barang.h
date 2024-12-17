#ifndef BARANG_H
#define BARANG_H
#define MAX_LEN 50

#include "../../Boolean/boolean.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"

typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

typedef struct {
    Barang items[MAX_LEN];
    int count;
} ListBarang;

extern ListBarang listbarang;

void CreateListBarang(ListBarang *list); 
int CountBarang(ListBarang *listbarang);
int IndexBarang(ListBarang *listbarang, char *name);
void AddBarang(ListBarang *list, char *name, int price);
void TakeBarang(ListBarang *listbarang, char *name);
boolean IsBarangExist(ListBarang *listbarang, char *name);
boolean IsEmptyListBarang(ListBarang list);
void PrintBarang(Barang *barang);
boolean StringCompare(const char *str1, const char *str2);
int GetBarangPrice(ListBarang listbarang, char *name);

#endif /* BARANG_H */