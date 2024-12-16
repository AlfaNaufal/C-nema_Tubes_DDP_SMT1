#ifndef REKAP_H
#define REKAP_H

#include "film.h"    // Untuk tipe data film
#include "bioskop.h" // Untuk tipe data bioskop
#include "kursi.h"   // Untuk tipe data kursi

void simpanRekapitulasi(const char *waktuFormatted, 
                        film selectedFilm, 
                        bioskop selectedBioskop, 
                        char tanggalDipilih[][30], 
                        int tanggalPilihan, 
                        const char *jamDipilih, 
                        kursi *K1, 
                        int jumlah, 
                        int totalBayar);
void tampilRekapitulasi();
void tampilRekapitulasiHarian(const char *tanggal);
void tampilRekapitulasiBulanan(int bulan, int tahun);
void tampilRekapitulasiTahunan(int tahun);

#endif
