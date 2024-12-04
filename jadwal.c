#include <stdio.h>
#include "film.h"

// Fungsi untuk memilih jadwal
void pilihJadwal() {
    // Mengambil film yang dipilih dari file film.c
    film selectedFilm = getSelectedFilm();

    // Menampilkan film yang dipilih
    printf("========================================\n");
    printf("         Jadwal Film C'Nema            \n");
    printf("========================================\n");
    printf("Film yang Anda pilih: %s\n", selectedFilm.judul);
    printf("Genre: %s\n", selectedFilm.genre);
    printf("========================================\n");

    // Menampilkan jadwal yang tersedia
    printf("Pilih jadwal untuk film ini:\n");
    printf("1. 10:00 AM\n");
    printf("2. 01:00 PM\n");
    printf("3. 04:00 PM\n");
    printf("4. 07:00 PM\n");
    printf("----------------------------------------\n");

    // Membaca pilihan jadwal
    int jadwal;
    printf("Masukkan nomor jadwal yang Anda pilih: ");
    scanf("%d", &jadwal);

    // Menampilkan jadwal yang dipilih
    printf("\nAnda memilih jadwal: ");
    switch (jadwal) {
        case 1: printf("10:00 AM\n"); break;
        case 2: printf("01:00 PM\n"); break;
        case 3: printf("04:00 PM\n"); break;
        case 4: printf("07:00 PM\n"); break;
        default: printf("Pilihan tidak valid!\n");
    }
}
