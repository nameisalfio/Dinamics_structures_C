#ifndef STACK_H 
#define STACK_H

#include "Node.h"

typedef struct Stack
{
    int size;
    Node* top;
}Stack;

bool isEmpty(Stack* stack)
{
    return !(stack->top);
}

void push(Stack* stack, int val)
{
    Node* toinsert = (Node*)malloc(sizeof(Node));
    toinsert->key = val;
    toinsert->next = NULL;

    if(isEmpty(stack))
    {
        stack->top = toinsert;
        stack->size++;
        return;
    }
    toinsert->next = stack->top;
    stack->top = toinsert;
    stack->size++;
}

Node* pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        puts("\nEmpty Stack\n");
        return NULL;
    }
    Node* toreturn = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    return toreturn;
}

void printStack(Stack* stack)
{
    if(isEmpty(stack))
    {
        puts("\nEmpty Stack\n");
        return;
    }
    printf("\nSize: %d \n", stack->size);
    printf("Top--");
    Node* cur = stack->top;
    while(stack->top)
    {
        printf(" ");
        printNode(cur);
        if(!cur->next)
            break;
        cur = cur->next;
    }
    printf(" --Down\n");
}

#endif