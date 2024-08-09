#include <stdio.h>
#include <stdlib.h>

// node
typedef struct Node{
    int data;
    struct Node* next;
} Node;


// // create node fun
// void createNode(Node* head){
//     head = malloc(sizeof(Node));
//     if(head == NULL) printf("alloc fail"); exit(1);
//     int n;
//     printf("enter the data you want to store in the node: ");
//     scanf("%d", &n);
//     head->data = n;
//     head->next = NULL;
//     int* ptr = head;
//     ptr = ptr->head;
// }

void countNode(Node* head){
    if(head == NULL){
        printf("link list is empty\n");
        exit(1);
    }
    int count = 0;
    Node* ptr = NULL;

    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("\nno of nodes are %d\n", count);
}


int main(){
    
    Node* head = malloc(sizeof(Node));
    head->data = 6;
    head->next = NULL;

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

    /* ------------------- 
    function to count the no of nodes
    -------------------  */
    countNode(head);

    free(current);
    free(head);
    return 0;
}