#include <stdio.h>
#include <string.h>
#include "txtfind.h"

#define LINE 256
#define WORD 30
#define TRUE 1
#define FALSE 0

int get_line(char *s)
{

    char c = getchar();
    int numOfChars = 0;

    if (c != '\n')
    { 
        numOfChars++;
        s[0] = c;
    }
  
    for (int i = 1; c != '\n' && i < LINE && c != '\r' && c != EOF; i++)
    {
        c = getchar();
        s[i] = c;
        numOfChars++;
    }
   // getchar();
    return numOfChars - 1;
}

int get_word(char w[])
{

    char c = getchar();
    if (c == '\n' || c == ' ' || c == '\t' || c == '\r' || c == EOF)
    {
        return -1;
    }
    int numOfChars = 0;

    for (int i = 0; c != '\n' && c != ' ' && c != '\t' && c != '\r' && i < WORD && c != EOF; i++)
    {
        w[i] = c;
        numOfChars++;
        c = getchar();
    }
    w[numOfChars] = '\0';

    return numOfChars + 1;
}

int substring(char *str1, char *str2){

    int numOfSimilarLetters = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 < len2) return 0;

    for (int i=0; i<len1-len2+1; i++){
        for (int j=0; j<len2; j++){
            if (*(str1+i+j) == *(str2+j)){
                numOfSimilarLetters++;
            }
            else break; // else move to next i 
        }
        if (numOfSimilarLetters == len2){
            return 1;
        }
        else numOfSimilarLetters = 0;
    }
    
    return 0;
}

int similar(char *s, char *t, int n)
{
    int len_s = strlen(s); // get_word(s);
    int len_t = strlen(t); // get_word(t);

    if (substring(s, t) && substring(t, s) && n == 0)
    {
        return TRUE;
    }

    if (len_s < len_t)
    {
        return FALSE;
    }

    int similar = 0;
    int i = 0, j = 0; // i->t , j->s

    while (i < len_t && j < len_s)
    {
        if (*(t + i) == *(s + j))
        {
            similar++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    if (len_s - similar == n)
    {
        return TRUE;
    }
    return FALSE;
}

void print_lines(char *str)
{
    int line_len = 1;
    int lineToPrint = FALSE;

    while (line_len != 0 && line_len != '\r')
    {
        char line[LINE] = {0};
        line_len = get_line(line);
        
        lineToPrint = substring(line, str);
        

        if (lineToPrint)
        {
            for (int i = 0; i < line_len; i++)
            {
                printf("%c", line[i]);
            }
            printf("\n");
        }
    }
}

void print_similar_words(char *str)
{
    int word_len = 0;
    int wordToPrint = FALSE;

    while (word_len != ' ' && word_len != '\t' && word_len != '\r' && word_len != '\n')
    {
        char word[WORD] = {0};
        word_len = get_word(word);
        if (word_len == -1)
        {
            return;
        }

        wordToPrint = similar(word, str, 1)||similar(word, str ,0);

        if (wordToPrint)
        {
            for (int i = 0; i < word_len; i++)
            {
                printf("%c", word[i]);
            }
            printf("\n");
        }
    }
}