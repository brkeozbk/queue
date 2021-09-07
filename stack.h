#ifndef HW2_STACK_H
#define HW2_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct stack stack;

struct node{
    int data;
    node * prev;
};

struct stack{
    int size;
    node * top;
};

int top();
int pop(stack * s);
void push(stack * s, int data);
void displayStack(stack s);
int * toArray(stack s);

#endif //HW2_STACK_H
