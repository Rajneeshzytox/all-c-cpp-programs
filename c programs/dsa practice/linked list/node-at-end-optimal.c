// ******************************************
// optimal code for node at end O(1)
// ******************************************
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
} Node;

Node* createNode(int data){
    Node* a = malloc(sizeof(Node));
    if(a == NULL){
        printf("alloc fail");
        exit(-1);
    }
    a->data = data;
    a->link = NULL;

    return a;
}

Node* nodeAtEnd(Node* endptr, int data){
    endptr->link = createNode(data);
    return endptr->link;

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


int main(){
    Node* head = createNode(5);
    Node* ptrAtEnd = head;

    // ********************************
    ptrAtEnd = nodeAtEnd(ptrAtEnd, 10);
    ptrAtEnd = nodeAtEnd(ptrAtEnd, 20);
    ptrAtEnd = nodeAtEnd(ptrAtEnd, 30);
    // ********************************


   

    printNode(head);
    free(head);
    return 0;
}



