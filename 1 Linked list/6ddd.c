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
 // insertion at beginning 
struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head; // change 
    ptr->prev = NULL; // change
    

    head = ptr;
    return head;
}
// insertion at end 
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
   ptr->data = data;
   


    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL; 
    ptr->prev = p;

    return head;
}
// deletion at beginning
 struct Node* deleteAtBeginning(struct Node* head) {

    struct Node* temp = head;
    head = head->next;
 

    free(temp);
    return head;
}
// deletion at end 
struct Node* deleteAtEnd(struct Node* head) {
   

    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }

    free(temp);
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
    head = insertAtFirst(head, 54);
    head = insertAtFirst(head, 58);
    head = insertAtFirst(head, 59);
   
   head=deleteAtEnd(head); 
    // head=insertAtEnd(head,80);
   
    printf("Doubly Linked list after insertion\n");
    linkedListTraversal(head);
    return 0;
} 

