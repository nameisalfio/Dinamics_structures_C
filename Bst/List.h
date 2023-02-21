#ifndef LIST_H
#define LIST_H

#include "Node.h"

typedef struct l_node
{
    Node* k;
    struct l_node* next;
}l_node;

void print_lnode(l_node* node)
{
    if(node)
        printf("[%d]", node->k->key);
}
typedef struct List
{
    l_node* head;
}List;

bool Empty(List* list)
{
    return !(list->head);
}

void insertHead(List* list, Node* val)
{    
    l_node* toinsert = (l_node*)malloc(sizeof(l_node));
    toinsert->k = val;

    if(Empty(list))
    {
        list->head = toinsert;
        return;
    }

    l_node* cur = list->head;
    while(cur->next)
        cur = cur->next;
    cur->next = toinsert;
}

Node* extract(List* list)
{
    if(Empty(list))
    {
        puts("\nEmpty List\n");
        return NULL;
    }
    l_node* toremove = list->head;
    list->head = list->head->next;
    return toremove->k;
}

void printList(List* list)
{
    if(Empty(list))
    {
        puts("\nEmpty List\n");
        return;
    }

    l_node* cur = (l_node*)malloc(sizeof(l_node));
    cur = list->head;
    printf("\nHead --");
    while(cur)
    {
        print_lnode(cur);
        printf("--");
        cur = cur->next;
    }
    puts(" NIL");
}

#endif