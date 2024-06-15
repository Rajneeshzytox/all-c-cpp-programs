#include <stdio.h>
#include <stdlib.h>

//  update array at a index and order not follow function
// see array-using-struct file first 

struct  Arr
{
    int size;
    int usedSize;
};
int* createArr(int n){
    int* ptr;
    ptr = malloc(n*sizeof(int));
    return ptr;
}

void printArr(int* ptr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

void insertArr(int* ptr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("enter %d element :\n", i);
        scanf("%d", (ptr + i));
    }
    printf("\n");
}

void addeArr_atIndex(int* arr, struct Arr* arr1, int index, int num){
    if(arr1->size == arr1->usedSize){
        printf("array is full, can't addd");
        return;
    }
    else{
        *(arr + (arr1->usedSize)) = *(arr + index);
        *(arr + index) = num;
        arr1->usedSize +=1;
        return;
    }
}

int main(){

    struct Arr arr1;
    printf("enter num of total size and size you want to use : \n");
    scanf("%d %d", &arr1.size, &arr1.usedSize);

    if(arr1.usedSize > arr1.size) {
        printf("total size can't be greater than the size you want to use");
        return -1;
    }

    int* arrptr = createArr(arr1.size);
    if(arrptr == NULL) {
        printf("array creation  fail");
        return -1;
    }
    
    // getting value and printing
    insertArr(arrptr, arr1.usedSize);
    printArr(arrptr, arr1.usedSize);
    
    // update arr start
    addeArr_atIndex(arrptr, &arr1, 2, 33);
     printArr(arrptr, arr1.usedSize);

    free(arrptr);
    return 0;
}
