#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------
    DELETE BY INDEX,
    ARRAY FROM USER FUNCTION
--------------------------------------- */
struct Arr{
    int totalSize;
    int usedSize;
};

int* createArr(struct Arr* arrStruct){
    int* arr;
    printf("enter the total size and the size you want to use\n");
    scanf("%d %d" , &(arrStruct->totalSize), &(arrStruct->usedSize));
    if((arrStruct->totalSize > 0) && (arrStruct->usedSize > 0) && (arrStruct->totalSize >= arrStruct->usedSize) ){
        arr = malloc(arrStruct->totalSize * sizeof(int));
        return arr;
    }
    return NULL;
}

void insertArray(struct Arr* arrStruct, int* arrayPtr){
    for (int i = 0; i < arrStruct->usedSize; i++){
        printf("enter the value of index %d\n", i);
        scanf("%d", (arrayPtr + i));
    }
    return;
}


void printFullArr(struct Arr* arrStruct, int* arrayPtr){
    printf("printing Full Array with total size of %d: ", (arrStruct->totalSize));
    for(int i = 0; i< arrStruct->totalSize; i++){
        printf("%d ", *(arrayPtr + i));
    }
    printf("\n");
    return;
}

void printUsedArr(struct Arr* arrStruct, int* arrayPtr){
    printf("printing Array with Used size of %d: ", (arrStruct->usedSize));
    for(int i = 0; i< arrStruct->usedSize; i++){
        printf("%d ", *(arrayPtr + i));
    }
    printf("\n");
    return;
}


void delArr(struct Arr* arrStruct, int* arrayPtr){
    int index;
    printf("enter the index, you want to delete \n");
    scanf("%d", &index);
    if (index >= arrStruct->totalSize || index < 0)
    {
        printf("the index size should less than total size and greater than 0\n");
        return;
    }
    for (int i = 0; i < arrStruct->totalSize - index; i++)
    {
        *(arrayPtr + index + i) = *(arrayPtr + index + i + 1);
    }
    arrStruct->usedSize -=1;
    return;
    

}

int main(){
    struct Arr arr1;

     int *arrptr = createArr(&arr1);
    if(arrptr == NULL){
        printf("!! alloccation fail, try diffrent values");
        return -1;
    }
    
    
    insertArray(&arr1, arrptr);
    printUsedArr(&arr1, arrptr);
    // printFullArr(&arr1, arrptr);

    // del function

    delArr(&arr1, arrptr);
    printUsedArr(&arr1, arrptr);
    // printFullArr(&arr1, arrptr);
    
    free(arrptr);
    return 0;
}
