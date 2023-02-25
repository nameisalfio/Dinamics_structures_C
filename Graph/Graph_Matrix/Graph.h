#ifndef GRAPH_H
#define GRAPH_H

#include "Queue.h"

typedef struct Graph
{
    Vertex** vertices;
    int max_vertex;
    bool** adj; 
    int n_vertex;
    bool isOriented;
}Graph;

bool isEmpty(Graph* g)
{
    return g->n_vertex == 0;
}

bool isFull(Graph* g)
{
    return g->n_vertex == g->max_vertex;
}

void inizialize(Graph* g, int max, bool isOriented) 
{
    g->n_vertex = 0;
    g->max_vertex = max;
    g->isOriented = isOriented;

    g->vertices = malloc(sizeof(Vertex*) * g->max_vertex);
    for(int i = 0; i < g->max_vertex; i++)
        g->vertices[i] = malloc(sizeof(Vertex));

    g->adj = malloc(sizeof(bool*) * g->max_vertex);
    for(int i = 0; i < g->max_vertex; i++)
    {
        g->adj[i] = malloc(sizeof(bool) * g->max_vertex);
        for(int j = 0; j < g->max_vertex; j++)
            g->adj[i][j] = false;
    }
}

int search(Graph* g, int val)
{
    if(isEmpty(g))
    {
        puts("Graph is empty\n");
        exit -1;
    }

    for(int i = 0; i < g->n_vertex; i++)
    {
        if(g->vertices[i]->key == val)
            return i;
    }
    printf("Error key %d not in the graph\n", val);
    exit -1;
}

void addVertex(Graph* g, int val)
{
    if(isFull(g))
    {
        puts("Graph is full\n");
        exit -1;
    }

    for(int i = 0; i < g->n_vertex; i++)
    {
        if(g->vertices[i]->key == val)
        {
            printf("Vertex with key %d already exists in the graph\n", val);
            return;
        }
    }

    g->vertices[g->n_vertex] = malloc(sizeof(Vertex));
    g->vertices[g->n_vertex]->key = val;
    g->n_vertex++;
}

void addEdge(Graph* g, int val_1, int val_2) 
{
    int i = search(g, val_1);
    int j = search(g, val_2);

    g->adj[i][j] = true;
    if(!g->isOriented)
        g->adj[j][i] = true;
}

void removeVertex(Graph* g, int val)
{
    if(isEmpty(g))
    {
        puts("Graph is empty\n");
        exit -1;
    }
    
    int idx = -1;
    for(int i = 0; i < g->n_vertex; i++)
    {
        if(g->vertices[i]->key == val)
        {
            idx = i;
            break;
        }
    }

    if(idx == -1)
    {
        printf("Error key %d not in the graph\n", val);
        exit -1;
    }

    // Remove edges connected to the vertex
    for(int i = 0; i < g->n_vertex; i++)
    {
        g->adj[idx][i] = false;
        g->adj[i][idx] = false;
    }

    free(g->vertices[idx]);

    // Move last vertex to the deleted vertex position
    g->vertices[idx] = g->vertices[g->n_vertex-1];

    // Update adjacent matrix for moved vertex
    for(int i = 0; i < g->n_vertex; i++)
    {
        if(g->adj[i][g->n_vertex-1])
        {
            g->adj[i][idx] = true;
            g->adj[i][g->n_vertex-1] = false;
        }
        if(g->adj[g->n_vertex-1][i])
        {
            g->adj[idx][i] = true;
            g->adj[g->n_vertex-1][i] = false;
        }
    }

    // Decrement number of vertices
    g->n_vertex--;
}

void removeEdge(Graph* g, int val_1, int val_2)
{
    int idx_1 = search(g, val_1);
    int idx_2 = search(g, val_2);

    g->adj[idx_1][idx_2] = false;
    if(!g->isOriented)
        g->adj[idx_2][idx_1] = false;
}

