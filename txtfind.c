#include <stdio.h>
#include "txtfind.h"

#define LINE 256

int getline(char s[]){
    int numOfChars=0;
    for (int i = 0; i < LINE; i++)
    {
        if(*(s+i)!='\t' && *(s+i)!= '\n' && *(s+i)!=' '){
            numOfChars++;
        }
    }
    return numOfChars;
}