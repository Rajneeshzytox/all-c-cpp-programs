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
    return;
}

void insertArr(int* ptr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("enter %d element :\n", i);
        scanf("%d", (ptr + i));
    }
    printf("\n");
    return;
}

void addeArr_atIndex(int* arr, struct Arr* arr1, int index, int num){
    if(arr1->size == arr1->usedSize){
        printf("array is full, can't addd\n");
        return;
    }
    else{
        *(arr + (arr1->usedSize)) = *(arr + index);
        *(arr + index) = num;
        arr1->usedSize +=1;
        return;
    }
}


void addArray_atIndex_fromUser(int* arr, struct Arr* arr1){
    if(arr1->usedSize >= arr1->size){
        printf("array is full can't add new value\n");
        return;
    }
    else{
        int index, num;
        printf("Enter value you want to add: ");
        scanf("%d", &num);
        printf("enter index value (where you want to add %d)", num);
        scanf("%d", &index);

        *(arr + (arr1->usedSize)) = *(arr + index);
        *(arr + index) = num;
        arr1->usedSize +=1;
        printf("\n added %d at index %d\n", num, index);
        return;
    }
}

int main(){

    struct Arr arr1;
    printf("enter num of total size and size you want to use : \n");
    scanf("%d %d", &arr1.size, &arr1.usedSize);

    if(arr1.usedSize > arr1.size || !(arr1.usedSize > 0) || !(arr1.size >0)) {
        printf("total size should be always greater or equal to size you want to use\ntotal size should be at least 1\n size that you want to use should be greater than  0\n");
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
    
    // **************** update array start *********************
    
    // addeArr_atIndex(arrptr, &arr1, index, num);
    printf("\n running addedArr_atIndex function......\n");
    addeArr_atIndex(arrptr, &arr1, 2, 33);
    printf("\n added 33 at index 2\n");
    printArr(arrptr, arr1.usedSize);

    // addArray_atIndex_fromUser(int* arr, struct Arr* arr1)
    printf("\n running  addArray_atIndex_fromUser function......\n");
    addArray_atIndex_fromUser(arrptr, &arr1);
    printArr(arrptr, arr1.usedSize);


    free(arrptr);
    return 0;
}
