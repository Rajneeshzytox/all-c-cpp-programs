#include <stdio.h>

// fun to insert array
void insertArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("enter the %d index value\n", i);
        scanf("%d", (arr + i));
    }
}
// fun to print array
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

// print sum of array
void arraySum(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(arr + i);
    }
    printf("The sum is %d", sum);
}

int main()
{
    // hard coded array
    printf("\n\t\t CUSTOM ARRAY");
    int arr2[] = {2, 5, 1, 2, 10, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("\n size is %d\n", size2);
    printArray(arr2, size2);
    arraySum(arr2, size2);

    // value from user
    int n;
    printf("Enter the size of array");
    scanf("%d", &n);
    int arr[n];
    int size = getSize(arr);

    insertArray(arr, size);
    printArray(arr, size);
    arraySum(arr, size); // print sum

    return 0;
}