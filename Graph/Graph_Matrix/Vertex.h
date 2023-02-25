#ifndef VERTEX_H
#define VERTEX_H

typedef struct Vertex
{
    int key;
}Vertex;

void printVertex(Vertex* v)
{
    if(!v)
    {
        puts("\tNULLPTR");
        exit -1;
    }
    printf("[%d]", v->key);
}

#endif