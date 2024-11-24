#ifndef __WORLD3_H__
#define __WORLD3_H__

#include "../../Boolean/boolean.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../command/Random_Number/random_number.h"
#include "../../command/Score/score.h"

#define MAX_PLAYS 6

void READLINE(char *filename, int lineIDX);
// membaca kata pada baris tertentu

int wordl3_challenge();
// memulai Work Challenge WORLD3

void saveChar(char flag, char letter, boolean isLast);
// menyimpan hasil tebakan

void clearHist(char *filename);
// membersihkan history tebakan dari game sebelumnya setiap game baru dimulai

#endif