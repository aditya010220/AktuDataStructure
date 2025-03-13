#include <stdio.h>
#include <stdlib.h>

// Define the node structure.
struct Node {
    int data;
    struct Node* next;
};
// create a new node
// traversal code.
// insert the node.
struct Node* Concat(struct Node *first, struct Node *second) {
    // If the first list is empty, return the second list.
    if (first == NULL) {
        return second;
    }

    // Traverse the first list to find its last node.
    struct Node *p = first;
    while (p->next != NULL) {
        p = p->next;
    }

    // Link the last node of the first list to the head of the second list.
    p->next = second;

    return first;
}
// pseudo code for concatenating the two linked lists in which Function should have two parameters , pointers to beginning of the lists and the function should link second list at the end of the first list.
/*
* Pseudo code 
Function ConcatenateLinkedlist(first, second)
    If first is NULL, return second

 while p.next is not null:
 p=p.next
 end while
 p.next=second
 return first
*/
