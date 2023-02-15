#ifndef LIST_H
#define LIST_H

typedef struct l_node
{
    int key;
    struct l_node* next;
}l_node;

void print_lnode(l_node* node)
{
    printf("[%d]", node->key);
}
typedef struct List
{
    l_node* head;
}List;

bool Empty(List* list)
{
    return !(list->head);
}

void insertHead(List* list, int val)
{    
    l_node* toinsert = (l_node*)malloc(sizeof(l_node));
    toinsert->key = val;
    toinsert->next = NULL;

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

l_node* extract(List* list)
{
    if(Empty(list))
    {
        puts("\nEmpty List\n");
        return NULL;
    }

    l_node* toremove = list->head;
    list->head = list->head->next;
    return toremove;
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