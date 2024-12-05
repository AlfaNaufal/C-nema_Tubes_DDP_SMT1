#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "film.h"
#include "detail.h"

    // Mengambil film yang dipilih dari file film.c
    film selectedFilmGlb;
    char waktuFormatted[50];
    char tanggalDipilih[4][30];
    int tanggalPilihan;

    int validJam;
    int jamPilihan;
    char jamDipilih[10];


// Fungsi untuk memilih jadwal
void pilihJadwal() {
    

    // Mendapatkan waktu saat ini
    time_t t = time(NULL);
    struct tm waktuSekarang = *localtime(&t);

    // Format waktu sekarang
    // char waktuFormatted[50];
    strftime(waktuFormatted, sizeof(waktuFormatted), "%H:%M:%S, %d %B %Y", &waktuSekarang);

    detail1(waktuFormatted, selectedFilmGlb);

    // Menampilkan tanggal dari hari ini hingga 3 hari ke depan
    printf("Pilih tanggal untuk film ini:\n");
    // char tanggalDipilih[4][30]; // Untuk menyimpan tanggal-tanggal yang tersedia
    for (int i = 0; i < 4; i++) {
        struct tm temp = waktuSekarang;
        temp.tm_mday += i; // Menambahkan i hari ke tanggal hari ini
        mktime(&temp);     // Menyesuaikan overflow waktu jika ada

        // Menyimpan tanggal ke array untuk referensi
        strftime(tanggalDipilih[i], sizeof(tanggalDipilih[i]), "%d %B %Y", &temp);
        printf("%d. %s\n", i + 1, tanggalDipilih[i]);
    }
    printf("----------------------------------------\n");

    // Membaca pilihan tanggal
    // int tanggalPilihan;
    while (1) {
        printf("Masukkan nomor tanggal yang Anda pilih: ");
        if (scanf("%d", &tanggalPilihan) != 1 || tanggalPilihan < 1 || tanggalPilihan > 4) {
            printf("Input tidak valid! Silakan pilih nomor antara 1 dan 4.\n");
            sleep(3);
            continue;
        }
        break;
    }

    // Menampilkan tanggal yang dipilih
    printf("\nAnda memilih tanggal: %s\n", tanggalDipilih[tanggalPilihan - 1]);
    sleep(2);
    system("cls");

    // Menampilkan jam yang tersedia
    // int validJam;
    // int jamPilihan;
    // char jamDipilih[10];
    do {

        // header(2);
        detail2(waktuFormatted, selectedFilmGlb, tanggalDipilih, tanggalPilihan);
        printf("\nPilih jam untuk film ini:\n");

        // Jadwal jam yang tersedia
        char jadwalJam[][10] = {"10:00 AM", "01:00 PM", "04:00 PM", "07:00 PM", "10:00 PM"};
        int jamJadwal[] = {10, 13, 16, 19, 22}; // Jam dalam format 24 jam untuk perbandingan

        for (int i = 0; i < 5; i++) {
            // Jika tanggal yang dipilih adalah hari ini, bandingkan jam
            if (tanggalPilihan == 1 && jamJadwal[i] <= waktuSekarang.tm_hour) {
                printf("%d. %s (Sudah Lewat)\n", i + 1, jadwalJam[i]);
            } else {
                printf("%d. %s\n", i + 1, jadwalJam[i]);
            }
        }
        printf("----------------------------------------\n");

        printf("Masukkan nomor jam yang Anda pilih: ");
        if (scanf("%d", &jamPilihan) != 1 || jamPilihan < 1 || jamPilihan > 5) {
            printf("Input tidak valid! Silakan pilih nomor antara 1 dan 5.\n");
            sleep(2);
            continue;
        }

        if (tanggalPilihan == 1 && jamJadwal[jamPilihan - 1] <= waktuSekarang.tm_hour) {
            printf("Jam %s sudah lewat! Silakan pilih jam lain.\n", jadwalJam[jamPilihan - 1]);
            sleep(2);
            system("cls");
            validJam = 0; // Ulangi pemilihan
        } else {
            validJam = 1; // Jam valid
            sprintf(jamDipilih, "%s", jadwalJam[jamPilihan - 1]);
        }
    } while (!validJam);
    system("cls");

    detail3(waktuFormatted, selectedFilmGlb, tanggalDipilih, tanggalPilihan, jamDipilih);
    sleep(2);
    system("cls");
}
