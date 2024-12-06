#include<stdio.h>
#include<time.h>
#include "login.h"
#include "jadwal.h"
#include "film.h"
#include "kursi.h"
#include "bioskop.h"
#include "pembayaran.h"


int main(){

    akun A1;
    
    login(&A1);
    pilihFilm();
    pilihBioskop();
    pilihJadwal();
    pilihKursi();
    pembayaran(&K1);

    
    return 0;
}