#ifndef GRAPH_H
#define GRAPH_H

typedef struct Graph
{
    Vertex** vertices;
    bool** adj;
    int n_vertices;
    int max_vertices;
    bool isOriented;
}Graph;

Graph buildGraph(Graph)
{
    
}

#endif