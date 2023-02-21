#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

int main()
{
    List l;
    Node* n = malloc(sizeof(Node*));
    n->key = 4;
    insertHead(&l, n);
    extract(&l);
    printList(&l);
}