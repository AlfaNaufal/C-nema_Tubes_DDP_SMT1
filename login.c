#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "login.h"
#include "menu.h"
#include "film.h"
#include "jadwal.h"

#define FILENAME_PELANGGAN "akun_pelanggan.txt"
#define FILENAME_ADMIN "akun_admin.txt"

menu state;

// Fungsi untuk memberikan jeda waktu (delay)
void delay_seconds(int seconds) {
    time_t start_time = time(NULL);
    while (time(NULL) < start_time + seconds);
}

// Fungsi untuk validasi apakah string adalah angka
bool is_number(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Fungsi untuk memvalidasi login admin
bool validasiAdmin(const char *username, const char *password) {
    FILE *file = fopen(FILENAME_ADMIN, "r"); // Buka file dalam mode baca
    if (file == NULL) {
        printf("Gagal membuka file akun admin.\n");
        return false;
    }

    char storedUsername[50], storedPassword[50];
    while (fscanf(file, "%s %s", storedUsername, storedPassword) != EOF) {
        if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0) {
            fclose(file);
            return true; // Admin valid
        }
    }
    fclose(file);
    return false; // Admin tidak ditemukan
}

// Fungsi untuk menyimpan akun pelanggan ke file
void simpanAkun(akun *A1) {
    FILE *file = fopen(FILENAME_PELANGGAN, "a"); // Buka file dalam mode append
    if (file == NULL) {
        printf("Gagal membuka file untuk menyimpan akun.\n");
        return;
    }
    fprintf(file, "%s %s\n", A1->username, A1->password);
    fclose(file);
}

// Fungsi untuk memvalidasi login pelanggan
bool validasiAkun(akun *A1) {
    FILE *file = fopen(FILENAME_PELANGGAN, "r"); // Buka file dalam mode baca
    if (file == NULL) {
        printf("Gagal membuka file akun pelanggan.\n");
        return false;
    }

    char username[50], password[50];
    while (fscanf(file, "%s %s", username, password) != EOF) {
        if (strcmp(username, A1->username) == 0 && strcmp(password, A1->password) == 0) {
            fclose(file);
            return true; // Akun valid
        }
    }
    fclose(file);
    return false; // Akun tidak ditemukan
}

// Fungsi login pelanggan
void masukPelanggan(akun *A1) {
    while (1) {
        system("cls");
        printf("========================================\n");
        printf("        LOGIN SEBAGAI PELANGGAN         \n");
        printf("========================================\n");
        printf("Masukkan Username: ");
        scanf("%s", A1->username);
        printf("Masukkan Password: ");
        scanf("%s", A1->password);

        if (validasiAkun(A1)) {
            state.pilihan = 1;
            printf("\nLogin berhasil! Selamat datang, %s.\n", A1->username);
            pilihMenu(&state);
            sleep(2);
            system("cls");
            break;
        } else {
            printf("\nUsername atau password salah! Silakan coba lagi.\n");
            sleep(2);
        }
    }
}

// Fungsi sign-up pelanggan
void signUpPelanggan(akun *A1) {
    system("cls");
    printf("========================================\n");
    printf("           SIGN UP PELANGGAN            \n");
    printf("========================================\n");
    printf("Masukkan Username: ");
    scanf("%s", A1->username);
    printf("Masukkan Password: ");
    scanf("%s", A1->password);

    simpanAkun(A1); // Simpan username dan password ke file

    system("cls");
    printf("========================================\n");
    printf("        Berhasil! Silakan Login         \n");
    printf("========================================\n");
    delay_seconds(3);
    system("cls");
}

// Fungsi login utama
int login(akun *A1) {
    bool isValid = true;
    char input[100];

    while (isValid) {
        system("cls");
        printf("========================================\n");
        printf("       Selamat Datang di C'Nema         \n");
        printf("========================================\n");
        printf("Pilih opsi:\n");
        printf("1. Login sebagai Admin\n");
        printf("2. Login atau Sign-Up sebagai Pelanggan\n");
        printf("----------------------------------------\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%s", input);

        if (is_number(input)) {
            (*A1).pilih = atoi(input);

            if ((*A1).pilih == 1) {
                // Login admin
                char username[50], password[50];
                system("cls");
                printf("========================================\n");
                printf("            LOGIN SEBAGAI ADMIN         \n");
                printf("========================================\n");
                printf("Masukkan Username: ");
                scanf("%s", username);
                printf("Masukkan Password: ");
                scanf("%s", password);

                if (validasiAdmin(username, password)) {
                    printf("\nLogin Admin berhasil! Selamat datang, %s.\n", username);
                    sleep(2);
                    system("cls");
                    break;
                } else {
                    printf("\nUsername atau password Admin salah!\n");
                    sleep(2);
                }

            } else if ((*A1).pilih == 2) {
                // Menu pelanggan
                while (1) {
                    system("cls");
                    printf("========================================\n");
                    printf("           MENU PELANGGAN               \n");
                    printf("========================================\n");
                    printf("Pilih opsi:\n");
                    printf("1. Login\n");
                    printf("2. Sign Up\n");
                    printf("----------------------------------------\n");
                    printf("Masukkan pilihan Anda: ");
                    scanf("%s", input);

                    if (is_number(input)) {
                        (*A1).pilih = atoi(input);

                        if ((*A1).pilih == 1) {
                            masukPelanggan(A1);
                            isValid = !isValid;
                            break;

                        } else if ((*A1).pilih == 2) {
                            signUpPelanggan(A1);
                            break;

                        } else {
                            printf("\nPilihan tidak valid! Harap masukkan angka 1 atau 2.\n");
                            sleep(2);
                        }
                    } else {
                        printf("\nInput tidak valid! Harap masukkan angka 1 atau 2.\n");
                        sleep(2);
                    }
                }
            } else {
                printf("\nPilihan tidak valid! Harap masukkan angka 1 atau 2.\n");
                sleep(2);
            }
        } else {
            printf("\nInput tidak valid! Harap masukkan angka 1 atau 2.\n");
            sleep(2);
        }
    }
    return 0;
}
