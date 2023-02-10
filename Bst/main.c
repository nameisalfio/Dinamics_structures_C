#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Bst.h"

int main()
{
    Bst bst;

    insert(&bst, 20);
    insert(&bst, 10);
    insert(&bst, 30);

    insert(&bst, 5);
    insert(&bst, 15);
    insert(&bst, 25);
    insert(&bst, 35);
    insert(&bst, 37);

    in_order(&bst);

    printf("\nProfondità del nodo 35 = %d\n", depth(&bst, 20));
    printf("Profondità del nodo 35 = %d\n", depth(&bst, 35));
    printf("Profondità del nodo 37 = %d\n", depth(&bst, 37));

}