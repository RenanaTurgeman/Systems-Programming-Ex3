#include <stdio.h>
#include "isort.h"

//int argc, char const *argv[]
int main()
{
    int arr[]= {1,2,3,4,5};
    shift_element(arr,5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i] );
    }
    
    return 0;
}
