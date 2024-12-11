/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../../Boolean/boolean.h"

#define MARK '.'
#define BLANK ' '
#define LN '\n'

/* State Mesin */
extern char CurrentChar;
extern boolean EOP;

void START(char *FILE);
// void STARTINPUT();
void ADV();
char GetCC();
boolean IsEOP();
void ADVIgnoreNL();

#endif