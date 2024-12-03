#include<stdio.h>
#include<time.h>
#include "login.h"


int main(){
    akun A1;
    login(&A1);


    time_t seconds;
    seconds = time(NULL);
    printf("Hours since January 1, 1970 = %ld\n", seconds/3600);

    
    return 0;
}