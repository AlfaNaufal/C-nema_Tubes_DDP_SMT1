#ifndef KURSI_H
#define KURSI_H

#include "film.h"

typedef struct {
    char K[18][3]; // Maksimal 18 kursi, tiap kursi maksimal 2 karakter + null
    int jumlah;
    int harga;
} kursi;

extern kursi K1;
extern film selectedFilm;

extern char waktuFormatted[50];
extern char tanggalDipilih[4][30];
extern int tanggalPilihan;

extern int validJam;
extern int jamPilihan;
extern char jamDipilih[10];


int pilihKursi(); // Deklarasi fungsi utama untuk dipanggil dari main.c

#endif
