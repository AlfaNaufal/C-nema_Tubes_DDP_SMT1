#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "rekap.h"

#define FILENAME_REKAP "rekap.txt"
#define MAX_REKAP 150

void simpanRekapitulasi(const char *waktuFormatted, 
                        film selectedFilm, 
                        bioskop selectedBioskop, 
                        char tanggalDipilih[][30], 
                        int tanggalPilihan, 
                        const char *jamDipilih, 
                        kursi *K1, 
                        int jumlah, 
                        int totalBayar) {
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
        } else {
            fprintf(file, "%s ,", K1->K[i]);
        }
    }

    // Tambahkan baris baru setelah setiap transaksi
    fprintf(file, "\n");

    // Tutup file
    fclose(file);
    printf("Rekapitulasi berhasil disimpan ke file.\n");
}

void tampilRekapitulasi() {
    system("cls");
    FILE *file = fopen(FILENAME_REKAP, "r");
    if (file == NULL) {
        printf("Gagal membuka file rekap.\n");
        return;
    }

    char buffer[MAX_REKAP];

    printf("==========================================\n");
    printf("             Data Rekapitulasi            \n");
    printf("==========================================\n");

    while (fgets(buffer, sizeof(buffer), file)) {
        char *tanggal = strtok(buffer, "|");
        char *film = strtok(NULL, "|");
        char *bioskop = strtok(NULL, "|");
        char *hargaPerTiket = strtok(NULL, "|");
        char *jumlahTiket = strtok(NULL, "|");
        char *totalPendapatan = strtok(NULL, "|");
        char *jam = strtok(NULL, "|");
        char *kursi = strtok(NULL, "\n");

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
    int pilihan;
    do {
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);
    } while (pilihan != 0);
}

void tampilRekapitulasiHarian(const char *tanggal) {
    system("cls");
    FILE *file = fopen(FILENAME_REKAP, "r");
    if (!file) {
        printf("Gagal membuka file rekap.\n");
        return;
    }

    char buffer[MAX_REKAP];
    int found = 0;

    printf("==========================================\n");
    printf("    Rekapitulasi untuk tanggal: %s\n", tanggal);
    printf("==========================================\n");

    while (fgets(buffer, sizeof(buffer), file)) {
        char *tanggalRekap = strtok(buffer, "|");

        if (strcmp(tanggalRekap, tanggal) == 0) {
            found = 1;
            char *film = strtok(NULL, "|");
            char *bioskop = strtok(NULL, "|");
            char *hargaPerTiket = strtok(NULL, "|");
            char *jumlahTiket = strtok(NULL, "|");
            char *totalPendapatan = strtok(NULL, "|");
            char *jam = strtok(NULL, "|");
            char *kursi = strtok(NULL, "\n");

            printf("Film           : %s\n", film);
            printf("Bioskop        : %s\n", bioskop);
            printf("Harga per Tiket: %s\n", hargaPerTiket);
            printf("Jumlah Tiket   : %s\n", jumlahTiket);
            printf("Total Pendapatan: %s\n", totalPendapatan);
            printf("Jam            : %s\n", jam);
            printf("Kursi          : %s\n", kursi);
            printf("==========================================\n");
        }
    }

    fclose(file);

    if (!found) {
        printf("Tidak ada data untuk tanggal %s.\n", tanggal);
    }

    printf("0. Kembali\n");
    int pilihan;
    do {
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);
    } while (pilihan != 0);
}

void tampilRekapitulasiBulanan(int bulan, int tahun) {
    system("cls");
    FILE *file = fopen(FILENAME_REKAP, "r");
    if (!file) {
        printf("Gagal membuka file rekap.\n");
        return;
    }

    char buffer[MAX_REKAP];
    int found = 0;
    char bulanTahun[10];

    sprintf(bulanTahun, "%02d-%d", bulan, tahun);

    printf("==========================================\n");
    printf("    Rekapitulasi untuk bulan: %s\n", bulanTahun);
    printf("==========================================\n");

    while (fgets(buffer, sizeof(buffer), file)) {
        char *tanggalRekap = strtok(buffer, "|");

        if (strstr(tanggalRekap, bulanTahun)) {
            found = 1;
            char *film = strtok(NULL, "|");
            char *bioskop = strtok(NULL, "|");
            char *hargaPerTiket = strtok(NULL, "|");
            char *jumlahTiket = strtok(NULL, "|");
            char *totalPendapatan = strtok(NULL, "|");
            char *jam = strtok(NULL, "|");
            char *kursi = strtok(NULL, "\n");

            printf("Film           : %s\n", film);
            printf("Bioskop        : %s\n", bioskop);
            printf("Harga per Tiket: %s\n", hargaPerTiket);
            printf("Jumlah Tiket   : %s\n", jumlahTiket);
            printf("Total Pendapatan: %s\n", totalPendapatan);
            printf("Jam            : %s\n", jam);
            printf("Kursi          : %s\n", kursi);
            printf("==========================================\n");
        }
    }

    fclose(file);

    if (!found) {
        printf("Tidak ada data untuk bulan %s.\n", bulanTahun);
    }

    printf("0. Kembali\n");
    int pilihan;
    do {
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);
    } while (pilihan != 0);
}

void tampilRekapitulasiTahunan(int tahun) {
    system("cls");
    FILE *file = fopen(FILENAME_REKAP, "r");
    if (!file) {
        printf("Gagal membuka file rekap.\n");
        return;
    }

    char buffer[MAX_REKAP];
    int found = 0;
    char tahunStr[5];

    sprintf(tahunStr, "%d", tahun);

    printf("==========================================\n");
    printf("    Rekapitulasi untuk tahun: %s\n", tahunStr);
    printf("==========================================\n");

    while (fgets(buffer, sizeof(buffer), file)) {
        char *tanggalRekap = strtok(buffer, "|");

        if (strstr(tanggalRekap, tahunStr)) {
            found = 1;
            char *film = strtok(NULL, "|");
            char *bioskop = strtok(NULL, "|");
            char *hargaPerTiket = strtok(NULL, "|");
            char *jumlahTiket = strtok(NULL, "|");
            char *totalPendapatan = strtok(NULL, "|");
            char *jam = strtok(NULL, "|");
            char *kursi = strtok(NULL, "\n");

            printf("Film           : %s\n", film);
            printf("Bioskop        : %s\n", bioskop);
            printf("Harga per Tiket: %s\n", hargaPerTiket);
            printf("Jumlah Tiket   : %s\n", jumlahTiket);
            printf("Total Pendapatan: %s\n", totalPendapatan);
            printf("Jam            : %s\n", jam);
            printf("Kursi          : %s\n", kursi);
            printf("==========================================\n");
        }
    }

    fclose(file);

    if (!found) {
        printf("Tidak ada data untuk tahun %s.\n", tahunStr);
    }

    printf("0. Kembali\n");
    int pilihan;
    do {
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);
    } while (pilihan != 0);
}
