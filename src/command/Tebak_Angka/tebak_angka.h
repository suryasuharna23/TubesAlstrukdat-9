#ifndef __TEBAK_ANGKA_H__
#define __TEBAK_ANGKA_H__

#include "../../Boolean/boolean.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../command/Random_Number/random_number.h"
#include "../../command/Score/score.h"

#define MAX_TRIES 10

int getInt();
// membaca masukan kata sebagai integer

int tebak_angka();
// program challenge tebak angka

#endif