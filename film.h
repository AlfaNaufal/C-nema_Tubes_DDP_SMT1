#ifndef film_h
#define film_h


typedef struct {
    int pilih;
    char judul[100];
    char genre[50];
} film;

void pilihFilm();

#endif