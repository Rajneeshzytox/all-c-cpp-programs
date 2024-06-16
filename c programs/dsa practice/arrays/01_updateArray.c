#include <stdio.h>
#include <stdlib.h>

// add the element at a index while maintaining the order;
// see array-usimg-structure first

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
    printf("printing Full Array with total size of %d:\t", (arrStruct->totalSize));
    for(int i = 0; i< arrStruct->totalSize; i++){
        printf("%d ", *(arrayPtr + i));
    }
    printf("\n");
    return;
}

void printUsedArr(struct Arr* arrStruct, int* arrayPtr){
    printf("printing Array with Used size of %d:\t", (arrStruct->usedSize));
    for(int i = 0; i< arrStruct->usedSize; i++){
        printf("%d ", *(arrayPtr + i));
    }
    printf("\n");
    return;
}

// --------------------------  ARRAY UPDATE  --------------------------
void update_at_index(struct Arr* arrStruct, int* arrayPtr){
    int num, index;
    printf("enter value you want to add: ");
    scanf("%d", &num);
    printf("\nEnter the index, (where you want to add %d): ", num);
    scanf("%d", &index);

    if((index >= arrStruct->totalSize) || (index < 0)){
        printf("!!index should be greater than 0 and less than array total size\n");
        return;
    }

    if(arrStruct->usedSize >= arrStruct->totalSize ){
        printf("!! array is full, cant add more value\n");
        return;
    }

    //  0 1 2 3 4 5
    for (int i = (arrStruct->totalSize - 1); i > index; i--){
            *(arrayPtr + i) = *(arrayPtr + (i-1));
    }
    
    *(arrayPtr + index) = num;
    arrStruct->usedSize +=1;
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
    printFullArr(&arr1, arrptr);

    // calling update function
    update_at_index(&arr1, arrptr);
    printUsedArr(&arr1, arrptr);
    printFullArr(&arr1, arrptr);
    free(arrptr);
    return 0;
}