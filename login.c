#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include "login.h"


int login(akun * A1 ){
    
    void delay_seconds(int seconds) {
    time_t start_time = time(NULL);
    while (time(NULL) < start_time + seconds);
}
    bool isValid = true;


    while (isValid){
    
    printf("1.Login\n2.Sign Up\n");
    scanf("%d", &((* A1).pilih));
    if ( ((*A1).pilih) == 1){


        printf("--------Login--------\n");
        printf("masukkan username= ");
        scanf("%s", &((* A1).username));
        printf("masukkan password= ");
        scanf("%s", &((* A1).password));
        isValid = !isValid;
        system("cls");

        
    }else if ( ((*A1).pilih) == 2){
    
        printf("--------SignUp--------\n");
        printf("masukkan username= ");
        scanf("%s", &((* A1).username));
        printf("masukkan password= ");
        scanf("%s", &((* A1).password));
        isValid = !isValid;
        system("cls");
        ((*A1).pilih) = 1
    
    }else{
        printf("Error 404: Option Not Found!! ");
        delay_seconds(3);
        system("cls");

    }
}

    }
