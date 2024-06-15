#include <stdio.h>
#include <stdlib.h>

// see my other code file: array-using-structure first
// FUNCTION => appendArray(arr, struct Arr* arr1,   num); add num at last


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

// appendArray()
int appendArray(int* arr, struct Arr* arr1, int num){
    if((arr1->size) == (arr1->usedSize)){
        printf("array is full, can't add new num\n");
        return 0;
    }
    else{
        
        *(arr + (arr1->usedSize)) = num;
        arr1->usedSize += 1;
        return 1;
    }
}


// UPDATED FUNCTION GETTING VALUE FROM USER
void appendArray_fromUser(int* arr, struct Arr* arr1){
    if((arr1->size) == (arr1->usedSize)){
        printf("array is full, can't add new num\n");
        return;
    }
    else{
        int num;
        printf("enter the value you want to add in end of array\n");
        scanf("%d", &num);
        *(arr + (arr1->usedSize)) = num;
        arr1->usedSize += 1;
        return;
    }
}

int main(){
    
    struct Arr arr1;
    printf("enter num of total size and size you want to use : \n");
    scanf("%d %d", &arr1.size, &arr1.usedSize);

    // calling creating array function
    int* arrptr = createArr(arr1.size);
    if(arrptr == NULL) {
        printf("array creation  fail");
        return -1;
    }
    
    // data insert 
    for (int i = 0; i < arr1.usedSize; i++)
    {
        printf("enter the value of index %d\n", i);
        scanf("%d", (arrptr +i));
    }
    // initial array: printing array
    for (int i = 0; i < arr1.usedSize; i++)
    {
        printf("%d ", *(arrptr + i));
    }

    // calling appendArray, appendArray(arr, arr1  num)
    printf("\ncalling append Array function.........\n");
    appendArray(arrptr, &arr1, 6);

     // printing array after append 
    for (int i = 0; i < arr1.usedSize; i++)
    {
        printf("%d ", *(arrptr + i));
    }


    // append value from user function
    printf("\ncalling append Array from User function.........\n");
    appendArray_fromUser(arrptr, &arr1);
    // printing array after append from user
    for (int i = 0; i < arr1.usedSize; i++)
    {
        printf("%d ", *(arrptr + i));
    }
    
    free(arrptr);
    return 0;
}
