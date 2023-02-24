#ifndef LIST_H
#define LIST_H

#include "Node.h"

typedef struct q_node
{
    Node* k;
    struct q_node* next;
}q_node;

void print_lnode(q_node* node)
{
    if(node)
        printf("[%d]", node->k->key);
}
typedef struct Queue
{
    q_node* head;
}Queue;

bool Empty(Queue* queue)
{
    return !(queue->head);
}

void push(Queue* queue, Node* val)
{    
    q_node* toinsert = (q_node*)malloc(sizeof(q_node));
    toinsert->k = val;

    if(Empty(queue))
    {
        queue->head = toinsert;
        return;
    }

    q_node* cur = queue->head;
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
    q_node* toremove = queue->head;
    queue->head = queue->head->next;
    return toremove->k;
}

#endif