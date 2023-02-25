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

void inizialize(Graph* g, int max, bool oriented) 
{
    g->n_vertex = 0;
    g->max_vertex = max;
    g->isOriented = oriented;

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
        return -1;
    }	

    for(int i = 0; i < g->n_vertex; i++)
    {
        if(g->vertices[i]->key == val)
            return i;
    }
    return -1;
}

void addVertex(Graph* g, int val)
{
    if(isFull(g))
    {
        puts("Graph is full\n");
        exit -1;
    }
    g->vertices[g->n_vertex++]->key = val;
}

void addEdge(Graph* g, int val_1, int val_2) 
{
    int i = search(g, val_1);
    int j = search(g, val_2);

    if(i != -1 && j != -1)
    {
        g->adj[i][j] = true;
        if(!g->isOriented)
            g->adj[j][i] = true;
    }
    else if(i == -1)
    {
        printf("Error key %d\n", val_1);
        exit -1;
    }
    else if(j == -1)
    {
        printf("Error key %d\n", val_2);
        exit -1;
    }
}

//Breadth-First Search
void BFS(Graph* g, int start)
{
    if(isEmpty(g))
    {
        puts("Graph is empty\n");
        return;
    }
    if(search(g, start) == -1)
    {
        printf("Key %d not in the graph\n", start);
        return;
    }
    printf("BFS from %d\n", start);
    bool visited[g->n_vertex];
    for(int i = 0; i < g->n_vertex; i++)
        visited[i] = false;

    Queue* queue = malloc(sizeof(Queue));
    queue->head = NULL;

    visited[start] = true;
    push(queue, start);

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

void DFS(Graph* g, int start)
{
    if(isEmpty(g))
    {
        puts("Graph is empty\n");
        return;
    }
    if(search(g, start) == -1)
    {
        printf("Key %d not in the graph\n", start);
        return;
    }
    printf("DFS from %d\n", start);
    bool visited[g->n_vertex];
    for(int i = 0; i < g->n_vertex; i++)
        visited[i] = false;

    DFS_visit(g, start, visited);
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