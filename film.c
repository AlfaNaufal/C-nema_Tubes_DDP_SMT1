#include <stdio.h>
#include <stdbool.h>
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

// Ini buat jumlah film nya
int jumlahFilm = sizeof(daftarFilm) / sizeof(daftarFilm[0]);

// Nampilin film nya trus usernya milih
void pilihFilm() {
    int pilihan;

    while (1) {
        // Menampilkan daftar film
        printf("========================================\n");
        printf("            Daftar Film C'Nema         \n");
        printf("========================================\n");
        
        for (int i = 0; i < jumlahFilm; i++) {
            printf("%d. %s - %s\n", daftarFilm[i].pilih, daftarFilm[i].judul, daftarFilm[i].genre);
        }
        
        printf("========================================\n");
        printf("Masukkan nomor film yang ingin Anda tonton (1-%d): ", jumlahFilm);
        
        // Memvalidasi input
        if (scanf("%d", &pilihan) != 1 || pilihan < 1 || pilihan > jumlahFilm) {
            // Menangani input yang tidak valid
            while(getchar() != '\n'); // membersihkan buffer
            printf("Pilihan tidak valid, coba lagi!\n");
            delay_seconds(2);
            system("cls");
            continue;
        }

        // Menampilkan film yang dipilih
        printf("\nAnda memilih: %s\n", daftarFilm[pilihan - 1].judul);
        printf("Genre: %s\n", daftarFilm[pilihan - 1].genre);
        printf("Terima kasih telah memilih film di C'Nema!\n");
        
        // Exit setelah memilih film
        break;
    }
}

