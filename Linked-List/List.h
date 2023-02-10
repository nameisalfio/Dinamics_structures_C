#ifndef LIST_H
#define LIST_H

#include "Node.h"

typedef struct List
{
    Node* head;
}List;

bool isEmpty(List* list)
{
    return !(list->head);
}

void insertHead(List* list, int val)
{
    Node* toinsert = (Node*)malloc(sizeof(Node));
    toinsert->key = val;
    toinsert->next = NULL;

    if(isEmpty(list))
    {
        list->head = toinsert;
        return;
    }
    toinsert->next = list->head;
    list->head = toinsert;
}

void insertTail(List* list, int val)
{    
    if(isEmpty(list))
    {
        insertHead(list, val);
        return;
    }

    Node* toinsert = (Node*)malloc(sizeof(Node));
    toinsert->key = val;
    toinsert->next = NULL;

    Node* cur = list->head;
    while(cur->next)
        cur = cur->next;
    cur->next = toinsert;
}

void removeHead(List* list)
{
    if(isEmpty(list))
    {
        puts("\nEmpty List\n");
        return;
    }

    Node* toremove = list->head;
    list->head = list->head->next;
    free(toremove);
}

void removeTail(List* list)
{
    if(isEmpty(list))
    {
        puts("\nEmpty List\n");
        return;
    }

    Node* toremove = list->head;
    Node* prev = NULL;

    while(toremove->next)
    {
        prev = toremove;
        toremove = toremove->next;
    }
    prev->next = NULL;
    free(toremove);
}

Node* search(List* list, int val)
{
    if(isEmpty(list))
    {
        puts("\nEmpty List\n");
        return NULL;
    }

    Node* cur = list->head;
    while(cur->next && cur->key != val)
        cur = cur->next;
    
    if(cur->key != val)
    {
        printf("\nElement with key %d not found\n", val);
        return NULL;
    }
    return cur;
}

void invert(List* list)
{
    if(isEmpty(list))
    {
        puts("\nEmpty List\n");
        return;
    }

    Node* cur = list->head;
    Node* prev = NULL;
    Node* succ = NULL;
    while(cur)
    {
        succ = cur->next;
        cur->next = prev;
        prev = cur;
        cur = succ;
    }
    list->head = prev;
}

void printList(List* list)
{
    if(isEmpty(list))
    {
        puts("\nEmpty List\n");
        return;
    }

    Node* cur = (Node*)malloc(sizeof(Node));
    cur = list->head;
    printf("\nHead --");
    while(cur)
    {
        printNode(cur);
        printf("--");
        cur = cur->next;
    }
    puts(" NIL");
}

#endif
