#ifndef DLLIST_H
#define DLLIST_H

#include "Node.h"

typedef struct DLList
{
    Node* head;
    Node* tail;
}DLList;

bool isEmpty(DLList* list)
{
    return (!list->head && !list->tail);
}

void insertHead(DLList* list, int val)
{
    Node* toinsert = (Node*)malloc(sizeof(Node));
    toinsert->key = val;
    toinsert->next = toinsert->prev = NULL;

    if(isEmpty(list))
    {
        list->head = toinsert;
        list->tail = list->head;
        return;
    }
    toinsert->next = list->head;
    list->head->prev = toinsert;
    list->head = toinsert;
}

void insertTail(DLList* list, int val)
{    
    if(isEmpty(list))
    {
        insertHead(list, val);
        return;
    }

    Node* toinsert = (Node*)malloc(sizeof(Node));
    toinsert->key = val;
    toinsert->next = toinsert->prev = NULL;

    list->tail->next = toinsert;
    toinsert->prev = list->tail;
    list->tail = toinsert;
}

void removeHead(DLList* list)
{
    if(isEmpty(list))
    {
        puts("\nEmpty List\n");
        return;
    }
    Node* toremove = list->head;
    list->head = list->head->next;
    list->head->next->prev = NULL;
    free(toremove);
}

void removeTail(DLList* list)
{
    if(isEmpty(list))
    {
        puts("\nEmpty List\n");
        return;
    }
    Node* toremove = list->tail;
    list->tail->prev->next = NULL;
    list->tail = list->tail->prev;
    free(toremove);
}

Node* search(DLList* list, int val)
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

void invert(DLList* list)
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

void printList(DLList* list)
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
    puts(" Tail");
}

#endif