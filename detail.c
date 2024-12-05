#include <stdio.h>
#include "detail.h"
#include "film.h"
#include "jadwal.h"


    // if(pilihanHeader == 1){

        void detail1(const char *waktuFormatted, film selectedFilm){
            
            // Menampilkan waktu sekarang, film, dan genre
            printf("========================================\n");
            printf("        Jadwal Film C'Nema             \n");
            printf("========================================\n");
            printf("Waktu Saat Ini: %s\n\n", waktuFormatted);
            printf("Film yang Anda pilih: %s\n", selectedFilm.judul);
            printf("Genre: %s\n", selectedFilm.genre);
            printf("========================================\n");

        }
        void detail2(const char *waktuFormatted, film selectedFilm, char tanggalDipilih[][30], int tanggalPilihan){

            
            // Menampilkan waktu sekarang, film, genre, dan tanggal tayang
            printf("\n========================================\n");
            printf("        Jadwal Film yang Dipilih        \n");
            printf("========================================\n");
            printf("Waktu Saat Ini: %s\n", waktuFormatted);
            printf("Film   : %s\n", selectedFilm.judul);
            printf("Genre  : %s\n", selectedFilm.genre);
            printf("Tanggal: %s\n", tanggalDipilih[tanggalPilihan - 1]);
            printf("========================================\n");

        }
        void detail3(const char *waktuFormatted, film selectedFilm, char tanggalDipilih[][30], int tanggalPilihan, const char *jamDipilih){
            
            // Menampilkan waktu sekarang, film, genre, tanggal tayang, dan jam tayang
            printf("\n========================================\n");
            printf("        Jadwal Film yang Dipilih        \n");
            printf("========================================\n");
            printf("Waktu Saat Ini: %s\n", waktuFormatted);
            printf("Film   : %s\n", selectedFilm.judul);
            printf("Genre  : %s\n", selectedFilm.genre);
            printf("Tanggal: %s\n", tanggalDipilih[tanggalPilihan - 1]);
            printf("Jam    : %s\n", jamDipilih);
            printf("========================================\n");

        }
        void detailError(){
            
            // Menampilkan detail tapi error 
            printf("\n========================================\n");
            printf("        Jadwal Film yang Dipilih        \n");
            printf("========================================\n");
            printf("Waktu Saat Ini: %s\n");
            printf("Film   : error!!\n");
            printf("Genre  : error!!\n");
            printf("Tanggal: error!!\n");
            printf("Jam    : error!!\n");
            printf("========================================\n");

        }
    // }


//     void header(int pilihHeader){

//         if(pilihanHeader == 1){


//         }else if(pilihanHeader == 2){


//         }else if (pilihanHeader == 3){


//         }else{

            
//         }
// }
