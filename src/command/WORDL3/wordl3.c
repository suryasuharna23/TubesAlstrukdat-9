#include <stdio.h>
#include <stdlib.h>
#include "wordl3.h"

void READLINE(char *filename, int IdxLine){
    START(filename);
    // printf("[DEBUG] readline 1");
    int currentLine = 0;

    while ((currentLine < IdxLine) && (!IsEOP())){
        // printf("[DEBUG] readline 2");
        while ((CurrentChar != '\n') && (!IsEOP())){
            // printf("[DEBUG] readline 3");
            ADV();
        }
        if (CurrentChar == '\n'){
            ADV();
        }
        currentLine++;
    }

    IgnoreBlanks();
    if (!IsEOP()){
        CopyWord();
        EndWord = false;
    } else {
        EndWord = true;
    }
}

void wordl3_challenge(User *user){
    int try = MAX_PLAYS; // banyak kesempatan mencoba
    boolean win = false; // menentukan apakah pemain menang atau kalah
    char flag;
    int poin = 0; //score pemain

    if (user->money < 500){
        printf("Saldo kamu kurang nih!\n");
        return;
    }
    else {
        user->money -= 500; // mengurangi uang user untuk bermain
    }
    // printf("[DEBUG] wordl3 1");

    // implementasi random number untuk menentukan keyword dan poin secara acak
    int line = randomNumber(3) % 100;
    
    // mengambil keyword
    char *keyword = "../src/command/WORDL3/word_list.txt";

    READLINE(keyword, line);
    // printf("[DEBUG] wordl3 2");
    Word key_word = CurrentWord;

    char *history = "../src/command/WORDL3/history.txt";
    clearHist(history);
    // printf("[DEBUG] wordl3 3");

    printf("WELCOME TO W0RDL3, YOU HAVE 5 CHANCES TO ANSWER BEFORE YOU LOSE!\n");

    while (try > 0 && !win){
        if (user == NULL) {
            printf("Error: User tidak diinisialisasi!\n");
            return;
        }
        // printf("[DEBUG] wordl3 4");
        int isLast = false;

        // print kata yang ada di file history, alias kata-kata hasil tebakan sebelumnya
        START(history); // Memulai pembacaan file
        while (!IsEOP()) { // Selama belum mencapai akhir file
            while (CurrentChar != '\n' && !IsEOP()) {
                printf("%c", CurrentChar); // Cetak karakter
                ADV(); // Lanjutkan ke karakter berikutnya
            }
            printf("\n"); // Pindah baris setelah mencapai '\n'
            if (!IsEOP()) {
                ADV(); // Lewati karakter '\n' jika bukan akhir file
            }
        }

        // ngeprint si karakter kosong, tiap nyobain bakal berkurang jumlah barisnya
        for (int i = 0; i < try; i++){
            printf("_ _ _ _ _\n");
        }
    
        // menerima input kata yang ditebak
        printf("Masukkan kata tebakan Anda: ");
        STARTINPUTWORD();
        Word word = CurrentWord;

        if (word.Length != 5){ // kalau panjang katanya ga sesuai
            printf("Panjang kata tidak sesuai\n");
        } else { // kalau sesuai
            boolean checked[key_word.Length];
            for (int i = 0; i < key_word.Length; i++){
                checked[i] = false;
            }

            printf("Hasil: \n");
            for (int i = 0; i < word.Length; i++){ // memanggil karakter dari kata pada yang ditebak
                boolean match = false; // menentukan karakter yang sama
                if (i == word.Length - 1){
                    isLast = true;
                }

                // mengecek tiap karakter dari input kata yang ditebak dengan keyword yang terpilih acak
                for (int j = 0; j < key_word.Length; j++){
                    if ((word.TabWord[i] == key_word.TabWord[j]) && (checked[j] == false)) { 
                        if ((i == j)){ // kalau karakter ada dan pada posisi yang sama
                            flag = ' ';
                            saveChar(flag, word.TabWord[i], isLast);
                            checked[j] = true; // checked menjadi true, berarti karakter pada indeks j dalam kata key_word nantinya tidak perlu dicek lagi
                            match = true; // karakter yang sama ditemukan
                            break; // pengecekan berhenti dan berpindah ke karakter berikutnya
                        } else if (i != j){ // kalau karakter ada, tetapi beda posisi
                            flag = '*';
                            saveChar(flag, word.TabWord[i], isLast);
                            checked[j] = true;
                            match = true; // karakter yang sama ditemukan
                            break; // pengecekan berhenti dan berpindah ke karakter berikutnya
                        }
                    } 
                }
                        
                if (!match){ // jika karakter dari kata yang ditebak tidak ada pada keyword
                    flag = '%';
                    saveChar(flag, word.TabWord[i], isLast);
                }
            }

            char *keyString = WordToString(key_word);
            char *wordString = WordToString(word);

            // kalau katanya sama, pemain menang, dan pengecekan berhenti
            if (WordCompare(keyString, wordString)){
                win = true; // kalau pemain menang, win bernilai true, program berhenti
                START(history); // Memulai pembacaan file
                while (!IsEOP()) { // Selama belum mencapai akhir file
                    while (CurrentChar != '\n' && !IsEOP()) {
                        printf("%c", CurrentChar); // Cetak karakter
                        ADV(); // Lanjutkan ke karakter berikutnya
                    }
                    printf("\n"); // Pindah baris setelah mencapai '\n'
                    if (!IsEOP()) {
                        ADV(); // Lewati karakter '\n' jika bukan akhir file
                    }
                }
                printf("Selamat anda menang!\n");
                poin = score(150, try) % 1000;
                printf("+%d rupiah telah ditambahkan ke akun Anda.\n", poin);
                user->money += poin;
            }

            free(keyString);
            free(wordString);
        }
        // banyak kesempatan mencoba berkurang
        try--;
    }

    if (!win){ // kalau pemain kalah, program berhenti
        START(history); // Memulai pembacaan file
        while (!IsEOP()) { // Selama belum mencapai akhir file
            while (CurrentChar != '\n' && !IsEOP()) {
                printf("%c", CurrentChar); // Cetak karakter
                ADV(); // Lanjutkan ke karakter berikutnya
            }
            printf("\n"); // Pindah baris setelah mencapai '\n'
            if (!IsEOP()) {
                ADV(); // Lewati karakter '\n' jika bukan akhir file
            }
        }
        printf("Boo! kamu kalah 'v(- o -)v'\n");
        READLINE(keyword, line);
        printf("Kata yang benar adalah ");
        PrintCurrentWord();
    }
    printf("-------------------------------------------------\n");
    // printf("Poin yang diperoleh: %d\n", poin);
    printf("Total uang Anda sekarang: %d\n", user->money);

    for (int i = 0; i < users.count; i++) {
        if (WordCompare(users.users[i].name, user->name)) {
            users.users[i].money = user->money;
            break;
        }
    }
    printf("Apakah kamu ingin bermain lagi? (YES/BACK)\n");
    printf(">>> ");
    STARTINPUTWORD();
    char *response = WordToString(CurrentWord);
    if (WordCompare(response, "YES"))
    {
        wordl3_challenge(user);
    }
    else if (WordCompare(response, "BACK"))
    {
        return;
    }
    else
    {
        printf("Input tidak valid.\n");
    }
}

void saveChar(char flag, char letter, boolean isLast){
    FILE *history;
    // printf("[DEBUG] savechar 1");

    history = fopen("../src/command/WORDL3/history.txt", "a"); //  membuka file history tebakan kata

    // masukin karaketr ke file history
    fputc(letter, history);

    if (flag != ' '){ // kalau karakter benar di posisi benar, flagnya ' ', jadi untuk selain itu, bakal dikasih ' ' setelah flagnya
        fputc(flag, history);
    }
    fputc(' ', history);

    if (isLast){ // kalau udah karakter terakhir, ganti baris
        fputc('\n', history);
    }

    fclose(history); // close file
}

void clearHist(char *filename){
    STARTWORD(filename);
    // printf("[DEBUG] sclerhist 1");

    FILE *clear_hist = fopen("../src/command/WORDL3/history.txt", "w");
    fclose(clear_hist);
}

/*
int main(){
    User user; 

    wordl3_challenge(&user);
    return 0;
}*/