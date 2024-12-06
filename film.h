#ifndef film_h
#define film_h

// Struktur untuk menyimpan data film
typedef struct {
    int pilih;  // Pilihan film
    char judul[100]; // Judul film
    char genre[50];  // Genre film
} film;

extern film selectedFilm;

// Deklarasi fungsi untuk memilih film
void pilihFilm();
film getSelectedFilm(); // Fungsi untuk mendapatkan film yang dipilih

#endif
