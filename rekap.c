#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bioskop.h"
#include "film.h"
#include "kursi.h"
#include "rekap.h"

#define FILENAME_REKAP "rekap.txt"

// Variabel eksternal untuk data dari modul lain
extern char waktuFormatted[50];
extern film selectedFilm;
extern char tanggalDipilih[4][30];
extern int tanggalPilihan;
extern char jamDipilih[10];
extern int jumlah;
extern kursi K1;

// rekap dataPenjualan;
void simpanRekapitulasi( const char *waktuFormatted, film selectedFilm, bioskop selectedBioskop, char tanggalDipilih[][30], int tanggalPilihan, const char *jamDipilih, kursi *K1, int jumlah, int totalBayar) {
    // Buka file rekapitulasi untuk menambahkan data
    FILE *file = fopen(FILENAME_REKAP, "a");
    if (file == NULL) {
        printf("Gagal membuka file rekap.\n");
        return;
    }

    // Tulis data ke dalam file
    fprintf(file, "%s | %s | %s | Rp. 30000 | %d | Rp. %d | %s | %s | ", 
            tanggalDipilih[tanggalPilihan - 1], 
            selectedFilm.judul, 
            selectedBioskop.namaMall, 
            jumlah, 
            totalBayar, 
            jamDipilih);

    // Tulis kursi yang dipilih
    for (int i = 0; i < jumlah; i++) {
        fprintf(file, "%s ", K1->K[i]);
    }

    // Menambahkan baris baru setelah setiap transaksi
    fprintf(file, "\n");

    // Menutup file
    fclose(file);
    printf("Rekapitulasi berhasil disimpan ke file.\n");
}






// bool bacaFile(const char *filename, rekap *dataPenjualan, int *jumlahPenjualan) {
//     FILE *file = fopen(filename, "r"); // Buka file dalam mode baca
//     if (file == NULL) {
//         printf("Gagal membuka file rekap.\n");
//         return false;
//     }

//     char TanggalTayang[50], namaFilm[50], bioskop[50];
//     int hargaTiket, jumlahTiket, totalPendapatan;

//     while (fscanf(file, "%s %s %s %d %d %d", 
//                   TanggalTayang, namaFilm, bioskop, 
//                   &hargaTiket, &jumlahTiket, &totalPendapatan) != EOF) {
//         // Cocokkan data
//         if (strcmp(dataPenjualan->tanggal, TanggalTayang) == 0 &&
//             strcmp(dataPenjualan->film, namaFilm) == 0 &&
//             strcmp(dataPenjualan->bioskop, bioskop) == 0 &&
//             dataPenjualan->hargatTiket == hargaTiket &&
//             dataPenjualan->jumlahTiket == jumlahTiket &&
//             dataPenjualan->totalPendapatan == totalPendapatan) {
//             fclose(file);
//             return true; // Data ditemukan
//         }
//     }

//     fclose(file);
//     return false; // Data tidak ditemukan
// }
