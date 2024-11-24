#ifndef __STORE_H__
#define __STORE_H__

#include "../../Boolean/boolean.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Queue/queue.h"


void SList(ArrayDinStore *listStore); //menampilkan barang di list store

void SRemove (ArrayDinStore *listStore); //mengahpus barang dari list store

void SRequest(ArrayDinStore *listStore, Queue *req); //meminta barang ke list store

void SSupply(ArrayDinStore *listStore, Queue *req); //menambahkan barang ke list store dari store request

#endif