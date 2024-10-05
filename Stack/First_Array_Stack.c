#include <stdio.h>

void push(int num, int* arr, int* top, int max){
    if(*top == max -1){
        printf("overflow");
        return;
    }
    *top = *top + 1;
    *(arr + *top) = num;
    return;
}

int peek(int* arr, int top){
    printf("\n%d\n", *(arr + top));
    return *(arr + top);
}

void pop(int* arr, int* top){
    if(*top == -1){
        printf("underflow");
        return;
    }
    *top -= 1;
    return;
}

void printArr(int* arr, int top, int size){
    printf("\n printing array...\n ");
    for(int i = 0; i <= top; i++){
        printf("%d, ", *(arr + i));
    }

}

int main(){
    int max = 5;
    int top = -1;
    int a[max];

    // entering value 1-6 in array stack
    for(int i = 0; i < max; i++){
        push(i+1, a, &top, max);
    }

    // printing array stack
    printArr(a, top, max);
    
    // deleting 3 value in array stack
    for(int i = 0; i < 3; i++){
       pop(a, &top);
    }
    printArr(a, top, max);



    return 0;
}