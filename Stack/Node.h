#ifndef NODE_H
#define NODE_H

typedef struct Node
{
    int key;
    struct Node* next;
}Node;

void printNode(Node* node)
{
    printf("[%d]", node->key);
}

#endif
