#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "bioskop.h"
#include "film.h"
#include "film.h"

// Daftar bioskop yang tersedia
bioskop daftarBioskop[] = {
    {1, "Trans Studio Mall", "XXI"},
    {2, "Metro Indah Mall", "CGV"},
    {3, "Istana Plaza", "Cinepolis"},
    {4, "23 Paskal Shopping Center", "CGV"},
    {5, "Summarecon Mall Bandung", "XXI"}
};

// Jumlah bioskop dalam daftar
int jumlahBioskop = sizeof(daftarBioskop) / sizeof(daftarBioskop[0]);

// Variabel global untuk menyimpan bioskop yang dipilih
bioskop selectedBioskop;

// Fungsi untuk memilih bioskop
void pilihBioskop() {
    int pilihan;

    while (1) {

        // Menampilkan detail bagian ke 1
        detail1(selectedFilm);
        
        // Menampilkan daftar bioskop
        // printf("\n========================================\n");
        printf("Daftar Bioskop C'Nema       \n");
        printf("Pilih lokasi bioskop:       \n");
        // printf("========================================\n");
        
        for (int i = 0; i < jumlahBioskop; i++) {
            printf("%d. %s - %s\n", daftarBioskop[i].pilih, daftarBioskop[i].namaMall, daftarBioskop[i].jenisBioskop);
        }
        
        printf("========================================\n");
        printf("Masukkan nomor bioskop yang ingin Anda pilih (1-%d): ", jumlahBioskop);
        
        // Memvalidasi input
        if (scanf("%d", &pilihan) != 1 || pilihan < 1 || pilihan > jumlahBioskop) {
            // Menangani input yang tidak valid
            while (getchar() != '\n'); // Membersihkan buffer
            printf("Pilihan tidak valid, coba lagi!\n");
            sleep(2);
            system("cls");
            continue;
        }

        // Menyimpan pilihan bioskop
        selectedBioskop = daftarBioskop[pilihan - 1];

        // Menampilkan bioskop yang dipilih
        printf("\nAnda memilih bioskop: %s - %s\n", selectedBioskop.namaMall, selectedBioskop.jenisBioskop);

        
        // Exit setelah memilih bioskop
        break;
    }
    sleep(2);
    system("cls");
}

// Fungsi untuk mendapatkan bioskop yang dipilih
// bioskop getSelectedBioskop() {
//     return selectedBioskop;
// }
