#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top; // top of stack
    int max; // no of element or size of stack 
    int* arrPtr;
} STACK;

void createArr(STACK* s, int max){
    int arrSize = sizeof(int) * max; // memory size of array
    s->arrPtr = (int*) malloc(arrSize);
    if(s->arrPtr == NULL){
        printf("\nmemory alloc fail\n");
        exit(-1);
    }
    s->max = max;
    s->top = -1;

    return ;
}

void freeArr(STACK* s){
    free(s->arrPtr);
}

void push(STACK* s, int num){
    if (s->top == s->max -1)
    {
        printf("\noverflow cant add more elements\n");
        return;
    }
    s->top += 1;
    *(s->arrPtr + s->top) = num;
    return;
}

void pop(STACK* s){
    if (s->top == -1)
    {
       printf("\nunderflow cant delete more\n");
       return;
    }
    s->top -= 1;
}

int showTop(STACK* s){
    printf("%d ", *(s->arrPtr + s->top));
    printf("\n");
    return *(s->arrPtr + s->top);
}

void peek(STACK* s, int index){
    if(index > s->max){
        printf("\nindex not available\n");
        return;
    }
    printf("%d ", *(s->arrPtr + index));
    printf("\n");
}

void display(STACK* s){

    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", *(s->arrPtr + i));
    }
    printf("\n");
    
}

void showOption(){
    printf("Choose an option: \n");
    printf("1. push an element\n");
    printf("2. pop an element\n");
    printf("3. peek an index\n");
    printf("4. show top element\n");
    printf("5. display stack\n");
    printf("6. exit\n");
    printf("7. Show options\n");
}

void option(STACK* s){
    int option;
    printf(">>> Enter your option: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        printf("\nnter the num, you want to push: ");
        int num;
        scanf("%d", &num);
        push(s, num);
        break;

    case 2:
        pop(s);
        printf("\n1 Element pop out of stack");
        break;

    case 3:
        printf("\nnter the index, you want to peek: ");
        int index;
        scanf("%d", &index);
        peek(s, index);
        break;

    case 4:
        printf("\ntop element is: ");
        showTop(s);
        printf("\n");
        break;
    
    case 5:
        display(s);
        break;

    case 6:
        freeArr(s);
        exit(0);
        break;

    case 7:
        showOption();
        break;

    default:
        printf("\nenter a valid option");
        break;
    }
}

int main(){
    STACK a;
    printf("Welcome! We are creating a stack for you\nEnter size of array\n>>>  ");
    int sizeOfStack;
    scanf("%d", &sizeOfStack);
    createArr(&a, sizeOfStack); //createArr(STACK* s, int max)
    
    showOption();
    while (1==1){
        option(&a);
    }
    
    return 0;
}