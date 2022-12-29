#include <stdio.h>
#include "txtfind.h"
#define WORD 30

int main(){
    // printf("hello");

    char word[WORD]={0};
    get_word(word);
    // printf("%s",word);
    char option = getchar();
    getchar();
    getchar();
    getchar();

    if ( option == 'a'){
        print_lines(word);
    }
    else if (option == 'b')
    {
        print_similar_words(word);
    }
    return 0 ;
}