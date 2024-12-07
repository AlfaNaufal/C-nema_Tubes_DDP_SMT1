#include <stdio.h>
#include <unistd.h>
#include "menu.h"
#include "home.h"
#include "login.h"
#include "film.h"          // Untuk memilih film
#include "jadwal.h"        // Untuk memilih jadwal
#include "kursi.h"         // Untuk memilih kursi
#include "pembayaran.h"    // Untuk melakukan pembayaran


void pilihMenu(menu *state){
    akun A1;

            switch (state->pilihan) {
            case 0:
                login(&A1);;         // Melakukan pembayaran
                break;
            case 1:
                tampilkanHome();         // Melakukan pembayaran
                break;
            case 2:
                pilihFilm();         // Melakukan pembayaran
                break;
            case 3:
                pilihBioskop();       // Memilih Bioskop
                break;
            case 4:
                pilihJadwal();        // Memilih jadwal
                break;
            case 5:
                pilihKursi();         // Memilih kursi
                break;
            case 6:
                pembayaran();         // Melakukan pembayaran
                break;
            case 7:
                system("cls"); // Bersihkan layar
                printf("========================================\n");
                printf("            Riwayat Pembelian           \n");
                printf("========================================\n");
                printf("========================================\n");
                printf("\nTekan enter untuk kembali ke menu utama...");
                getchar(); // Tunggu pengguna menekan enter
                getchar(); // Untuk menangkap karakter enter sebelumnya
                break;
            case 8:
                // Keluar dari program
                printf("\nTerima kasih telah menggunakan C'Nema!\n");
                sleep(2);
                state->running = 0;
                system("cls");
                break;
            default:
                printf("\nstate tidak valid. Harap masukkan angka 1-3.\n");
                sleep(2);
                break;
        }

}