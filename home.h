#ifndef home_h
#define home_h

#include "kursi.h"
#include "film.h"

// Variabel eksternal yang digunakan dari modul lain
// extern char waktuFormatted[50];
// extern film selectedFilm;
// extern char tanggalDipilih[4][30];
// extern int tanggalPilihan;
// extern char jamDipilih[10];
// extern int jumlah;
// extern kursi K1;

typedef struct {
    int pilihan;
    int running;
} homw;

// Fungsi utama untuk menampilkan menu utama setelah login
void tampilkanHome();

#endif // HOME_H
