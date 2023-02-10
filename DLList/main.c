#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DLList.h"

int main()
{
    int vet[11] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 11};
    DLList dl;

    puts("\n...building list...");
    for(int i=0; i<6; i++)
        insertHead(&dl, vet[i]);

    for(int i=5; i<11; i++)
        insertTail(&dl, vet[i]);   
    
    printList(&dl);

    puts("\nRemove Head");
    removeHead(&dl);
    printList(&dl);

    puts("\nRemove Tail");
    removeTail(&dl);
    printList(&dl);

    puts("\nLooking for nodes with keys 9 and 37\n");
    Node* test = search(&dl, 9);
    printNode(test);
    test = search(&dl, 37);

    puts("\nInvert");
    invert(&dl);
    printList(&dl);
}