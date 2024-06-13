#include <stdio.h>
#include <stdlib.h>
#define EXTRA 3  //extra 3 space to opform other operations like adding new data

 int createArr(int n, int **arr){   //[100],  [299] = 100
    *arr = (int*) malloc( (n + EXTRA) * sizeof(int));
    if(*arr == NULL) return -1;
    else return 1;
}

void insertArr(int n, int* arr){
    for (int i = 0; i < n; i++)
    {
        printf("\nenter %d no: ", i);
        scanf("%d", (arr + i));
    }
    
}

int printArr(int n, int* arr){
    int count=0;

    printf("\nArray is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
        count++;
    }
    return count;
}


int main(){
    int n, *arr;
    printf("Enter no of data you want to store: ");
    scanf("%d", &n);

    if(createArr(n, &arr) == -1){
        printf("malloc fail");
        return 1; //exit malloc fail
    }

    insertArr(n, arr);
    int sizeUsed = printArr(n, arr);

    printf("\nyour array size is %d, used size is %d", (n + EXTRA), sizeUsed);
    free(arr);
    return 0;
}