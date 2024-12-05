#include <stdio.h>
#include <string.h>
#include "kursi.h"

void memilihKursi(kursi *K1);

int pilihKursi() {
    kursi K1;

    memilihKursi(&K1);

    printf("\nTerima kasih telah memesan kursi!\n");
    return 0;
}

void memilihKursi(kursi *K1) {
    int jumlah, i, j, valid;
    static char dipesan[18][3] = {0}; // Kursi yang sudah dipesan
    static int totalDipesan = 0;      // Jumlah kursi yang sudah dipesan
    char cek[18][3] = {
        "A1", "A2", "A3", "A4", "A5", "A6",
        "B1", "B2", "B3", "B4", "B5", "B6",
        "C1", "C2", "C3", "C4", "C5", "C6"
    };
    char yakin;

    while (1) {
        printf("\nSilakan Untuk Memilih Kursi\n");
        printf("______________________________________________________________\n");
        printf("                            Screen                            \n");
        printf("______________________________________________________________\n");
        printf("\n");
        printf("[A1]       [A2]       [A3]       [A4]       [A5]       [A6]\n");
        printf("\n");
        printf("[B1]       [B2]       [B3]       [B4]       [B5]       [B6]\n");
        printf("\n");
        printf("[C1]       [C2]       [C3]       [C4]       [C5]       [C6]\n");
        printf("\n\n");

        printf("Ingin Memesan Berapa Kursi (1-18): ");
        scanf("%d", &jumlah);

        if (jumlah <= 0 || jumlah > 18) {
            printf("Jumlah kursi tidak valid! Harus antara 1 hingga 18.\n");
            sleep(1);
            system("cls");
            continue;
        }

        printf("\nSilahkan Memilih Kursi (contoh: A1, B3):\n");
        for (i = 0; i < jumlah; i++) {
            valid = 0;

            while (!valid) {
                printf("Pilih kursi ke-%d: ", i + 1);
                scanf("%s", K1->K[i]);

                // Validasi apakah kursi ada dalam daftar
                for (j = 0; j < 18; j++) {
                    if (strcmp(K1->K[i], cek[j]) == 0) {
                        valid = 1;
                        break;
                    }
                }

                // Validasi apakah kursi sudah dipesan
                for (j = 0; j < totalDipesan; j++) {
                    if (strcmp(K1->K[i], dipesan[j]) == 0) {
                        valid = 0;
                        printf("Kursi %s sudah dipesan. Pilih kursi lain.\n", K1->K[i]);
                        break;
                    }
                }

                if (!valid) {
                    printf("Kursi tidak valid atau sudah dipesan. Ulangi input.\n");
                }
            }

            // Tambahkan ke daftar kursi yang sudah dipesan
            strcpy(dipesan[totalDipesan++], K1->K[i]);
        }

        printf("\nKursi yang Anda pilih:\n");
        for (i = 0; i < jumlah; i++) {
            printf("%s ", K1->K[i]);
        }

        K1->harga = jumlah * 30000;
        printf("\nHarga per Tiket: 30000");
        printf("\nHarga total yang harus dibayar: Rp.%d\n", K1->harga);

        printf("\nApakah Anda yakin dengan pilihan ini? (Y/T): ");
        scanf(" %c", &yakin);

        if (yakin == 'Y' || yakin == 'y') {
            printf("\nPesanan Anda telah dikonfirmasi!\n");
            break;
        } else if (yakin == 'T' || yakin == 't') {
            printf("\nUlangi pemilihan kursi...\n");
            sleep(1);
            system("cls");
            continue;
        } else {
            printf("\nInput tidak valid! Silakan ulangi proses.\n");
        }
    }
}
