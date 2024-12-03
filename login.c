#include<stdio.h>
#include "login.h"


int login(akun * A1 ){
    printf("1.Login\n2.Sign Up\n");
    scanf("%d", &((* A1).pilih));
    if (((*A1).pilih)==1);
    {
        printf("masukkan username= ");
        scanf("%s", &((* A1).username));
        printf("masukkan password= ");
        scanf("%s", &((* A1).password));
    }
    

}