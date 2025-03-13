#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *ptr){
    if(ptr->r==ptr->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *ptr){
    if(ptr->r==ptr->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *ptr, int val){
    if(isFull(ptr)){
        printf("This Queue is full\n");
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r] = val;
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *ptr){
    int val = -1;
    if(isEmpty(ptr)){
        printf("This Queue is empty\n");
    }
    else{
        ptr->f++;
        val = ptr->arr[ptr->f]; 
    }
    return val;
}
int peek(struct queue* ptr) {
    if (isEmpty(ptr)) {
        printf("Queue is Empty! No element to peek.\n");
        return -1;  // Indicating an empty stack
    } else {
        return ptr->arr[ptr->f];  // Return the top element without removing it
    }
}
 
int main(){
   
    struct queue *sp = (struct queue *) malloc(sizeof(struct queue));
    sp->size = 4;
    sp->f = sp->r = 0;
    sp->arr = (int*) malloc(sp->size*sizeof(int));
    
    // Enqueue few elements
    enqueue(sp, 12);
    enqueue(sp, 15);
    enqueue(sp, 1); 
    printf("Dequeuing element %d\n", dequeue(sp));
    printf("Dequeuing element %d\n", dequeue(sp));
    printf("Dequeuing element %d\n", dequeue(sp)); 
    printf("Peeking element: %d\n", peek(sp));
    enqueue(sp, 45);
    enqueue(sp, 45);
    enqueue(sp, 45);
 
    // if(isEmpty(&q)){
    //     printf("Queue is empty\n");
    // }
    // if(isFull(&q)){
    //     printf("Queue is full\n");
    // }
 
    return 0;
}
