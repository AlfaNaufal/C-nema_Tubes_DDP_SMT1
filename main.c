#include<stdio.h>
#include<time.h>
#include "login.h"
#include "jadwal.h"
#include "kursi.h"
#include "bioskop.h"


int main(){
    akun A1;
    login(&A1);
    pilihFilm();
    pilihBioskop();
    pilihJadwal();
    pilihKursi();


    time_t seconds;
    seconds = time(NULL);
    printf("Hours since January 1, 1970 = %ld\n", seconds/3600);

    
    return 0;
}