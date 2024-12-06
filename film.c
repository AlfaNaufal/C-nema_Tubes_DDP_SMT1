#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "film.h"

// Daftar film yang tersedia
film daftarFilm[] = {
    {1, "Avengers: Endgame", "Action, Adventure, Sci-Fi"},
    {2, "The Lion King", "Animation, Adventure, Drama"},
    {3, "Inception", "Action, Adventure, Sci-Fi"},
    {4, "Titanic", "Drama, Romance"},
    {5, "Frozen II", "Animation, Adventure, Family"},
    {6, "The Dark Knight", "Action, Crime, Drama"}
};

// Jumlah film dalam daftar
int jumlahFilm = sizeof(daftarFilm) / sizeof(daftarFilm[0]);

// Variabel global untuk menyimpan film yang dipilih
film selectedFilm;

// Fungsi untuk memilih film
void pilihFilm() {
    int pilihan;
    // film selectedFilm = selectedFilm;

    while (1) {
        // Menampilkan daftar film
        printf("========================================\n");
        printf("            Daftar Film C'Nema         \n");
        printf("========================================\n");
        
        for ( i = 0; i < jumlahFilm; i++) {
            printf("%d. %s - %s\n", daftarFilm[i].pilih, daftarFilm[i].judul, daftarFilm[i].genre);
        }
        
        printf("========================================\n");
        printf("Masukkan nomor film yang ingin Anda tonton (1-%d): ", jumlahFilm);
        
        // Memvalidasi input
        if (scanf("%d", &pilihan) != 1 || pilihan < 1 || pilihan > jumlahFilm) {
            // Menangani input yang tidak valid
            while (getchar() != '\n'); // membersihkan buffer
            printf("Pilihan tidak valid, coba lagi!\n");
            sleep(2);
            system("cls");
            continue;
        }

        // Menyimpan pilihan film
        selectedFilm = daftarFilm[pilihan - 1];

        // Menampilkan film yang dipilih
        printf("\nAnda memilih: %s\n", selectedFilm.judul);
        printf("Genre: %s\n", selectedFilm.genre);
        
        // Exit setelah memilih film
        break;
    }
    sleep(2);
    system("cls");
}

// Fungsi untuk mendapatkan film yang dipilih
// film getSelectedFilm() {
//     return selectedFilm;
// }
