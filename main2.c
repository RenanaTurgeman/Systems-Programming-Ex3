#include <stdio.h>
#include "txtfind.h"
#define WORD 30

int main(){
    // printf("hello");

    char word[WORD]={0};
    get_word(word);
    // printf("%s",word);
    char option = getchar();
    printf("-%c\n",getchar());
    printf("-%c\n",getchar());
    printf("-%c\n",getchar());

    if ( option == 'a'){
        print_lines(word);
    }
    // else if (option == 'b')
    // {
    //     print_similar_words(word);
    // }





    // char text[] = "this is a text file\n
    //                 looking for the word cat\n
    //                 the program should print also cats\n
    //                 after cats crat and lcat are printed\n
    //                 the program shouldn't print\n
    //                 the word caats";
   // printf("%s",text);
    // print_lines("cat");


    //char str[]= "hello";
    //char str1[] = "yt";
    // char s[30]="swsystems";
    // char r[30]="swsystems";
    // char r[30]="ssysems";
    // printf("%d" ,get_word(s));
    // printf("%d", similar(s,r,0));

    //char word[] = "is is a text file looking for the word cat the program should print also cats after cats crat and lcat are printed the program shouldn’t print he word caats";
    //get_word(word);

    //print_lines(word);
    return 0 ;
}