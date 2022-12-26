#include <stdio.h>
#include <string.h> // if we use strlen
#include "txtfind.h"

#define LINE 256
#define WORD 30
#define TRUE 1
#define FALSE 0

int get_line(char *s){
    printf("Enter a line:");
    char c = getchar();
    int numOfChars=0;

    if (c != '\n'){ //is it neccecary? 
        numOfChars++;
        s[0] = c;
    }

    for(int i=1; c != '\n' && i<LINE && c != EOF; i++){
        c = getchar();
        s[i] = c;
        numOfChars++;
    }
    return numOfChars-1;
}


int get_word(char w[]){
    printf("Enter a word:");
    char c = getchar();
    if (c == '\n' || c == ' ' || c == '\t' || c == EOF) {
        return -1;
    }
    int numOfChars = 0;
    
    for(int i=0; c != '\n' && c != ' ' && c != '\t' && i<WORD && c != EOF ;i++){
        w[i] = c;
        numOfChars++;
        c = getchar();
    }

    return numOfChars;
}


int substring(char *str1 , char *str2){
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int counter=0;
    int i =0;

    if(len_str1< len_str2){
        return FALSE;
    }

    
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

int similar(char *s , char *t, int n){
    int len_s= strlen(s);//get_word(s);
    int len_t =strlen(t); //get_word(t);

    if(substring(s,t)&& substring(t,s)&&n==0){
        return TRUE;
    }

     if (len_s < len_t){
        return FALSE;
     } 

     int similar =0;
     int i=0 , j=0; //i->t , j->s

     while (i<len_t && j<len_s)
     {
        if(*(t+i) == *(s+j)){
            similar++;
            i++;
            j++;
        }else{
            j++;
        }
     }
     if (len_s - similar == n){
        return TRUE;
     }
     return FALSE; 
     
}

void print_lines(char * str){
    int line_len = 0;
    int lineToPrint = FALSE;

    while (line_len !=1)
    {        
        char line[LINE] = {0}; 
        line_len = get_line(line);
        lineToPrint = substring(line, str);

         if (lineToPrint)
         {
        for (int i = 0; i < line_len; i++){
                printf("%c",line[i]);
            }
         }
    }
}


void print_similar_words(char *str){
    int word_len = 0;
    int wordToPrint = FALSE;

    while (word_len != 1)
    {
        char word[WORD] = {0};
        word_len = get_word(word);
        if (word_len == -1)
        {
            return; 
        }
        wordToPrint = similar(word,str,1);

        if (wordToPrint)
        {
            for (int i = 0; i < word_len; i++)
            {
                printf("%c",word[i]);
            }
            printf("\n");
        }
    }
}