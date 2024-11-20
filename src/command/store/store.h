#ifndef __STORE_H__
#define __STORE_H__


#include "../../ADT/Mesin/boolean.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Queue/queue.h"

void SList(ArrayDinStore listStore); //menampilkan barang di list store

void SRemove (ArrayDinStore *listStore); //mengahpus barang dari list store

void SRequest(ArrayDinStore *listStore, Queue *requestQueue); //meminta barang ke list store

#endif