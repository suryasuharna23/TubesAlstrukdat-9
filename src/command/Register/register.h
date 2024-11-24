#ifndef REGISTER_H
#define REGISTER_H

#include "mesinkata.h"  // Untuk menggunakan mesin kata
#include "mesinkarakter.h"
#include "user.h"

// Fungsi untuk registrasi pengguna baru
// Memeriksa apakah username sudah ada, jika belum maka menambahkan pengguna baru
void registerUser(ListUser *users);

#endif
