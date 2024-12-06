#ifndef detail_h
#define detail_h

#include "film.h"
#include "jadwal.h"
#include "bioskop.h"
#include "kursi.h"

typedef struct{
    
    char waktuFormatted[50];
    film selectedFilm;
    char tanggalDipilih[4][30];
    int tanggalPilihan;
    char jamPilih[10];

} detailParams;

void detail1(film selectedFilm);
void detail2(const char *waktuFormatted, film selectedFilm, bioskop selectedBioskop);
void detail3(const char *waktuFormatted, film selectedFilm, bioskop selectedBioskop, char tanggalDipilih[][30], int tanggalPilihan );
void detail4(const char *waktuFormatted, film selectedFilm, bioskop selectedBioskop, char tanggalDipilih[][30], int tanggalPilihan, const char *jamPilih);
void detail5(const char *waktuFormatted, film selectedFilm, bioskop selectedBioskop, char tanggalDipilih[][30], int tanggalPilihan, const char *jamPilih, kursi *K1, int jumlah);
// void detailError();

#endif