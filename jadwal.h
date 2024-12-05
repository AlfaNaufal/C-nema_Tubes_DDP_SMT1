#ifndef jadwal_h
#define jadwal_h

#include "detail.h"

 typedef struct{
    int pilih;
    char now[20];
    char jam[3][50];
 } jadwal;

   extern char waktuFormatted[50];
   extern char tanggalDipilih[4][30];
   extern int tanggalPilihan;

   extern int validJam;
   extern int jamPilihan;
   extern char jamDipilih[10];

 void pilihJadwal();


#endif
