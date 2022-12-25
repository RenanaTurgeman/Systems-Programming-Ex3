#include <stdio.h>


void shift_element(int *arr, int i){
    int last_index= i;
    while (last_index>0)
    {
        *(arr+ last_index)= *(arr+ last_index-1);
        last_index--;
    }
}   

void print_arr (int *arr , int len){
    for (int i = 0; i < len; i++)
    {
        if(i != len-1){
            printf("%d,", *(arr+i));
        }
        else{
           printf("%d", *(arr+i));
        }
    }
}

void insertion_sort(int *arr, int len){
    int key,j,i;
    int shift=0;

    for (i=1 ; i < len; i++)
    {
        key =*(arr+i);
        j= i-1;

        while (j>=0 && *(arr+j)>key)
        {
            shift++;
            j--;
        }
        
        if (shift>0)
        {
            int *pointer = arr+j+1;
           shift_element(pointer, shift);
           *(arr+(i-shift)) =key;
           shift=0;
        }
        
    }
    
    print_arr(arr , len);        
       
}
