shift_element(int *arr, int i){
    int last_index= i;
    while (last_index>0)
    {
        *(arr+ last_index)= *(arr+ last_index-1);
        last_index--;
    }
}   

insertion_sort(int *arr, int len){
    
}
