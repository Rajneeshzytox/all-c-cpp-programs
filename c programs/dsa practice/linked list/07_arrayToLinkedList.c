#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void deleteList(Node** AddrOfHead){

    Node* temp = *AddrOfHead;
    while (temp != NULL)
    {
        temp = temp->next;
        free(*AddrOfHead);
        *AddrOfHead = temp;
    }
}
int printNode(Node* head){
    int count = 0;

    // check if list is not empty
    if (head != NULL){
        Node* temp;
        temp = head;
        while (temp != NULL)
        {
            count++;
            printf("%d ", temp->data);
            temp = temp->next;
        }
        
    }
    else{
        printf("List ia empty");
    }

    return count;    
}

// // function to add data of arry into linked list
// Node* addNodeAtLast(Node*tail, int value){
//     Node* tempNode = malloc(sizeof(Node));
//     tempNode->data = value;
//     tempNode->next = NULL;

//     tail->next = tempNode;
//     return tempNode;
    
// }

// ############### 
// optimal solution way 
void convertToLinkedList(Node** head, int* arr, int size){
    // creating first node to store value 1st arr value
    *head = malloc(sizeof(Node));
    (*head)->data = *(arr);
    (*head)->next = NULL;

    // last node ptr tail, 
    Node* tail = *head;

    // temp node to add at last (declaration)
    Node* tempNode;

    // loop to create node and add at end
    // size -1 => because we already added first value of array to head node, we dont want to run 1 extra in end,
    // tempNode->data = *(arr + i + 1) => same reason as above, we are starting to add value from index 1, as value of index 0 is assigned to head node,
    for (int i = 0; i < size - 1; i++)
    {
        // tempp node to add at last
        tempNode = malloc(sizeof(Node));
        tempNode->data = *(arr + i + 1);
        tempNode->next = NULL;

        tail->next = tempNode;
        tail = tempNode;
    }
    // also valid : return head, you dont need to write *head, and pass &head, also take care function return type => Node*
}



int main(){
    int arr[6] = {1,2,3,4,77,88};
    int size = sizeof(arr)/sizeof(arr[0]);

    // # starting node and ending;
    Node* head; // ptr to first node always
    
    convertToLinkedList(&head, arr, size);

    printNode(head);
    deleteList(&head);
    // printNode(head);
    return 0;
}