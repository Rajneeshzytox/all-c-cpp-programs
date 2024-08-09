// ******************************************
// program to add node at start
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
    while (ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return;
    
}

Node* nodeAtStart(Node* head, int data){
    Node* temp = createNode(data);
    temp->link = head;

    return temp;
 }

int main(){
    Node* head = createNode(5);
    Node* ptrAtEnd = head;
    ptrAtEnd = nodeAtEnd(ptrAtEnd, 10);
    ptrAtEnd = nodeAtEnd(ptrAtEnd, 20);
    ptrAtEnd = nodeAtEnd(ptrAtEnd, 30);

// ******************************
   head = nodeAtStart(head, 55);
   head = nodeAtStart(head, 65);
// ******************************
   

    printNode(head);
    free(head);
    return 0;
}



