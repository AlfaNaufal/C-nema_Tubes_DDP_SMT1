#ifndef pembayaran_h
#define pembayaran_h

#include "film.h"
#include "bioskop.h"
#include "detail.h"

extern char waktuFormatted[50];
extern film selectedFilm;
extern char tanggalDipilih[4][30];
extern int tanggalPilihan;
extern char jamDipilih[10];
// extern int jumlah;
extern kursi K1;

// Fungsi untuk menyimpan riwayat transaksi
void simpanRiwayat(const char *waktu, const char *film, const char *bioskop, const char *tanggal,
                   const char *jam, const char *kursi[], int hargaPerTiket, int jumlahTiket, int totalBayar);

// Fungsi pembayaran
void pembayaran();

#endif
