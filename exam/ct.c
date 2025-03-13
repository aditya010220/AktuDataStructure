#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void displayAlternateNodes(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* ptr = head;
    int count = 0;

    printf("Alternate nodes: ");
    while (ptr != NULL) {
        if (count % 2 == 0) {
            printf("%d ", ptr->data);
        }
        ptr = ptr->next;
        count++;
    }
    printf("\n");
}

// void findEvenValues(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     printf("Even values: ");
//     while (head != NULL) {
//         if (head->data % 2 == 0) {
//             printf("%d ", head->data);
//         }
//         head = head->next;
//     }
//     printf("\n");
// }

int main() {
    // Create a sample linked list
    struct Node* head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, 5);


    // Display alternate nodes
    displayAlternateNodes(head);

    // Find even values
    findEvenValues(head);

    return 0;
}