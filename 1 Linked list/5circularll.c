#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head) {
    struct Node *ptr = head;
    do {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// Case 1
struct Node *insertAtFirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;

// last end 
    struct Node *p = head;
    while (p->next != head) {
        p = p->next;
    }

    p->next = ptr;
//  ptr->next=NULL;
    return ptr;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node (making it circular)
    fourth->data = 66;
    fourth->next = head;

    printf("Linked list before insertion\n");
     linkedListTraversal(head);
    head = insertAtFirst(head, 56);
    linkedListTraversal(head);

    return 0;
}
 // insert at end 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head) {
    struct Node *ptr = head;
    do {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// Case 2
struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    
//  end
    struct Node *p = head;
    while (p->next != head) {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    // head == null 

    return head;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node (making it circular)
    fourth->data = 66;
    fourth->next = head;

    printf("Linked list before insertion\n");
    // linkedListTraversal(head);
    head = insertAtEnd(head, 56);
    linkedListTraversal(head);

    return 0;
} 
