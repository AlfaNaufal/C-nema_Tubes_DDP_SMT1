#include <stdio.h>
#include "detail.h"
#include "bioskop.h"
#include "film.h"
#include "jadwal.h"
#include "kursi.h"



        void detail1(film selectedFilm){
            
            // Menampilkan waktu sekarang, film, dan genre
            printf("========================================\n");
            printf("        Detail Pembelian C'Nema         \n");
            printf("========================================\n");
            // printf("Waktu Saat Ini: %s\n\n", waktuFormatted);
            printf("Film yang Anda pilih: %s\n", selectedFilm.judul);
            printf("Genre: %s\n", selectedFilm.genre);
            printf("========================================\n");

        }

        void detail2(const char *waktuFormatted, film selectedFilm, bioskop selectedBioskop){

            
            // Menampilkan waktu sekarang, film, genre, dan tanggal tayang
            printf("========================================\n");
            printf("        Detail Pembelian C'Nema         \n");
            printf("========================================\n");
            printf("Waktu Saat Ini: %s\n", waktuFormatted);
            printf("Film   : %s\n", selectedFilm.judul);
            printf("Genre  : %s\n", selectedFilm.genre);
            printf("Bioskop: %s - %s\n", selectedBioskop.namaMall, selectedBioskop.jenisBioskop);
            printf("========================================\n");

        }

        void detail3(const char *waktuFormatted, film selectedFilm, bioskop selectedBioskop, char tanggalDipilih[][30], int tanggalPilihan){

            
            // Menampilkan waktu sekarang, film, genre, dan tanggal tayang
            printf("========================================\n");
            printf("        Detail Pembelian C'Nema         \n");
            printf("========================================\n");
            printf("Waktu Saat Ini: %s\n", waktuFormatted);
            printf("Film   : %s\n", selectedFilm.judul);
            printf("Genre  : %s\n", selectedFilm.genre);
            printf("Bioskop: %s - %s\n", selectedBioskop.namaMall, selectedBioskop.jenisBioskop);
            printf("Tanggal: %s\n", tanggalDipilih[tanggalPilihan - 1]);
            printf("========================================\n");

        }


        void detail4(const char *waktuFormatted, film selectedFilm, bioskop selectedBioskop, char tanggalDipilih[][30], int tanggalPilihan, const char *jamDipilih){
            
            // Menampilkan waktu sekarang, film, genre, tanggal tayang, dan jam tayang
            printf("========================================\n");
            printf("        Detail Pembelian C'Nema         \n");
            printf("========================================\n");
            printf("Waktu Saat Ini: %s\n", waktuFormatted);
            printf("Film   : %s\n", selectedFilm.judul);
            printf("Genre  : %s\n", selectedFilm.genre);
            printf("Bioskop: %s - %s\n", selectedBioskop.namaMall, selectedBioskop.jenisBioskop);
            printf("Tanggal: %s\n", tanggalDipilih[tanggalPilihan - 1]);
            printf("Jam    : %s\n", jamDipilih);
            printf("========================================\n");

        }
        
        void detail5(const char *waktuFormatted, film selectedFilm, bioskop selectedBioskop, char tanggalDipilih[][30], int tanggalPilihan, const char *jamDipilih, kursi *K1, int jumlah){
            
            // Menampilkan waktu sekarang, film, genre, tanggal tayang, dan jam tayang
            printf("========================================\n");
            printf("        Detail Pembelian C'Nema         \n");
            printf("========================================\n");
            printf("Waktu Saat Ini: %s\n", waktuFormatted);
            printf("Film   : %s\n", selectedFilm.judul);
            printf("Genre  : %s\n", selectedFilm.genre);
            printf("Bioskop: %s - %s\n", selectedBioskop.namaMall, selectedBioskop.jenisBioskop);
            printf("Tanggal: %s\n", tanggalDipilih[tanggalPilihan - 1]);
            printf("Jam    : %s\n", jamDipilih);
            printf("Kursi  : ");
            for (int i = 0; i < jumlah; i++) {
                printf("%s ", K1->K[i]);
            }
            printf("\n========================================\n");

        }

        // void detailError(){
            
        //     // Menampilkan detail tapi error 
        //     printf("\n========================================\n");
        //     printf("        Jadwal Film yang Dipilih        \n");
        //     printf("========================================\n");
        //     printf("Waktu Saat Ini: %s\n");
        //     printf("Film   : error!!\n");
        //     printf("Genre  : error!!\n");
        //     printf("Tanggal: error!!\n");
        //     printf("Jam    : error!!\n");
        //     printf("========================================\n");

        // }

        void detailPembayaran(const char *waktuFormatted, film selectedFilm, bioskop selectedBioskop, char tanggalDipilih[][30], int tanggalPilihan, const char *jamDipilih){
            
            // Menampilkan waktu sekarang, film, genre, tanggal tayang, dan jam tayang
            printf("========================================\n");
            printf("        Detail Pembelian Tiket         \n");
            printf("========================================\n");
            printf("Waktu Saat Ini: %s\n", waktuFormatted);
            printf("Film   : %s\n", selectedFilm.judul);
            printf("Genre  : %s\n", selectedFilm.genre);
            printf("Bioskop: %s - %s\n", selectedBioskop.namaMall, selectedBioskop.jenisBioskop);
            printf("Tanggal: %s\n", tanggalDipilih[tanggalPilihan - 1]);
            printf("Jam    : %s\n", jamDipilih);
            printf("========================================\n");

        }