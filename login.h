#ifndef login_h
#define login_h

typedef struct {
    int pilih;
    char username[50];
    char password[50];
} akun;

int login(akun *A1);

#endif
