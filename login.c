#include <stdio.h>
#include "film.h"
#include "login.h"

// Fungsi login
int login(akun *A1) {
    // Tampilan header
    printf("========================================\n");
    printf("          Selamat Datang di C'Nema      \n");
    printf("========================================\n");
    printf("Pilih opsi:\n");
    printf("1. Login\n");
    printf("2. Sign Up\n");
    printf("----------------------------------------\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &((*A1).pilih));
    system("cls");
    
    // Jika pilihan adalah login
    if ((*A1).pilih == 1) {
        printf("\n----------------------------------------\n");
        printf("                LOGIN                   \n");
        printf("----------------------------------------\n");
        printf("Masukkan Username: ");
        scanf("%s", &((*A1).username));
        printf("Masukkan Password: ");
        scanf("%s", &((*A1).password));
        printf("\n----------------------------------------\n");
        printf("Login berhasil! Selamat datang, %s.\n", (*A1).username);
    } else if ((*A1).pilih == 2) {
        printf("\n----------------------------------------\n");
        printf("               SIGN UP                  \n");
        printf("----------------------------------------\n");
        printf("Fitur sign-up belum tersedia.\n");
        printf("----------------------------------------\n");
    } else {
        printf("\n----------------------------------------\n");
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
        printf("----------------------------------------\n");
    }
    system("cls");
    tampilFilm();

    return 0;
}