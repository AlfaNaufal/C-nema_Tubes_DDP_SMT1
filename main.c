#include<stdio.h>
#include<time.h>
#include "login.h"
#include "login.c"


int main(){
    akun A1;
    login(&A1);


    time_t second;
    seconds = time(NULL);
    printf("Hours since January 1, 1970 = %ld\n", seconds/3600);

    
    return 0;
}