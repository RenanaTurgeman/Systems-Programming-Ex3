#include <stdio.h>
#include "isort.h"

#define SIZE 50

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", arr+i);
    }
    
    insertion_sort(arr, SIZE);
    
    return 0;
}
