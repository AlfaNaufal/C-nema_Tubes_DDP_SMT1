#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "pembayaran.h"
#include "rekap.h"

// Variabel eksternal untuk data dari modul lain
extern char waktuFormatted[50];
extern film selectedFilm;
extern char tanggalDipilih[4][30];
extern int tanggalPilihan;
extern char jamDipilih[10];
extern int jumlah;
extern kursi K1;

// Saldo awal pelanggan (contoh simulasi)
int saldoSaatIni = 100000;

// Fungsi pembayaran tiket
void pembayaran() {
    char konfirmasi;
    int totalBayar = jumlah * 30000;

    while (1) {
        system("cls");

        // Tampilkan detail tiket (dengan asumsi fungsi detail5 tersedia)
        detail5(waktuFormatted, selectedFilm, selectedBioskop, tanggalDipilih, tanggalPilihan, jamDipilih, &K1, jumlah);

        // Tampilkan informasi pembayaran
        printf("\n========================================\n");
        printf("              INFORMASI PEMBAYARAN              \n");
        printf("========================================\n");
        printf("Harga per Tiket            : Rp. 30000\n");
        printf("Jumlah Tiket yang dipesan  : %d\n", jumlah);
        printf("Total Bayar                : Rp. %d\n", totalBayar);
        printf("Saldo Saat Ini             : Rp. %d\n", saldoSaatIni);
        printf("========================================\n");

        if (saldoSaatIni >= totalBayar) {
            printf("Apakah Anda yakin ingin membeli tiket ini? (Y/T): ");
            scanf(" %c", &konfirmasi);
            while (getchar() != '\n'); // Membersihkan buffer input

            if (konfirmasi == 'Y' || konfirmasi == 'y') {
                saldoSaatIni -= totalBayar;
                simpanRekapitulasi(waktuFormatted, selectedFilm, selectedBioskop, tanggalDipilih, tanggalPilihan, jamDipilih, &K1,  jumlah, totalBayar);
                printf("\nPembayaran berhasil!\n");
                printf("Saldo Anda saat ini: Rp. %d\n", saldoSaatIni);
                printf("\nTerima kasih telah memesan tiket di C'Nema!\n");
                sleep(3);
                system("cls");
                break;
            } else if (konfirmasi == 'T' || konfirmasi == 't') {
                printf("\nPembelian dibatalkan.\n");
                sleep(2);
                system("cls");
                break;
            } else {
                printf("\nInput tidak valid! Harap masukkan Y atau T.\n");
                sleep(2);
            }
        } else {
            printf("\nSaldo Anda tidak mencukupi untuk melakukan pembelian.\n");
            printf("Silakan isi ulang saldo Anda.\n");
            sleep(3);
            system("cls");
            break;
        }
    }
}
