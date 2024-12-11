#ifndef MAP_H
#define MAP_H
#include <stdio.h>
#include "boolean.h"

#define Nil 0
#define MaxElMap 10
#define Undefined -999

typedef int keytype;
typedef int valuetype;
typedef int address;

typedef struct {
    keytype Key;
    valuetype Value;
} infotype;

typedef struct {
    infotype Elements[MaxElMap];
    address Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */

void CreateEmpty(Map *M);
boolean IsEmpty(Map M);
boolean IsFull(Map M);
valuetype Value(Map M, keytype k);
void Insert(Map *M, keytype k, valuetype v);
void Delete(Map *M, keytype k);
boolean IsMember(Map M, keytype k);

#endif