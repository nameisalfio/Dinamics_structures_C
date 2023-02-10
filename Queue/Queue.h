#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

typedef struct Queue_dynamic 
{
    int size;
    Node* head;
    Node* tail;
}Queue;

bool isEmpty(Queue* queue)
{
    //return(!queue->head && !queue->tail);
    return (queue->size == 0);
}

void enqueue(Queue* queue, int val)
{
    Node* toinsert = (Node*)malloc(sizeof(Node));
    toinsert->key = val;
    toinsert->next = toinsert->prev = NULL;

    if(isEmpty(queue))
    {
        queue->head = toinsert;
        queue->tail = queue->head;
        queue->size ++;
        return;
    }

    queue->tail->next = toinsert;
    toinsert->prev = queue->tail;
    queue->tail = toinsert;
    queue->size ++;
}

Node* dequeue(Queue* queue)
{
    if(isEmpty(queue))
    {
        puts("\nEmpty queue\n");
        return NULL;
    }
    Node* toremove = queue->head;
    queue->head = queue->head->next;
    queue->head->next->prev = NULL;
    queue->size --;
    return toremove;
}

void printQueue(Queue* queue)
{
    if(isEmpty(queue))
    {
        puts("\nEmpty queue\n");
        return;
    }

    Node* cur = (Node*)malloc(sizeof(Node));
    cur = queue->head;
    printf("\nHead --");
    while(cur)
    {
        printNode(cur);
        printf("--");
        cur = cur->next;
    }
    puts(" Tail");
}

#endif
