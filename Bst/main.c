#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Bst.h"

int main()
{
    Bst bst;

    puts("...building bst...");
    insert(&bst, 20);   
    insert(&bst, 10);   
    insert(&bst, 30);
    insert(&bst, 5);    
    insert(&bst, 15);
    insert(&bst, 25);
    insert(&bst, 35);
    insert(&bst, 37);   

/*
    Bst is the following
    --------------------
              20                lv.0
          /        \
        10          30          lv.1
      /    \      /    \
    5       15  25      35      lv.2
                          \
                           37   lv.3 
*/

    in_order(&bst);

    printf("\nProfondità del nodo 20 = %d\n", depth(&bst, 20));
    printf("Profondità del nodo 35 = %d\n", depth(&bst, 35));
    printf("Profondità del nodo 37 = %d\n", depth(&bst, 37));

    puts("\n\t...removing nodes 35, 20, 37 ...");
    removeNode(&bst, 35);
    removeNode(&bst, 20);
    removeNode(&bst, 37);

    in_order(&bst);
    
/*
    After removing
    --------------
            25          lv.0
          /    \
        10      30      lv.1
      /    \
    5       15           lv.2
*/

    printf("Distance from 25 to successor : %d\n", from_successor(&bst, 25));
    printf("Distance from 15 to successor : %d\n", from_successor(&bst, 15));

}