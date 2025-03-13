#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void linkedListTraversal(struct Node *ptr) {
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Queue is Full\n");
    } else {
        n->data = val;
        n->next = NULL;

        if (front == NULL) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
    }
}

int dequeue() {
    int val = -1;
    struct Node *ptr = front;
    if (front == NULL) {
        printf("Queue is Empty\n");
    } else {
        front = front->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main() {


    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(front);
    return 0;
} 