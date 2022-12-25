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
        printf("%d,", *(arr+i));
    }
}

void insertion_sort(int *arr, int len){
    int i=1;
    int key=0;
    int j=0;
    int shift=0;

    for ( i ; i < len; i++)
    {
        key =*(arr+i);
        j--;

        while (j>=0 && *(arr+j)>key)
        {
            shift++;
            j--;
        }
        
        if (shift>0)
        {
           shift_element(*(arr+j+1), shift);
           *(arr+(i-shift)) =key;
           shift=0;
        }
        
    }
    
    print_arr(arr , len);        
       
}
