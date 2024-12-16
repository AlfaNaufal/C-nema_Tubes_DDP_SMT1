#ifndef pembayaran_h
#define pembayaran_h


typedef struct{

    int idPembelian;
    int jumlahTiket;
    int hargaTiket;
    int totalHarga;
    


} bayar;

void pembayaran();
float hitungtTotalHarga();
float hitungtKembalian();
int validasiPembayaran();

 


#endif