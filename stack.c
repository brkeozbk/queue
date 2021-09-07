#include "stack.h"

int top(stack s){
    if(s.top)
        return s.top->data;
    return -1;
}

void push(stack * s, int data){
    node * new = (node *) malloc(sizeof(node));
    new->data = data;
    s->size++;

    if(s->top == NULL) {
        new->prev = NULL;
        s->size = 1;
        s->top = new;
        return;
    }
    new->prev = s->top;
    s->top = new;
}

void displayStack(stack s){
    node * iter = s.top;

    while(iter != NULL){
        printf("%d ", iter->data);
        iter = iter->prev;
    }
    printf("\n");
}

int pop(stack * s){
    if(s->size == 0)
        return -1;

    int temp = s->top->data;
    node * toDelete = s->top;

    s->size--;
    s->top = s->top->prev;
    free(toDelete);

    return temp;
}

int * toArray(stack s){
    int * new = (int*)calloc(s.size, sizeof(int));
    int i = 0;

    node * iter = s.top;
    while(iter != NULL){
        new[i++] = iter->data;
        iter = iter->prev;
    }
    return new;
}