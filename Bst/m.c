#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

int main()
{
    List l;
    insert(&l, 4);
    extract(&l);
    printList(&l);
}