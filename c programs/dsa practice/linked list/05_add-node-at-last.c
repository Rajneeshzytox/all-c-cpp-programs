// **************************************
// program to add node at last
// see previous file: "print-Data-In-LinkedList"
// **************************************

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
} Node;

Node* createNode(int data){
    Node* ptr = malloc(sizeof(Node));
    if (ptr == NULL){
        printf("ALLOC FAIL !!\n");
        exit(-1);
    }
    ptr->data = data;
    ptr->link = NULL;
    return ptr;
}

void printNode(Node* head){
    if(head == NULL){
        printf("head is Null");
        return;
    }
    Node* ptr = head;
    while (ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    return;  
}

void addNodeAtLast(Node* head, int data){
    if(head == NULL){
        printf("head is Null");
        return;
    }
    Node* ptr = head;
    while (ptr->link!=NULL){
        ptr = ptr->link;
    }
    ptr->link = createNode(data);

}

int main(){
    Node* head = createNode(5); // node 1
    Node* current = createNode(15); // node 2
    head->link = current;
    current = createNode(25); // node 3
    head->link->link = current;
    current = createNode(35); // node 4
    head->link->link->link = current;
    current = createNode(45); // node 5
    head->link->link->link->link = current;
    addNodeAtLast(head, 55);
    addNodeAtLast(head, 65);
    addNodeAtLast(head, 75);


    printNode(head);
    free(current);
    free(head);
    return 0;
}
