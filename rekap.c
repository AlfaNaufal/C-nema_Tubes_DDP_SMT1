#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "rekap.h"

#define FILENAME_REKAP "rekap.txt"

// rekap dataPenjualan;

void bacaFile(const char *filename, rekap *dataPenjualan, int *jumlahPenjualan){

    FILE *file = fopen(FILENAME_REKAP, "r"); // Buka file dalam mode baca
    if (file == NULL) {
        printf("Gagal membuka file rekap.\n");
        return false;
    }

    char TanggalTayang[50], namaFilm[50], bioskop[50];
    int hargaTiket, jumlahTiket, totalPendapatan;
    
    while (fscanf(file, "%s %s %s %d %d %d", TanggalTayang, namaFilm, hargaTiket, jumlahTiket, totalPendapatan) != EOF) {
        if (strcmp(dataPenjualan->tanggal, TanggalTayang) == 0 && strcmp(dataPenjualan->film, namaFilm) == 0 && strcmp(dataPenjualan->hargatTiket, hargaTiket ) == 0 && strcmp(dataPenjualan->jumlahTiket, jumlahTiket) == 0 && strcmp(dataPenjualan->totalPendapatan, totalPendapatan) == 0) {
            fclose(file);
            return true; // Admin valid
        }
    }

    fclose(file);

}
