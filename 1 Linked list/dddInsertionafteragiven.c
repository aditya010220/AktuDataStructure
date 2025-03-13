#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedListTraversal(struct Node *head) {
    struct Node *ptr = head; // change
    while (ptr != NULL) {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    // changes
    ptr->prev = prevNode;
    
    // If the node after prevNode exists, update its prev pointer
    if (prevNode->next != NULL) {
        prevNode->next->prev = ptr;
    }
    // changes end..
    // Link prevNode to the new node
    prevNode->next = ptr;
   

    
    return head;
}


int main() {
    struct Node *head = NULL;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;
    head->prev = NULL;

    // Link second and third nodes
    second->data = 3;
    second->next = third;
    second->prev = head;

    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;
    third->prev = second;

    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = NULL;
    fourth->prev = third;

    printf("Doubly Linked list before insertion\n");
    linkedListTraversal(head);
    head = insertAfterNode(head,third, 54);
   
    
   
   
    printf("Doubly Linked list after insertion\n");
    linkedListTraversal(head);
    return 0;
} 

