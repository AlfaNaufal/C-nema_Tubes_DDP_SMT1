#include <stdio.h>
#include <string.h>
#include "film.h"

void halo(){
    printf("Hallo\n");
}
// typedef struct{
//     char judul[20];
//     char genre[20];
// }film;

// void tambahFilm(){
// void tambahFilm(const char *judul, const char *genre){
//     FILE *file;
//     int jumlah, i;
//     char judul;
//     char genre;


//     file = fopen("fileData/akun.txt", "w");
//     if (file == NULL){
//         printf("Gagal membuka file!!\n");
//         // return 1;
//     }

//     printf("Masukkan jumlah film:");
//     scanf("%d", &jumlah);

//     for (i = 0; i < jumlah; i++){
//         printf("Film tayang\n");

//         printf("Masukkan Judul Film: ");
//         scanf("%s", &judul);

//         printf("Masukkan Genre Film: ");
//         scanf("%s", &genre);

//         fprintf(file, "%s,%s", judul, genre);
//     }

//     fclose(file);
// }


