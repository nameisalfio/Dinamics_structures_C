#ifndef NODE_H
#define NODE_H

struct Node
{
    int key;
    struct Node* next;
    struct Node* prev;
};
typedef struct Node Node;

void printNode(Node* node)
{
    printf("[%d]", node->key);
}

#endif
