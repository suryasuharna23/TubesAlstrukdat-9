#include <stdio.h>
#include <stdlib.h>
#include "cart.h"
#include "../../command/History/history.h"
#include "../../ADT/User/user.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Map/map.h"
#include "../../ADT/Mesin/mesinkata.h"

extern Stack purchaseHistory;

Word GetLastWord(Word command)
{
    Word result;
    result.Length = 0;
    int i = command.Length - 1;

    // Skip trailing spaces
    while (i >= 0 && command.TabWord[i] == ' ')
    {
        i--;
    }

    // Find start of last word
    int end = i;
    while (i >= 0 && command.TabWord[i] != ' ')
    {
        i--;
    }

    // Copy last word
    for (int j = i + 1; j <= end; j++)
    {
        result.TabWord[result.Length] = command.TabWord[j];
        result.Length++;
    }

    return result;
}

Word GetItemNameFromCommand(Word command)
{
    Word result;
    result.Length = 0;
    int i = 0;
    boolean found_command = false;

    // Skip until after "ADD " or "REMOVE "
    while (i < command.Length - 6)
    {
        if ((command.TabWord[i] == 'A' &&
             command.TabWord[i + 1] == 'D' &&
             command.TabWord[i + 2] == 'D' &&
             command.TabWord[i + 3] == ' ') ||
            (command.TabWord[i] == 'R' &&
             command.TabWord[i + 1] == 'E' &&
             command.TabWord[i + 2] == 'M' &&
             command.TabWord[i + 3] == 'O' &&
             command.TabWord[i + 4] == 'V' &&
             command.TabWord[i + 5] == 'E' &&
             command.TabWord[i + 6] == ' '))
        {
            i += (command.TabWord[i] == 'A') ? 4 : 7;
            found_command = true;
            break;
        }
        i++;
    }

    if (!found_command)
        return result;

    // Find last space (before quantity)
    int end = command.Length - 1;
    while (end >= 0 && command.TabWord[end] != ' ')
    {
        end--;
    }

    // Copy item name (including spaces and numbers)
    while (i < end)
    {
        result.TabWord[result.Length] = command.TabWord[i];
        result.Length++;
        i++;
    }

    return result;
}

void DisplayAvailableItems(ListBarang *listbarang) {
    printf("Barang yang tersedia di toko:\n");
    printf("+----------------------------+------------+\n");
    printf("| Nama                       | Harga      |\n");
    printf("+----------------------------+------------+\n");
    for (int i = 0; i < listbarang->count; i++) {
        printf("| %-26s | %-10d |\n", listbarang->items[i].name, listbarang->items[i].price);
    }
    printf("+----------------------------+------------+\n");
}

