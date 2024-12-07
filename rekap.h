#ifndef rekap_h
#define rekap_h

typedef struct {
    char tanggal[20];
    char film[50];
    char bioskop[50];
    int jumlahTiket;
    int hargatTiket;
    int totalPendapatan;
} rekap;


void bacaFile(const char *filename, rekap *dataPenjualan, int *jumlahPenjualan);

#endif