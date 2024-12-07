#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "home.h"
#include "film.h"          // Untuk memilih film
#include "jadwal.h"        // Untuk memilih jadwal
#include "kursi.h"         // Untuk memilih kursi
#include "pembayaran.h"    // Untuk melakukan pembayaran

// Variabel eksternal yang digunakan dari modul lain
extern char waktuFormatted[50];
extern film selectedFilm;
extern char tanggalDipilih[4][30];
extern int tanggalPilihan;
extern char jamDipilih[10];
extern int jumlah;
extern kursi K1;

// Fungsi placeholder untuk history pembelian
void tampilkanHistory() {
    system("cls");
    printf("========================================\n");
    printf("            HISTORY PEMBELIAN           \n");
    printf("========================================\n");
    
    // Implementasi history pembelian bisa berupa membaca dari file atau array
    // Untuk contoh ini, kita gunakan placeholder
    printf("Belum ada history pembelian.\n");
    
    printf("========================================\n");
    printf("\nTekan Enter untuk kembali ke menu utama...\n");
    getchar(); // Menunggu input Enter
    getchar(); // Menangkap Enter pertama
}

// Fungsi utama untuk menampilkan menu utama setelah login
void tampilkanHome() {
    int pilihan;
    int running = 1;

    while (running) {
        system("cls");
        printf("========================================\n");
        printf("        Selamat Datang di C'Nema        \n");
        printf("========================================\n");
        printf("Pilih opsi:\n");
        printf("1. Memilih Film\n");
        printf("2. Melihat History Pembelian\n");
        printf("3. Keluar\n");
        printf("========================================\n");
        printf("Masukkan pilihan Anda: ");
        
        // Membaca input sebagai string terlebih dahulu untuk validasi
        char input[10];
        scanf("%s", input);

        // Validasi apakah input adalah angka
        int isValid = 1;
        for(int i = 0; input[i] != '\0'; i++) {
            if(!isdigit(input[i])) {
                isValid = 0;
                break;
            }
        }

        if (!isValid) {
            printf("\nInput tidak valid. Harap masukkan angka antara 1 hingga 3.\n");
            sleep(2);
            continue;
        }

        pilihan = atoi(input);

        switch (pilihan) {
            case 1:
                // Alur pemesanan film
                pilihFilm();          // Memilih film
                pilihBioskop();       // Memilih Bioskop
                pilihJadwal();        // Memilih jadwal
                pilihKursi();         // Memilih kursi
                pembayaran();         // Melakukan pembayaran
                break;
            case 2:
                system("cls"); // Bersihkan layar
                printf("========================================\n");
                printf("            Riwayat Pembelian           \n");
                printf("========================================\n");
                printf("========================================\n");
                printf("\nTekan enter untuk kembali ke menu utama...");
                getchar(); // Tunggu pengguna menekan enter
                getchar(); // Untuk menangkap karakter enter sebelumnya
                break;
            case 3:
                // Keluar dari program
                printf("\nTerima kasih telah menggunakan C'Nema!\n");
                sleep(2);
                running = 0;
                system("cls");
                break;
            default:
                printf("\nPilihan tidak valid. Harap masukkan angka 1-3.\n");
                sleep(2);
                break;
        }
    }
}
