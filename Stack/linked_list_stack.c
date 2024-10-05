#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node* next;
} NODE;


// stackk info - struct
typedef struct Stack{
    struct node* topPtr;
    int top;
    int max;
} STACK;


NODE* createNode(STACK* s,int data){
    NODE* temp = malloc(sizeof(NODE));
    temp->next = s->topPtr;
    temp->data = data;
    return temp;
}


void init_stack(STACK*s){
    s->topPtr = NULL;
    s->top = -1;
    printf("\nenter the size of the stack: ");
    int tempSize;
    scanf("%d", &tempSize);
    s->max = tempSize;
}


void push(STACK* s, int num){
    if(s->top == s->max - 1){
        printf("!!! Stack is full Cant add more value\n");
        return;
    }
    s->topPtr = createNode(s, num);
    s->top += 1;
}


void display(STACK* s){
    if (s->topPtr == NULL)
    {
        printf("list is empty add some value first\n");
        return;
    }
    
    NODE* ptr = s->topPtr;
    while (ptr != NULL)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    
}


void delete_stack(STACK* s){
    NODE* ptr; 
    while (s->topPtr != NULL)
    {
        ptr = s->topPtr;
        s->topPtr = ptr->next;
        free(ptr);
    }
    printf("Stack is deleted\n");
    
    return;
}


void pop(STACK* s){
    if (s->top == -1)
    {
        printf("list empty\n");
        return;
    }
    NODE* temp = s->topPtr;
    s->topPtr = s->topPtr->next;
    free(temp);
}


void peek(STACK* s, int index){
    if(index >= s->max || index < 0){
        printf("invalid index %d\n", index);
        return;
    }
    int count = s->max - 1 - index;
    NODE* ptr = s->topPtr;
    for (int i = 0; i < count; i++)
    {
        ptr = ptr->next;
    }
    printf("Value at index no %d is %d\n", index, ptr->data);
    
}


void showTop(STACK* s){
    printf("value at top (index: %d) is %d\n", s->top, s->topPtr->data);
}



int main(){
    STACK s1;
    init_stack(&s1);
    push(&s1, 3);
    push(&s1, 6);
    push(&s1, 9);
    showTop(&s1);
    push(&s1, 12);
    showTop(&s1);
    display(&s1);

    // pop
    pop(&s1);
    pop(&s1);
    display(&s1);

    peek(&s1, 0);
    peek(&s1, 1);
    peek(&s1, 2);
    peek(&s1, 3);
    peek(&s1, 4);
    peek(&s1, 5);


    delete_stack(&s1);
    display(&s1);
    return 0;
}