#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------
    SIMPLE PROGRAM TO DELETE BY INDEX
--------------------------------------- */

int main(){
    int arr[10] = {1,2,3,4,5,6};

    int index, n, usedSize = 6;
    // n = sizeof(arr)/sizeof(arr[0]); // size of arr

    // remove by index
    printf("enter the index you want to remove\n");
    scanf("%d", &index);

    for (int i = 0; i < usedSize - index; i++)
    {
        arr[index + i] = arr[index + i + 1];
    }
    usedSize -= 1;

    for (int i = 0; i < usedSize; i++)
    {
        printf("%d ", arr[i]);
    }
    
    
    return 0;
}
