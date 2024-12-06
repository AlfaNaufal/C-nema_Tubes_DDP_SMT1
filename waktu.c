// #include <stdio.h>
// #include <unistd.h>
// #include <time.h>
// #include "waktu.h"

// char translate(waktu *hari){

//     switch(hari){
//         case 0:
//             return "minggu";
//             break;
//         default:
//             return "Hari";

//     }


// }

// void tampilHari(){

//     time_t t = time(NULL);
//     struct tm *timeNow = localtime(&t);
//     int ambilHari = timeNow.tm_wday;
//     waktu *hari = translate(&ambilHari);


//     printf("Waktu Saat Ini: %s\n", hari);

// }

// void tampilTanggal(){

//     time_t t = time(NULL);
//     struct tm timeNow = *localtime(&t);
//     char tanggal[50];

//     strftime(tanggal, sizeof(tanggal), "%H:%M:%S %d %B %Y", &timeNow);

//     printf("Waktu Saat Ini: %s\n", tanggal);
//     // printf("Hari ini adalah hari %s\n", tanggal);

// }


// // void tampilWaktu(){

// //     time_t t = time(NULL);
// //     struct tm *waktu = localtime(&t);

    
// //     int a;
// //     printf("Waktu Saat ini: %d\n", waktu->tm_wday);
// //     printf("Keluar Dong\n");
// //     scanf("%d", &a);
// // }