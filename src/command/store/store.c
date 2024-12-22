#include "store.h"
#include <stdio.h>
#include <stdlib.h>

void DisplayBarang(ListBarang *listbarang) {
    printf("+----+-----------------------------+-----------+\n");
    printf("| No | Nama Barang                 | Harga     |\n");
    printf("+----+-----------------------------+-----------+\n");

    for (int i = 0; i < listbarang->count; i++) {
        printf("| %-2d | %-27s | %-9d |\n", i + 1, listbarang->items[i].name, listbarang->items[i].price);
    }

    printf("+----+-----------------------------+-----------+\n");
}

int StringLength(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void ToLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32; 
        }
    }
}


void SList(ListBarang *listbarang) {
    while (1) {
        if (IsEmptyListBarang(*listbarang)) {
            printf("TOKO KOSONG\n");
        } else {
            DisplayBarang(listbarang);
        }

        printf("Ketik 'BACK' untuk kembali: \n");
        printf(">>> ");
        STARTINPUTWORD();

        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu utama.\n");
            break;
        } else {
            printf("Input tidak valid. \n");
        }
    }
}



void SRemove(ListBarang *listbarang) {
    char *rem_input;
    boolean barangExist = false;

    while (!barangExist) {
        printf("Daftar barang yang ada di toko:\n");
        DisplayBarang(listbarang);
        printf("Nama barang yang akan dihapus:\n");
        printf(">>> ");
        STARTINPUTWORD();
        rem_input = WordToString(CurrentWord);

        if (IsBarangExist(listbarang, rem_input)) {
            TakeBarang(listbarang, rem_input);
            printf("Barang %s berhasil dihapus.\n", rem_input);
            barangExist = true;
        } else if (isEqual(CurrentWord, "BACK")){
            printf("Kembali ke menu utama.\n");
            return;
        }
        else {
            printf("Toko tidak menjual %s. Silakan masukkan nama barang yang valid.\n", rem_input);
        }
    }

    while (1) {
        printf("Apakah kamu ingin menghapus barang lain? (YES/BACK): \n");
        printf(">>> ");
        STARTINPUTWORD();

        if (isEqual(CurrentWord, "YES")) {
            barangExist = false;
            while (!barangExist) {
                printf("Daftar barang yang ada di toko:\n");
                DisplayBarang(listbarang);
                printf("Nama barang yang akan dihapus:\n");
                printf(">>> ");
                STARTINPUTWORD();
                rem_input = WordToString(CurrentWord);

                if (IsBarangExist(listbarang, rem_input)) {
                    TakeBarang(listbarang, rem_input);
                    printf("Barang %s berhasil dihapus.\n", rem_input);
                    barangExist = true;
                }
                else if (isEqual(CurrentWord, "BACK"))
                {
                    printf("Kembali ke menu utama.\n");
                    return;
                }
                else {
                    printf("Toko tidak menjual %s. Silakan masukkan nama barang yang valid.\n", rem_input);
                }
            }
        }
        else if (isEqual(CurrentWord, "BACK"))
        {
            break;
        }
        else
        {
            printf("Perintah tidak dikenal. Silakan masukkan YES atau BACK.\n");
        }
    }
}

void SRequest(Queue *req, ListBarang *listbarang) {
    while (1) {
        printf("Nama barang yang diminta: \n");
        printf(">>> ");
        STARTINPUTWORD();
        char *req_input = WordToString(CurrentWord);

        if (IsBarangExist(listbarang, req_input)) {
            printf("Barang dengan nama yang sama sudah ada di toko!\n");
            continue; // Meminta input ulang
        }

        int i = req->idxHead;
        while (i != ((req->idxTail + 1) % CAPACITY)) {
            if (StringCompare(req_input, req->buffer[i].name)) {
                printf("Barang dengan nama yang sama sudah ada di antrian!\n");
                continue; //  input ulang
            }
            i = (i + 1) % CAPACITY;
        }

        Barang newRequest;
        StringCopy(newRequest.name, req_input);
        newRequest.price = 0;

        enqueue(req, newRequest);
        printf("\nBarang %s berhasil ditambahkan ke dalam antrian!\n", req_input);

        while (1) {
            printf("Apakah kamu ingin menambahkan barang lain? (YES/BACK): \n");
            printf(">>> ");
            STARTINPUTWORD();
            char *response = WordToString(CurrentWord);

            if (StringCompare(response, "YES")) {
                break; // req barang baru
            } else if (StringCompare(response, "BACK")) {
                printf("Kembali ke menu utama.\n");
                return;
            } else {
                printf("Input tidak valid. Silakan masukkan YES atau BACK.\n");
            }
        }
    }
}


void SSupply(Queue *req, ListBarang *listbarang) {
    if (isEmpty(*req)) {
        printf("Tidak ada barang dalam antrian!\n");
        while (1) {
            printf("Ketik 'BACK' untuk kembali: \n");
            printf(">>> ");
            STARTINPUTWORD();

            if (isEqual(CurrentWord, "BACK")) {
                break;
            } else {
                printf("Input tidak valid. \n");
            }
        }
        return;
    }

    while (!isEmpty(*req)) {
        Barang frontItem = req->buffer[req->idxHead];
        char input[20];

        while (1) {
            printf("Apakah kamu ingin menambahkan barang %s (terima/tunda/tolak): ", frontItem.name);
            printf(">>> ");
            STARTINPUTWORD();
            StringCopy(input, WordToString(CurrentWord));
            ToLowerCase(input);

            if (StringCompare(input, "terima")) {
                int harga;
                while (1) {
                    printf("Harga barang: ");
                    STARTINPUTWORD();
                    harga = WordToInt(CurrentWord);

                    if (harga > 0) {
                        break; // Harga valid
                    } else {
                        printf("Harga tidak valid! Silakan masukkan harga yang lebih besar dari 0.\n");
                    }
                }

                dequeue(req, &frontItem);
                frontItem.price = harga;
                AddBarang(listbarang, frontItem.name, frontItem.price);
                printf("\n%s dengan harga %d telah ditambahkan ke toko.\n", frontItem.name, harga);
                break;
            } else if (StringCompare(input, "tunda")) {
                Barang temp;
                dequeue(req, &temp);
                enqueue(req, temp);
                printf("\n%s dikembalikan ke antrian.\n", temp.name);
                break;
            } else if (StringCompare(input, "tolak")) {
                Barang temp;
                dequeue(req, &temp);
                printf("\n%s dihapuskan dari antrian.\n", temp.name);
                break;
            } else {
                printf("Input tidak valid. Silakan masukkan 'terima', 'tunda', atau 'tolak'.\n");
            }
        }

        while (1) {
            printf("Ketik 'BACK' untuk kembali ke menu atau lanjut ke barang berikutnya: \n");
            printf(">>> ");
            STARTINPUTWORD();

            if (isEqual(CurrentWord, "BACK")) {
                return; 
            } else {
                printf("Input tidak valid. Ketik 'BACK' untuk kembali.\n");
            }
        }
    }
}
