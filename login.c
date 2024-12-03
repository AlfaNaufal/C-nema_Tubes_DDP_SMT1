#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "login.h"
#include "film.h"

// Fungsi untuk memberikan jeda waktu (delay)
void delay_seconds(int seconds) {
    time_t start_time = time(NULL);
    while (time(NULL) < start_time + seconds);
}

// Fungsi untuk validasi apakah string adalah angka
bool is_number(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return false; // Bukan angka jika ada karakter non-digit
        }
    }
    return true;
}

// Fungsi login
int login(akun *A1) {
    bool isValid = true;
    char input[100]; // Buffer untuk membaca input

    while (isValid) {
        // Header menu utama
        system("cls"); // Membersihkan layar (gunakan "clear" di Linux/Mac)
        printf("========================================\n");
        printf("       Selamat Datang di C'Nema         \n");
        printf("========================================\n");
        printf("Pilih opsi:\n");
        printf("1. Login\n");
        printf("2. Sign Up\n");
        printf("----------------------------------------\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%s", input); // Baca input sebagai string

        // Validasi apakah input adalah angka
        if (is_number(input)) {
            (*A1).pilih = atoi(input); // Konversi string ke integer

            // Pilihan login
            if (((*A1).pilih) == 1) {
                system("cls");
                printf("========================================\n");
                printf("                LOGIN                   \n");
                printf("========================================\n");
                printf("Masukkan Username: ");
                scanf("%s", &((*A1).username));
                printf("Masukkan Password: ");
                scanf("%s", &((*A1).password));

                // Konfirmasi login
                isValid = !isValid;
                system("cls");
                printf("========================================\n");
                printf("         Login berhasil!               \n");
                printf("========================================\n");
                delay_seconds(2);
                system("cls");
                pilihFilm(); // Panggil fungsi untuk memilih film
            } 
            // Pilihan sign up
            else if (((*A1).pilih) == 2) {
                system("cls");
                printf("========================================\n");
                printf("               SIGN UP                  \n");
                printf("========================================\n");
                printf("Masukkan Username: ");
                scanf("%s", &((*A1).username));
                printf("Masukkan Password: ");
                scanf("%s", &((*A1).password));

                // Konfirmasi sign up
                isValid = !isValid;
                system("cls");
                printf("========================================\n");
                printf("    Berhasil! Silakan Login Kembali     \n");
                printf("========================================\n");
                delay_seconds(3);
            } 
            // Jika angka tidak valid
            else {
                system("cls");
                printf("========================================\n");
                printf("     Error 404: Option Not Found!       \n");
                printf("========================================\n");
                delay_seconds(3);
            }
        } 
        // Jika input bukan angka
        else {
            system("cls");
            printf("========================================\n");
            printf("    Input tidak valid! Harap masukkan   \n");
            printf("         angka (1 atau 2).              \n");
            printf("========================================\n");
            delay_seconds(3);
        }
    }
    return 0;
}
