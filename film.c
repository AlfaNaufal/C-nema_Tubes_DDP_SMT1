#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "film.h"
#include "menu.h"

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
    menu state;
    int pilih;
    // film selectedFilm = selectedFilm;

    while (1) {
        // Menampilkan daftar film
        system("cls");
        printf("========================================\n");
        printf("            Daftar Film C'Nema         \n");
        printf("========================================\n");
        
        for (int i = 0; i < jumlahFilm; i++) {
            printf("%d. %s - %s\n", daftarFilm[i].pilih, daftarFilm[i].judul, daftarFilm[i].genre);
        }
            printf("0. Kembali\n");
        
        printf("========================================\n");
        printf("Masukkan nomor film yang ingin Anda tonton (1-%d): ", jumlahFilm);
        
        
        // Memvalidasi input
        if (scanf("%d", &pilih) != 1|| pilih < 0 || pilih > jumlahFilm) {
            // Menangani input yang tidak valid
            while (getchar() != '\n'); // membersihkan buffer
            printf("Pilihan tidak valid, coba lagi!\n");
            sleep(2);
            system("cls");
            continue;
        }


        if(pilih == 0){
            state.pilihan = state.pilihan -1;

            pilihMenu(&state);   
        }
        
        // Menyimpan pilihan film
        selectedFilm = daftarFilm[state.pilihan - 1];

        // Menampilkan film yang dipilih
        printf("\nAnda memilih: %s\n", selectedFilm.judul);
        printf("Genre: %s\n", selectedFilm.genre);
        
        // Exit setelah memilih film
        break;
    }
    sleep(2);
    system("cls");
}
