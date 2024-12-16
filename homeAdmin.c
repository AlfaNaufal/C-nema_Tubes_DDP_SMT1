#include <stdio.h>
#include "rekap.h"

void halamanAdmin() {
    while (1) {
        system("cls");
        printf("========================================\n");
        printf("           Halaman Admin                \n");
        printf("========================================\n");
        printf("1. Lihat Riwayat Penjualan\n");
        printf("2. Lihat Rekapitulasi Per Hari\n");
        printf("3. Lihat Rekapitulasi Per Bulan\n");
        printf("4. Lihat Rekapitulasi Per Tahun\n");
        printf("5. Keluar\n");
        printf("----------------------------------------\n");
        printf("Masukkan pilihan Anda: ");
        
        int pilihan;
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilRekapitulasi();
                break;
            case 2: {
                char tanggal[15];
                printf("Masukkan tanggal (DD-MM-YYYY): ");
                scanf("%s", tanggal);
                system("cls");
                tampilRekapitulasiHarian(tanggal);
                break;
            }
            case 3: {
                int bulan, tahun;
                printf("Masukkan bulan (1-12): ");
                scanf("%d", &bulan);
                printf("Masukkan tahun: ");
                scanf("%d", &tahun);
                system("cls");
                tampilRekapitulasiBulanan(bulan, tahun);
                break;
            }
            case 4: {
                int tahun;
                printf("Masukkan tahun: ");
                scanf("%d", &tahun);
                system("cls");
                tampilRekapitulasiTahunan(tahun);
                break;
            }
            case 5:
                printf("Keluar dari halaman admin.\n");
                return;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}
