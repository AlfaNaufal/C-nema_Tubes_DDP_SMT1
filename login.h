#ifndef login_h
#define login_h


typedef struct {
    int pilih;
    char username;
    char password;
} akun;

int login(akun * A1 );

#endif