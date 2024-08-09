// **************************************
// Program to print data of all nodes
// createNode Function to create node, takes int data and store in node, 
// see previou files: 'first-linked-list.c',  'count-no-of-nodes.c'
// **************************************

#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* link;
} Node;

Node* createNode(int data){
    Node* a = malloc(sizeof(Node));
    if (a==NULL){
        printf("alloc fail");
        exit(-1);
    }
    a->data = data;
    a->link = NULL;
    return a;
}

void printLinkedList(Node* head){
    if(head == NULL) {
        printf("empty linked list ");
        return;
    }
    Node* ptr = head;
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    return;

}

int main(){
    // NODE 1
    Node* head = createNode(67);
    // printf("data %d \n", head->data);

    // NODE 2
    Node* current = createNode(45);
    head->link = current;

    // NODE 3
    current = createNode(35);
    head->link->link = current;

    // NODE 4
    current = createNode(25);
    head->link->link->link = current;

    // printf("%d %d %d %d", head->data, head->link->data, head->link->link->data, head->link->link->link->data);
    printLinkedList(head);


    free(head);
    free(current);
    // printf("check if really free or not %d", head->data);
    return 0;
}