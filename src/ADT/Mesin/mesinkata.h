/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../../Boolean/boolean.h"
#include "mesinkarakter.h"

#define NMax 50
#define BLANK '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word CurrentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(char *FILE);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
         atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTINPUTWORD();
/* I.S : currentChar adalah karakter pertama kata yang akan diakuisisi
 * F.S : currentWord adalah kata terakhir yang sudah diakuisisi,
 *		 currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
 *		 Jika currentChar = MARK, EndWord = true.
 * Proses : Akuisisi kata menggunakan procedure CopyWord */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
         currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
         Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
         currentChar = BLANK atau currentChar = MARK;
         currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void PrintCurrentWord();
/* Mencetak kata yang tersimpan dalam CurrentWord
   I.S:  CurrentWord berisi kata yang sudah diakuisisi
   F.S:  semua karakter dalam CurrentWord tercetak sesuai urutan*/

Word GetWord (Word w1, int a);
// ngambil kata ke-a

boolean isEqual(Word w, const char *c);
// memeriksa apakah kata yang di-input atau difolder itu sama dengan di parameter


// CONVERT //

char * WordToString (Word word);
// mengubah tipe data word ke string

int WordToInt(Word word);
// mengubah tipe data word ke integer

Word StringtoWord (char*string);
// mengubah tipe data string ke word



boolean WordCompare(const char *str1, const char *str2);
// membandingkan dua kata


#endif