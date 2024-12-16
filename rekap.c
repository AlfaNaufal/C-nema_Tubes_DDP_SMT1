#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "bioskop.h"
#include "film.h"
#include "kursi.h"
#include "rekap.h"

#define FILENAME_REKAP "rekap.txt"
#define MAX_REKAP 150

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
    fprintf(file, "%s | %s | %s | Rp. 30000 | %d | Rp. %d | %s | ", 
            tanggalDipilih[tanggalPilihan - 1], 
            selectedFilm.judul, 
            selectedBioskop.namaMall, 
            jumlah, 
            totalBayar, 
            jamDipilih);

    // Tulis kursi yang dipilih
    for (int i = 0; i < jumlah; i++) {
        if (i == jumlah - 1) {
            fprintf(file, "%s", K1->K[i]);
        }else{
            fprintf(file, "%s ,", K1->K[i]);
        }
        // fprintf(file, "%s ", K1->K[i]);
    }

    // Menambahkan baris baru setelah setiap transaksi
    fprintf(file, "\n");

    // Menutup file
    fclose(file);
    printf("Rekapitulasi berhasil disimpan ke file.\n");
}


void tampilRekapitulasi() {
    // Buka file rekapitulasi untuk menambahkan data
    FILE *file = fopen(FILENAME_REKAP, "r");
    if (file == NULL) {
        printf("Gagal membuka file rekap.\n");
        return;
    }

    char buffer[MAX_REKAP];

    printf("==========================================\n");
    printf("             Data Dekapitulasi            \n");
    printf("==========================================\n");

    // Baca setiap baris dalam file
    while (fgets(buffer, sizeof(buffer), file)) {
        char *tanggal = strtok(buffer, "|");
        char *film = strtok(NULL, "|");
        char *bioskop = strtok(NULL, "|");
        char *hargaPerTiket = strtok(NULL, "|");
        char *jumlahTiket = strtok(NULL, "|");
        char *totalPendapatan = strtok(NULL, "|");
        char *jam = strtok(NULL, "|");
        char *kursi = strtok(NULL, "\n");

        // Menampilkan data yang diambil
        printf("Tanggal        : %s\n", tanggal);
        printf("Film           : %s\n", film);
        printf("Bioskop        : %s\n", bioskop);
        printf("Harga per Tiket: %s\n", hargaPerTiket);
        printf("Jumlah Tiket   : %s\n", jumlahTiket);
        printf("Total Pendapatan: %s\n", totalPendapatan);
        printf("Jam            : %s\n", jam);
        printf("Kursi          : %s\n", kursi);
        printf("==========================================\n");
    }

    fclose(file);


    printf("0. Kembali\n");

    // return scanf("%s", &pilihan);
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
