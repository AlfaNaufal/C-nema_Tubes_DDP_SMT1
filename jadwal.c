#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jadwal.h"

jadwal listJadwal[] = {
    {1, "12-10-2024", {"11.00", "12.30", "14.00"}},
    {2, "12-12-2024", {"11.20", "12.50", "14.20"}},
    {3, "12-15-2024", {"11.30", "13.00", "14.30"}},

};

int jumlahJadwal = sizeof(listJadwal)/ sizeof(listJadwal[0]);

void pilihJadwal(){

    int pilihan;
    int pilihTanggal;
    time_t jad;
    struct tm *waktu;
    jad = time(NULL);
    waktu = localtime(&jad);

    int tahun = waktu->tm_year + 1900;
    int bulan = waktu->tm_mon + 1;
    int tanggal = waktu->tm_mday + 1;
    int jam = waktu->tm_hour;
    int menit = waktu->tm_min;

    printf("=================================\n");
    printf("     Silahkan Memilih Jadwal     \n");
    printf("=================================\n");
    printf("Waktu sekarang %d-%d-%d\n", tahun, tanggal, bulan);
    printf("Waktu sekarang %d.%d\n", jam, menit);
    
    for (int i = 0; i < jumlahJadwal; i++) {
        printf("%d. %s - %s | %s | %s\n", listJadwal[i].pilih, listJadwal[i].now, listJadwal[i].jam[0], listJadwal[i].jam[1], listJadwal[i].jam[2]);
        
    }

    printf("Note: Pilih berdasarkan nomor urutnya! \n");
    printf("Silahkan pilih tanggal: ");
    scanf("%d", &pilihTanggal);
    system("cls");

    if(pilihTanggal == 1){
    printf("==================== \n");
    printf("     Jam Tayang      \n");
    printf("==================== \n");
        for (int i = 0; i < 3; i++) {
            printf("%d. %s | %s | %s\n", i+1, listJadwal[pilihTanggal].jam[i], listJadwal[pilihTanggal].jam[i], listJadwal[pilihTanggal].jam[i]);
            
        }
    printf("Silahkan pilih jam: ");
    scanf("%d", &pilihan);
    }else if(pilihTanggal == 2){
    printf("==================== \n");
    printf("     Jam Tayang      \n");
    printf("==================== \n");
        for (int i = 0; i < 3; i++) {
            printf("%d. %s | %s | %s\n", i+1, listJadwal[pilihTanggal].jam[i], listJadwal[pilihTanggal].jam[i], listJadwal[pilihTanggal].jam[i]);
            
        }
    printf("Silahkan pilih jam: ");
    scanf("%d", &pilihan);
    }else if(pilihTanggal == 3){
    printf("==================== \n");
    printf("     Jam Tayang      \n");
    printf("==================== \n");
        for (int i = 0; i < 3; i++) {
            printf("%d. %s | %s | %s\n", i+1, listJadwal[pilihTanggal].jam[i], listJadwal[pilihTanggal].jam[i], listJadwal[pilihTanggal].jam[i]);
            
        }
    printf("Silahkan pilih jam: ");
    scanf("%d", &pilihan);
    }

    // scanf("%d", &pilihan);

}
