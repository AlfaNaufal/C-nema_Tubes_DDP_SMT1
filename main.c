#include<stdio.h>
#include<time.h>
#include "login.h"
#include "jadwal.h"
#include "film.h"
#include "kursi.h"

int main(){

    akun A1;
    
    login(&A1);
    pilihFilm();
    pilihJadwal();
    pilihKursi();

    
    return 0;
}