#include <stdio.h>
#include <stdlib.h>

struct  Arr
{
    int size; // total size of array
    int usedSize; //size that is used by user
};


// creating array with using malloc and sending the address of array 0th element
// int n => is the usedSize that user wants to use,
int* createArr(int n){
    int* ptr;
    ptr = malloc(n*sizeof(int));
    return ptr;
}


int main(){
    // init arr1 structue
    struct Arr arr1; 

    // getting value of arr.size & arr.usedSize from user 
    // for example : arr.size = 10; arr.usedSize = 5;
    printf("enter num of total size and size you want to use : \n");
    scanf("%d %d", &arr1.size, &arr1.usedSize);
      if(arr1.usedSize > arr1.size) {
        printf("total size can't be greater than the size you want to use");
        return -1;
    }

    // calling creating array function
    int* arrptr = createArr(arr1.size);

    // checking if address return is null or not,
    // exit program is memory allocation fails
    if(arrptr == NULL) {
        printf("array creation  fail");
        return -1;
    }
    
    // data insert 
    // note: i'm not making function to insert array, as i already made in create-insert-array.c, here focus is on array using structure,
    for (int i = 0; i < arr1.usedSize; i++)
    {
        printf("enter the value of index %d\n", i);
        scanf("%d", (arrptr +i));
    }
    
    // printing array
    // note: i'm not making function to print array, as i already made in create-insert-array.c, here focus is on array using structure,
    for (int i = 0; i < arr1.usedSize; i++)
    {
        printf("%d ", *(arrptr + i));
    }
    
    // free memory
    free(arrptr);

    // ends
    return 0;
}
