#include <stdio.h>
#include <time.h>
#include "login.h"
#include "home.h"
#include "jadwal.h"
#include "film.h"
#include "kursi.h"
#include "bioskop.h"
#include "pembayaran.h"
#include "homeAdmin.h"

int main() {
    akun A1; // Struktur akun
    int statusLogin; // Menyimpan status login (1 = admin, 2 = pelanggan)

    statusLogin = login(&A1); // Login dan menentukan jenis pengguna (admin atau pelanggan)

    if (statusLogin == 1) {
        // Jika login sebagai admin, panggil halaman admin
        halamanAdmin();
    } else if (statusLogin == 2) {
        // Jika login sebagai pelanggan, jalankan alur pelanggan
        tampilkanHome();
        pilihFilm();
        pilihBioskop();
        pilihJadwal();
        pilihKursi();
        pembayaran();
    } else {
        printf("Kesalahan login. Aplikasi akan ditutup.\n");
    }

    return 0;
}
