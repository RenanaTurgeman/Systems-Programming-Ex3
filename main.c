#include <stdio.h>
#include "isort.h"

#define SIZE 50

//int argc, char const *argv[]
int main()
{
    //check shift elemnt
    // int arr[]= {1,2,3,4,5};
    // shift_element(arr,5);
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d ", arr[i] );
    // }

    //chek insertion sort
    int arr[]={7,8,5,2,4,6,3};
    insertion_sort(arr,7);
    
    return 0;
}