/*//Breadth-First Search
void BFS(Graph* g, int source)
{
    if(isEmpty(g))
    {
        puts("Graph is empty\n");
        return;
    }
    if(search(g, source) == -1)
    {
        printf("Key %d not in the graph\n", source);
        return;
    }
    printf("BFS from %d\n", source);
    bool visited[g->n_vertex];
    for(int i = 0; i < g->n_vertex; i++)
        visited[i] = false;

    Queue* queue = malloc(sizeof(Queue));
    queue->head = NULL;

    visited[source] = true;
    push(queue, source);

    while(!Empty(queue))
    {
        int current = pop(queue)->k;
        printVertex(g->vertices[current]);
        printf(" ");

        for(int i = 0; i < g->n_vertex; i++)
        {
            if(g->adj[current][i] && !visited[i])
            {
                visited[i] = true;
                push(queue, i);
            }
        }
    }
    free(queue);
    printf("\n\n");
}
*/

void BFS(Graph* g, int source)
{
    if(isEmpty(g))
    {
        puts("Graph is empty\n");
        return;
    }
    if(search(g, source) == -1)
    {
        printf("Key %d not in the graph\n", source);
        return;
    }
    printf("BFS from %d\n", source);
    
    bool visited[g->n_vertex];
    int distance[g->n_vertex];
    int parent[g->n_vertex];

    for(int i = 0; i < g->n_vertex; i++) {
        visited[i] = false;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    Queue* queue = malloc(sizeof(Queue));
    queue->head = NULL;

    visited[source] = true;
    distance[source] = 0;
    push(queue, source);

    while(!Empty(queue))
    {
        int current = pop(queue)->k;
        printVertex(g->vertices[current]);
        printf(" ");

        for(int i = 0; i < g->n_vertex; i++)
        {
            if(g->adj[current][i] && !visited[i])
            {
                visited[i] = true;
                distance[i] = distance[current] + 1;
                parent[i] = current;
                push(queue, i);
            }
        }
    }

    printf("\nShortest paths from %d:\n", source);

    for (int i = 0; i < g->n_vertex; i++) {
        if (distance[i] == INT_MAX) {
            printf("Vertex %d is not reachable from source\n", i);
        } else {
            printf("Distance from %d to %d: %d. Path: ", source, i, distance[i]);
            int j = i;
            while (j != source) {
                printf("%d ", j);
                j = parent[j];
            }
            printf("%d\n", source);
        }
    }

    free(queue);
    printf("\n\n");
}

//Depth-First Search
void DFS_visit(Graph* g, int current, bool* visited)
{
    visited[current] = true;
    printVertex(g->vertices[current]);
    printf(" ");

    for(int i = 0; i < g->n_vertex; i++)
    {
        if(g->adj[current][i] && !visited[i])
            DFS_visit(g, i, visited);
    }
}

void DFS(Graph* g, int source)
{
    if(isEmpty(g))
    {
        puts("Graph is empty\n");
        return;
    }
    if(search(g, source) == -1)
    {
        printf("Key %d not in the graph\n", source);
        return;
    }
    printf("DFS from %d\n", source);
    bool visited[g->n_vertex];
    for(int i = 0; i < g->n_vertex; i++)
        visited[i] = false;

    DFS_visit(g, source, visited);
    printf("\n\n");
}


void printMatrix(Graph* g) 
{
    if(isEmpty(g))
    {
        puts("\nEmpty matrix");
        return;
    }
    puts("\nAdj Matrix");
    for (int i = 0; i < g->n_vertex; i++) 
    {
        for (int j = 0; j < g->n_vertex; j++) 
            printf("\t%d  ", g->adj[i][j]);
        printf("\n");
    } 
    printf("\n");
}

void printGraph(Graph* g) 
{
    if(isEmpty(g))
    {
        puts("\nEmpty graph");
        return;
    }

    printf("Oriented :\t");
    if(g->isOriented)
        printf("TRUE");
    else
    printf("FALSE");

    printf("\n\nVertices: ");
    for(int i = 0; i < g->n_vertex; i++) 
    {
        printVertex(g->vertices[i]);
        printf("   ");
    }

    puts("\n\nEdges:");
    for(int i = 0; i < g->n_vertex; i++) 
    {
        for(int j = 0; j < g->n_vertex; j++) 
        {
            if(g->adj[i][j]) 
            {
                printf("\t");
                printVertex(g->vertices[i]);
                printf(" --- ");
                printVertex(g->vertices[j]);
                printf("\n");
            }
        }
    }
    printf("\n");
}

#endif