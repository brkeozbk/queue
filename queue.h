#ifndef HW2_QUEUE_H
#define HW2_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

typedef struct queue queue;

struct queue{
    int * arr;
    int capacity;
    int head, tail;
};

queue init_queue(int capacity);
void enqueue(queue * q, int data);
int dequeue(queue * q);
void displayQueue(queue q);
double calculateAvg(queue q);
void largerToStack(queue q, stack * s);

#endif //HW2_QUEUE_H
