#include <stdio.h>
#include "txtfind.h"

#define LINE 256
#define WORD 30
#define TRUE 1
#define FALSE 0

// int getline(char s[]){
    
//     int numOfChars=0;
//     for (int i = 0; i < LINE ; i++)
//     {
        
//         if(*(s+i)!= '\n'){
//             numOfChars++;
//         }else{
//             break;
//         }
//     }
//     *(s+255)= '\0';

//     return numOfChars;
// }

// int getword(char w[]){

//     int numOfChars=0;
//     for (int i = 0; i < WORD ; i++)
//     {
        
//         if(*(w+i)!= '\n'){
//             numOfChars++;
//         }else{
//             break;
//         }
//     }
//     *(w+29)= '\0';

//     return numOfChars;
// }

int substring(char *str1 , char *str2){
    int len_str1 = getword(str1);
    int len_str2 = getword(str2);
    int counter=0;
    int i =0;

    
    for (int j = 0; j < len_str1 && (len_str2-i)!=0; j++)
    {
        if (*(str2+i)== *(str1+j))
        {
            counter++;
            i++;
        }   
    }  
    
    
    if(counter == len_str2){
        return TRUE;
    }
    return FALSE;
}