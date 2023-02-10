#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

int main()
{
    int vet[15] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 11, 12, 13, 14, 15};
    Stack s;

    puts("\n...building stack...");
    for(int i=0; i<15; i++)
        push(&s, vet[i]);
    printStack(&s);

    puts("\nPop: ");
    for(int i=0; i<5; i++)
        pop(&s);
    printStack(&s);

}