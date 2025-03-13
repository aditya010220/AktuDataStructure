#include <stdio.h>
#include <stdlib.h>

// Definition of the singly linked list node also for doubly 
struct Node {
    int data;
    struct Node* next;
};

// Function to calculate the size of the singly linked list
int sizeOfLinkedList(struct Node* head) {
    int count = 0;         // Initialize count to 0
    struct Node* ptr = head; // Start from the head of the list

    // Traverse the linked list
    while (ptr != NULL) {
        count++;           // Increment count for each node
        ptr = ptr->next; // Move to the next node
    }
    
    return count;         // Return the total count of nodes
}
