#include <stdio.h>
#include <unistd.h>
#include "pembayaran.h"
#include "detail.h"

char waktuFormatted[50];
char tanggalDipilih[4][30];
int tanggalPilihan;

int validJam;
int jamPilihan;
char jamDipilih[10];

void pembayaran(){

    int a;
    detail4(waktuFormatted, selectedFilm, selectedBioskop, tanggalDipilih, tanggalPilihan, jamDipilih);
    scanf("%d", &a);


}