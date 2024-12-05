#ifndef detail_h
#define detail_h

#include "film.h"
#include "jadwal.h"

typedef struct{
    
    char waktuFormatted[50];
    film selectedFilm;
    char tanggalDipilih[4][30];
    int tanggalPilihan;
    char jamPilih[10];

} detailParams;

void detail1(const char *waktuFormatted, film selectedFilm);
void detail2(const char *waktuFormatted, film selectedFilm, char tanggalDipilih[][30], int tanggalPilihan );
void detail3(const char *waktuFormatted, film selectedFilm, char tanggalDipilih[][30], int tanggalPilihan, const char *jamPilih);
void detailError();

#endif