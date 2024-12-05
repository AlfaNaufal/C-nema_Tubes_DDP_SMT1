#ifndef bioskop_h
#define bioskop_h

// Struktur untuk menyimpan informasi bioskop
typedef struct {
    int pilih;
    char namaMall[50];
    char jenisBioskop[20];
} bioskop;

// Fungsi untuk memilih bioskop
void pilihBioskop();

// Fungsi untuk mendapatkan bioskop yang telah dipilih
bioskop getSelectedBioskop();

#endif
