#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

int main()
{
    int vet[11] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 11};
    List l;

    puts("\n...building list...");
    for(int i=0; i<6; i++)
        insertHead(&l, vet[i]);

    for(int i=5; i<11; i++)
        insertTail(&l, vet[i]);   
    
    printList(&l);

    puts("\nRemove Head");
    removeHead(&l);
    printList(&l);

    puts("\nRemove Tail");
    removeTail(&l);
    printList(&l);

    puts("\nLooking for nodes with keys 9 and 37\n");
    Node* test = search(&l, 9);
    printNode(test);
    test = search(&l, 37);

    puts("\nInvert");
    invert(&l);
    printList(&l);
} 
