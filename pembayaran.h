#ifndef pembayaran_h
#define pembayaran_h

#include "kursi.h"
#include "film.h"

extern kursi K1;
extern int jumlah;
extern film selectedFilm;

extern char waktuFormatted[50];
extern char tanggalDipilih[4][30];
extern int tanggalPilihan;

extern int validJam;
extern int jamPilihan;
extern char jamDipilih[10];

typedef struct{

    int idPembayaran;
    int jumlahTiket;
    int hargaTiket;
    int totalHarga;
    int kembalian;

} bayar;


void pembayaran();
// float hitungtotalHarga();
 


#endif