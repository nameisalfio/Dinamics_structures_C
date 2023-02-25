#ifndef LIST_H
#define LIST_H

#include "Vertex.h"

typedef struct Node
{
    int k;
    struct Node* next;
}Node;

void printNode(Node* node)
{
    if(!node)
    {
        puts("NULLPTR");
        exit -1;
    }
    printf("[%d] ", node->k);
}
typedef struct Queue
{
    Node* head;
}Queue;

bool Empty(Queue* queue)
{
    return !(queue->head);
}

void push(Queue* queue, int val)
{    
    Node* toinsert = (Node*)malloc(sizeof(Node));
    toinsert->k = val;

    if(Empty(queue))
    {
        queue->head = toinsert;
        return;
    }

    Node* cur = queue->head;
    while(cur->next)
        cur = cur->next;
    cur->next = toinsert;
}

Node* pop(Queue* queue)
{
    if(Empty(queue))
    {
        puts("\nEmpty queue\n");
        return NULL;
    }
    Node* toremove = queue->head;
    queue->head = queue->head->next;
    return toremove;
}

void printQueue(Queue* queue)
{
    if(Empty(queue))
    {
        puts("\nEmpty queue\n");
        return;
    }
    Node* cur = (Node*)malloc(sizeof(Node));
    cur = queue->head;
    while(cur)
    {
        printNode(cur);
        cur = cur->next;
    }
    printf("\n");
}

#endif