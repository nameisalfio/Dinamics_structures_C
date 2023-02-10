#ifndef NODE_H
#define NODE_H

typedef struct Node
{
    int key;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
}Node;

void printNode(Node* node)
{
    printf("\n(%d)", node->key);
}

#endif