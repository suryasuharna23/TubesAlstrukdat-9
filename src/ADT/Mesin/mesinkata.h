/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "mesinkarakter.h"
#include "../../Boolean/boolean.h"

#define NMax 50
#define BLANK ' '
#define NL '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word CurrentWord;

void IgnoreBlanks();
void STARTWORD(char *FILE);
void STARTINPUTWORD();
void ADVWORD();
void ADVSENTENCE();
void CopyWord();
void PrintCurrentWord();
Word GetWord (Word w1, int a);
// ngambil kata ke-a
Word GetSentence(Word w1, int idx);
boolean isEqual(Word w, const char *c);
// memeriksa apakah kata yang di-input atau difolder itu sama dengan di parameter
// CONVERT //
char * WordToString (Word word);
// mengubah tipe data word ke string
int WordToInt(Word word);
// mengubah tipe data word ke integer
Word StringToWord (char*string);
// mengubah tipe data string ke word
boolean WordCompare(const char *str1, const char *str2);
// membandingkan dua kata
void GetLine();
//ambil satu line penuh hingga user enter
void StringCopy(char *str1, char *str2);
void StringConcat(char *str1, char *str2);
void STARTINPUT(); // Deklarasi
void ADVIgnoreLN(); // Deklarasi
boolean IsBlankExist(Word word); // Declaration
boolean IsLetterOrDigit(Word word); // Declaration
#endif