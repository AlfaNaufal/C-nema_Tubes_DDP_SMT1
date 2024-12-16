#ifndef rekap_h
#define rekap_h

// typedef struct {
//     char tanggal[20];
//     char film[50];
//     char bioskop[50];
//     int jumlahTiket;
//     int hargatTiket;
//     int totalPendapatan;
// } rekap;

typedef struct {
    char tanggal[20];
    char film[100];
    char bioskop[100];
    int hargaTiket;
    int jumlahTiket;
    int totalPendapatan;
    char waktuTayang[6];
    char kursi[50];  // Contoh: A1, B2, ...
} rekap;

void simpanRekapitulasi( const char *waktuFormatted, film selectedFilm, bioskop selectedBioskop, char tanggalDipilih[][30], int tanggalPilihan, const char *jamDipilih, kursi *K1, int jumlah, int totalBayar);
void tampilRekapitulasi();




#endif