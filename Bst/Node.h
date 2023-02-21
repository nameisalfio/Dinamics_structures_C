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
    if(!node)
    {
        puts("NULLPTR");
        return;
    }
    printf("\n(%d)", node->key);
}

#endif