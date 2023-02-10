#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

int main()
{
    int vet[15] = {11, 12, 13, 14, 15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Queue q;

    puts("\n...building queue...");
    for(int i=0; i<15; i++)
        enqueue(&q, vet[i]);
    printQueue(&q);

    puts("\nDequeue: ");
    for(int i=0; i<5; i++)
        dequeue(&q);
    printQueue(&q);

}