void DisplayCartItems(User *CurrentUser, ListBarang *listbarang) {
    if (IsEmpty(CurrentUser->keranjang)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    printf("Berikut adalah isi keranjangmu:\n");
    printf("+------------+----------------+------------+------------+\n");
    printf("| Kuantitas  | Nama           | Harga/unit | Total      |\n");
    printf("+------------+----------------+------------+------------+\n");

    for (int i = 0; i < CurrentUser->keranjang.Count; i++) {
        int key = CurrentUser->keranjang.Elements[i].Key;
        int value = CurrentUser->keranjang.Elements[i].Value;
        int harga = listbarang->items[key].price;
        printf("| %-10d | %-14s | %-10d | %-10d |\n", value, listbarang->items[key].name, harga, value * harga);
    }
    printf("+------------+----------------+------------+------------+\n");
}

void CartAdd(User *CurrentUser, ListBarang *listbarang)
{
    while (true)
    {
        DisplayAvailableItems(listbarang);
        printf("\nMasukkan perintah: CART ADD <nama barang> <jumlah barang>\n");
        printf(">>> ");
        STARTINPUTWORD();

        if (isEqual(CurrentWord, "BACK"))
        {
            printf("Kembali ke menu utama.\n");
            return;
        }

        Word namaBarang = GetItemNameFromCommand(CurrentWord);
        if (namaBarang.Length == 0)
        {
            printf("Format perintah salah! Silakan coba lagi.\n");
            continue;
        }

        Word jumlahBarangWord = GetLastWord(CurrentWord);
        int jumlahBarang = WordToInt(jumlahBarangWord);

        if (jumlahBarang < 1)
        {
            printf("Masukkan jumlah barang yang valid!\n");
        }
        else
        {
            boolean found = false;
            for (int i = 0; i < listbarang->count; i++)
            {
                if (StringCompare(listbarang->items[i].name, WordToString(namaBarang)))
                {
                    found = true;
                    if (IsMember(CurrentUser->keranjang, i))
                    {
                        Insert(&CurrentUser->keranjang, i, Value(CurrentUser->keranjang, i) + jumlahBarang);
                    }
                    else
                    {
                        Insert(&CurrentUser->keranjang, i, jumlahBarang);
                    }
                    printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", jumlahBarang, WordToString(namaBarang));
                    break;
                }
            }
            if (!found)
            {
                printf("Barang tidak ada di toko!\n");
            }
        }
        printf("\nKetik 'ADD' untuk menambahkan barang lagi atau 'BACK' untuk kembali ke menu utama:\n");
        printf(">>> ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "BACK"))
        {
            printf("Kembali ke menu utama.\n");
            return;
        }
    }
}

void CartRemove(User *CurrentUser, ListBarang *listbarang) {
    while (true) {
        DisplayCartItems(CurrentUser, listbarang);
        printf("Masukkan perintah: CART REMOVE <nama barang> <jumlah barang>\n");
        printf(">>> ");
        STARTINPUTWORD();

        if (isEqual(CurrentWord, "BACK")) {
            return;
        }

        Word namaBarang = GetItemNameFromCommand(CurrentWord);
        if (namaBarang.Length == 0) {
            printf("Format perintah salah!\n");
            continue;
        }

        Word jumlahBarangWord = GetLastWord(CurrentWord);
        int jumlahBarang = WordToInt(jumlahBarangWord);

        if (jumlahBarang < 1) {
            printf("Masukkan jumlah barang yang Valid!\n");
        } else {
            boolean found = false;
            for (int i = 0; i < CurrentUser->keranjang.Count; i++) {
                int key = CurrentUser->keranjang.Elements[i].Key;
                if (StringCompare(listbarang->items[key].name, WordToString(namaBarang))) {
                    found = true;
                    if (CurrentUser->keranjang.Elements[i].Value >= jumlahBarang) {
                        CurrentUser->keranjang.Elements[i].Value -= jumlahBarang;
                        if (CurrentUser->keranjang.Elements[i].Value == 0) {
                            Delete(&CurrentUser->keranjang, key);
                        }
                        printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", jumlahBarang, WordToString(namaBarang));
                    } else {
                        printf("Tidak cukup jumlah %s di keranjang untuk mengurangi!\n", WordToString(namaBarang));
                    }
                    break;
                }
            }
            if (!found) {
                printf("Barang tidak ada di keranjang belanja!\n");
            }
        }
        printf("Ketik 'REMOVE' untuk mengurangi barang lagi atau 'BACK' untuk kembali ke menu utama:\n");
    }
}

void CartShow(User *CurrentUser, ListBarang *listbarang) {
    if (IsEmpty(CurrentUser->keranjang)) {
        printf("Keranjang kamu kosong!\n");
        while (true) {
            printf("Ketik 'BACK' untuk kembali ke menu utama: \n");
            printf(">>> ");
            STARTINPUTWORD();
            if (isEqual(CurrentWord, "BACK")) {
                printf("Kembali ke menu utama.\n");
                return;
            } else {
                printf("Input tidak valid. Harap ketik 'BACK'.\n");
            }
        }
    }

    printf("Berikut adalah isi keranjangmu:\n");
    printf("+------------+----------------+------------+------------+\n");
    printf("| Kuantitas  | Nama           | Harga      | Total      |\n");
    printf("+------------+----------------+------------+------------+\n");

    int totalBiaya = 0;
    for (int i = 0; i < CurrentUser->keranjang.Count; i++) {
        int key = CurrentUser->keranjang.Elements[i].Key;
        int value = CurrentUser->keranjang.Elements[i].Value;
        int harga = listbarang->items[key].price;
        printf("| %-10d | %-14s | %-10d | %-10d |\n", value, listbarang->items[key].name, harga, value * harga);
        totalBiaya += value * harga;
    }
    printf("+------------+----------------+------------+------------+\n");
    printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalBiaya);

    printf("Ketik 'BACK' untuk kembali ke menu utama: ");
    printf("\n>>> ");

    STARTINPUTWORD();
    if (isEqual(CurrentWord, "BACK")) {
        printf("Kembali ke menu utama.\n");
    }
}

void CartPay(User *CurrentUser, ListBarang *listbarang) {
    if (IsEmpty(CurrentUser->keranjang)) {
        printf("Keranjang kamu kosong!\n");
        while (true) {
            printf("Ketik 'BACK' untuk kembali ke menu utama: \n");
            printf(">>> ");
            STARTINPUTWORD();
            if (isEqual(CurrentWord, "BACK")) {
                printf("Kembali ke menu utama.\n");
                return;
            } else {
                printf("Input tidak valid. Harap ketik 'BACK'.\n");
            }
        }
    }

    printf("Kamu akan membeli barang-barang berikut:\n");
    printf("+------------+----------------+------------+------------+\n");
    printf("| Kuantitas  | Nama           | Harga      | Total      |\n");
    printf("+------------+----------------+------------+------------+\n");

    int totalBiaya = 0;
    Purchase purchase;
    purchase.count = 0;

    for (int i = 0; i < CurrentUser->keranjang.Count; i++) {
        int key = CurrentUser->keranjang.Elements[i].Key;
        int value = CurrentUser->keranjang.Elements[i].Value;
        int harga = listbarang->items[key].price;
        printf("| %-10d | %-14s | %-10d | %-10d |\n", value, listbarang->items[key].name, harga, value * harga);
        totalBiaya += value * harga;

        PurchaseItem item;
        StringCopy(item.name, listbarang->items[key].name);
        item.quantity = value;
        item.total = value * harga;
        purchase.items[purchase.count++] = item;
    }

    purchase.totalCost = totalBiaya;
    printf("+------------+----------------+------------+------------+\n");
    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalBiaya);
    printf("\n>>> ");

    while (true) {
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "Ya")) {
            if (CurrentUser->money >= totalBiaya) {
                CurrentUser->money -= totalBiaya;
                printf("Selamat kamu telah membeli barang-barang tersebut!\n");

                // Store in user's history instead of global history
                Push(&CurrentUser->riwayat_pembelian, purchase);

                // Clear cart
                CreateEmpty(&CurrentUser->keranjang);
            } else {
                printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", CurrentUser->money);
            }
            break;
        } else if (isEqual(CurrentWord, "Tidak")) {
            printf("Pembelian dibatalkan.\n");
            break;
        } else {
            printf("Input tidak valid. Silakan masukkan 'Ya' atau 'Tidak': ");
            printf("\n>>> ");
        }
    }

    printf("Ketik 'BACK' untuk kembali ke menu utama: ");
    printf("\n>>> ");
    while (true) {
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu utama.\n");
            return;
        } else {
            printf("Input tidak valid. Harap ketik 'BACK'.\n");
        }
    }
}
