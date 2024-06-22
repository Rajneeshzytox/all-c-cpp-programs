#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
    int data;
    struct Node* next;
};

int main(){
    
    Node* head = malloc(sizeof(Node));
    head->data = 6;
    head->next = NULL;

    // printf("%d", head->data);

    // second node
    Node* current = malloc(sizeof(Node));
    current->data = 5;
    current->next = NULL;

    head->next = current;

    //third node
    current = malloc(sizeof(Node));
    current->data = 4;
    current->next = NULL;

    head->next->next = current;

    printf("three node data are: %d, %d, %d", head->data, head->next->data, head->next->next->data);
    free(current);
    free(head);
    return 0;
}