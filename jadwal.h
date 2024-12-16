#ifndef jadwal_h
#define jadwal_h

#include "detail.h"
#include "film.h"
#include "bioskop.h"

 typedef struct{
    int pilih;
    char now[20];
    char jam[3][50];
 } jadwal;

  extern film selectedFilm;
  extern bioskop selectedBioskop;
  extern char waktuFormatted[50];
  extern char tanggalDipilih[4][30];
  extern int tanggalPilihan;
  
  extern int validJam;
  extern int jamPilihan;
  extern char jamDipilih[10];

 void pilihJadwal();


#endif
