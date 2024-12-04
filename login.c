#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "login.h"
#include "film.h"
#include "jadwal.h"

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

void masuk(akun *A1){

    system("cls");
    printf("========================================\n");
    printf("                LOGIN                   \n");
    printf("========================================\n");
    printf("Masukkan Username: ");
    scanf("%s", &((*A1).username));
    printf("Masukkan Password: ");
    scanf("%s", &((*A1).password));

    system("cls");
    printf("========================================\n");
    printf("             Login berhasil!            \n");
    printf("========================================\n");
    // delay_seconds(2);
    sleep(2);
    system("cls");
    // pilihFilm(); // Panggil fungsi untuk memilih film
    // pilihJadwal();

}

void signUp(akun *A1){

    system("cls");
    printf("========================================\n");
    printf("               SIGN UP                  \n");
    printf("========================================\n");
    printf("Masukkan Username: ");
    scanf("%s", &((*A1).username));
    printf("Masukkan Password: ");
    scanf("%s", &((*A1).password));

    system("cls");
    printf("========================================\n");
    printf("        Berhasil! Silakan Login         \n");
    printf("========================================\n");
    delay_seconds(3);
    system("cls");

    // Memanggil fungsi login 
    masuk(A1);

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

                // Memanggil fungsi login 
                masuk(A1);

                // Konfirmasi login
                isValid = !isValid;

                // pilihFilm(); // Panggil fungsi untuk memilih film
                pilihFilm();

            } 
            // Pilihan sign up
            else if (((*A1).pilih) == 2) {

                // Memanggil fungsi signUp 
                signUp(A1);

                // Konfirmasi sign up
                isValid = !isValid;   

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