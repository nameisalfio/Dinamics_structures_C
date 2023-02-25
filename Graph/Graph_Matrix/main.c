#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "Graph.h"

int main()
{
    Graph g;
    inizialize(&g, 10, true);

    //VERTEX
    addVertex(&g, 1);
    addVertex(&g, 2);
    addVertex(&g, 3);
    addVertex(&g, 4);
    addVertex(&g, 5);

    //EDGES
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);
    addEdge(&g, 4, 5);
    
    printGraph(&g);
    printMatrix(&g);

    removeVertex(&g, 1);
    printGraph(&g);

    BFS(&g, 1);
}