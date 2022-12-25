#include <stdio.h>
#include "txtfind.h"

int main(){
    
    //char str[]= "hello";
    //char str1[] = "yt";
    char s[30]="swsystems";
    char r[30]="swsystems";
    // char r[30]="ssysems";
    // printf("%d" ,get_word(s));
    printf("%d", similar(s,r,0));

    return 0 ;
}