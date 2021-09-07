#include "queue.h"

queue init_queue(int capacity){
    queue new;
    new.arr = (int*)calloc(capacity, sizeof(int));
    new.capacity = capacity;
    new.head = -1;
    new.tail = 0;

    return new;
}

void enqueue(queue * q, int data){
    if(q->head == q->tail){
        printf("CAPACITY IS FULL. ");
        return;
    }
    if(q->head == -1)
        q->head = 0;
    q->arr[q->tail++] = data;

    if(q->tail == q->capacity)
        q->tail = 0;
}

int dequeue(queue * q){
    if(q->head != q->tail)
        return q->arr[q->head++];
    return -1;
}

void displayQueue(queue q){
    int i;
    for(i = q.head; i < ((q.head >= q.tail) * q.capacity + q.tail);i++){
        printf("%d ", q.arr[i % q.capacity]);
    }
    printf("\n");
}

double calculateAvg(queue q){
    double sum = 0;

    int i;
    for(i = q.head; i < ((q.head >= q.tail) * q.capacity + q.tail);i++)
        sum += q.arr[i % q.capacity];

    int count = q.head < q.tail ? q.tail - q.head : q.capacity - q.head + q.tail;

    return sum / count;
}

void largerToStack(queue q, stack * s){
    double average = calculateAvg(q);

    int i;
    for(i = q.head; i < ((q.head >= q.tail) * q.capacity + q.tail);i++)
        if(q.arr[i] > average)
            push(s, q.arr[i]);
}