#ifndef LISTLINIER_H
#define LISTLINIER_H

#include "../../Boolean/boolean.h"
#include "../mesin/mesinkata.h"

#define Nol NULL

typedef char* infotypes;
typedef struct tElmtlist *address_list;
typedef struct tElmtlist { 
    infotypes info;
    address_list next;
} ElmtList;
typedef struct {
    address_list First;
} List;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

boolean IsEmptyList(List L);
void CreateEmptyList(List *L);
void PrintInfo(List L);
address_list Alokasi(infotypes X);
void Dealokasi(address_list *P);
address_list Search(List L, infotypes X);
void InsVLast(List *L, infotypes X);
void DelP(List *L, infotypes X);
void DelVFirst(List *L, infotypes *X);
int NbElmt(List L);
infotypes Max(List L);
address_list AdrMax(List L);
infotypes Min(List L);
void InversList(List *L);
void Konkat1(List *L1, List *L2, List *L3);
void InsertLast(List *L, address_list P);

#endif