#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "home.h"
#include "menu.h"
#include "film.h"          // Untuk memilih film
#include "jadwal.h"        // Untuk memilih jadwal
#include "kursi.h"         // Untuk memilih kursi
#include "pembayaran.h"    // Untuk melakukan pembayaran

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
    menu  state;

    while (state.running) {
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

        state.pilihan = atoi(input);

        pilihMenu(&state);
    }
}


