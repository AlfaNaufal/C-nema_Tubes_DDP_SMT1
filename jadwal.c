#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include "film.h"
#include "bioskop.h"
#include "detail.h"

    // Mengambil film yang dipilih dari file film.c
    film selectedFilm;
    bioskop selectedBioskop;
    char waktuFormatted[50];
    char tanggalDipilih[4][30];
    int tanggalPilihan;

    int validJam;
    int jamPilihan;
    char jamDipilih[10];


// Fungsi untuk memilih jadwal
void pilihJadwal() {
    // film selectedFilm = getSelectedFilm(); // Mendapatkan film yang dipilih
    time_t t = time(NULL);
    struct tm waktuSekarang = *localtime(&t);

    // char waktuFormatted[50];
    strftime(waktuFormatted, sizeof(waktuFormatted), "%H:%M:%S, %d %B %Y", &waktuSekarang);

    // Menampilkan detail bagian ke 2
    detail2(waktuFormatted, selectedFilm, selectedBioskop);

    printf("Pilih tanggal untuk film ini:\n");
    // char tanggalDipilih[4][30];
    for (int i = 0; i < 4; i++) {
        struct tm temp = waktuSekarang;
        temp.tm_mday += i;
        mktime(&temp);
        strftime(tanggalDipilih[i], sizeof(tanggalDipilih[i]), "%d %B %Y", &temp);
        printf("%d. %s\n", i + 1, tanggalDipilih[i]);
    }
    printf("----------------------------------------\n");

    char input[10];
    // int tanggalPilihan;
    int isValid; // Deklarasi variabel isValid
    while (1) {
        printf("Masukkan nomor tanggal yang Anda pilih: ");
        scanf("%s", input);

        // Validasi input
        isValid = 1; // Variabel isValid digunakan untuk validasi
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                isValid = 0;
                break;
            }
        }

        if (!isValid) {
            printf("Input tidak valid! Silakan masukkan angka antara 1 dan 4.\n");
            sleep(2);
            continue;
        }

        // Konversi string ke integer
        tanggalPilihan = atoi(input);
        if (tanggalPilihan < 1 || tanggalPilihan > 4) {
            printf("Input tidak valid! Pilih nomor antara 1 dan 4.\n");
            sleep(2);
            continue;
        }
        break;
    }

    printf("\nAnda memilih tanggal: %s\n", tanggalDipilih[tanggalPilihan - 1]);
    sleep(2);
    system("cls");

    // Menampilkan jam yang tersedia
    int validJam = 0;
    // int jamPilihan;
    // char jamDipilih[10];
    do {

        // Menampilkan detail bagian ke 3
        detail3(waktuFormatted, selectedFilm, selectedBioskop, tanggalDipilih, tanggalPilihan);
        printf("\nPilih jam untuk film ini:\n");

        char jadwalJam[][10] = {"10:00 AM", "01:00 PM", "04:00 PM", "07:00 PM", "10:00 PM"};
        int jamJadwal[] = {10, 13, 16, 19, 22};

        for (int i = 0; i < 5; i++) {
            if (tanggalPilihan == 1 && jamJadwal[i] <= waktuSekarang.tm_hour) {
                printf("%d. %s (Sudah Lewat)\n", i + 1, jadwalJam[i]);
            } else {
                printf("%d. %s\n", i + 1, jadwalJam[i]);
            }
        }
        printf("----------------------------------------\n");

        printf("Masukkan nomor jam yang Anda pilih: ");
        scanf("%s", input);

        // Validasi input
        isValid = 1; // Deklarasi ulang untuk blok validasi jam
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                isValid = 0;
                break;
            }
        }

        if (!isValid) {
            printf("Input tidak valid! Silakan masukkan angka antara 1 dan 5.\n");
            sleep(2);
            system("cls");
            continue;
        }

        // Konversi string ke integer
        jamPilihan = atoi(input);
        if (jamPilihan < 1 || jamPilihan > 5) {
            printf("Input tidak valid! Pilih nomor antara 1 dan 5.\n");
            sleep(2);
            system("cls");
            continue;
        }

        if (tanggalPilihan == 1 && jamJadwal[jamPilihan - 1] <= waktuSekarang.tm_hour) {
            printf("Jam %s sudah lewat! Silakan pilih jam lain.\n", jadwalJam[jamPilihan - 1]);
            sleep(2);
            validJam = 0;
            system("cls");
        } else {
            validJam = 1;
            sprintf(jamDipilih, "%s", jadwalJam[jamPilihan - 1]);
        }
    } while (!validJam);

    printf("\nJam yang anda pilih: %s\n", jamDipilih);
    sleep(2);
    system("cls");
}
