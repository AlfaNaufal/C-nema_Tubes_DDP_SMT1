#ifndef KURSI_H
#define KURSI_H

typedef struct {
    char K[18][3]; // Maksimal 18 kursi, tiap kursi maksimal 2 karakter + null
    int harga;
} kursi;

extern kursi K1;
extern int jumlah;

int pilihKursi(); // Deklarasi fungsi utama untuk dipanggil dari main.c

#endif
