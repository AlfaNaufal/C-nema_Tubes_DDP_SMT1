#include <stdio.h>
#include <unistd.h>
#include "pembayaran.h"
#include "kursi.h"
#include "film.h"
#include "jadwal.h"

// extern film selectedFilm;

// char waktuFormatted[50];
// char tanggalDipilih[4][30];
// int tanggalPilihan;

// int validJam;
// int jamPilihan;
// char jamDipilih[10];

void pembayaran(){
    // int a;
    // Menampilkan detail bagian ke 4
        // detail4(waktuFormatted, selectedFilm, selectedBioskop, tanggalDipilih, tanggalPilihan, jamDipilih);
    detail5(waktuFormatted, selectedFilm, selectedBioskop, tanggalDipilih, tanggalPilihan, jamDipilih, &K1, K1.jumlah);

    K1.harga = K1.jumlah * 30000;
    printf("\nHarga per Tiket: Rp.30000");
    printf("\nTotal Tiket yang di Pesan: %d", K1.jumlah);
    printf("\nHarga total yang harus dibayar: Rp.%d\n", K1.harga);

    // scanf("%d", &a);
}