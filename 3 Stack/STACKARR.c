#include<stdio.h>
#include<stdlib.h>
 
struct stack{
    int size;
    int top;
    int * arr;
};
 
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
         printf("Pushed %d onto the stack\n", val);
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack is Empty! No element to peek.\n");
        return -1;  // Indicating an empty stack
    } else {
        return ptr->arr[ptr->top];  // Return the top element without removing it
    }
}

 
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int)); 
    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 57);
    printf("Top element is %d\n", peek(sp)); // --> 57

        printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    return 0;
}
