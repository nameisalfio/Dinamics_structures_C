#ifndef BST_H
#define BST_H

#include "Node.h"

typedef struct Bst
{
    Node* root;
}Bst;

bool isEmpty(Bst* bst){return !bst->root;}

//INSERT
void bst_insert(Bst* bst, Node* ptr, int val)
{
    Node* toinsert = (Node *)malloc(sizeof(Node));
    toinsert->key = val;

    if(!ptr->left && val <= ptr->key)
    {
        ptr->left = toinsert;
        ptr->left->parent = ptr;
        return;
    }
    if(!ptr->right && val > ptr->key)
    {
        ptr->right = toinsert;
        ptr->right->parent = ptr;
        return;
    }

    if(val <= ptr->key)
        bst_insert(bst, ptr->left, val);
    else
        bst_insert(bst, ptr->right, val);
}
void insert(Bst* bst, int val)
{
    Node* toinsert = (Node *)malloc(sizeof(Node));
    toinsert->key = val;

    if(isEmpty(bst))
    {
        bst->root = toinsert;
        return;
    }
    bst_insert(bst, bst->root, val);
}

//PRE-ORDER
void bst_pre_order(Node* ptr)
{
    if(!ptr)
        return;
    printNode(ptr);
    bst_pre_order(ptr->left);
    bst_pre_order(ptr->right);
}
void pre_order(Bst* bst)
{
    printf("\nPre-order vist\n--------------");
    bst_pre_order(bst->root);
    printf("\n");
}

//IN-ORDER
void bst_in_order(Node* ptr)
{
    if(!ptr)
        return;
    bst_in_order(ptr->left);
    printNode(ptr);
    bst_in_order(ptr->right);
}
void in_order(Bst* bst)
{
    printf("\nIn-order vist\n--------------");
    bst_in_order(bst->root);
    printf("\n");
}

//POST-ORDER
void bst_post_order(Node* ptr)
{
    if(!ptr)
        return;
    bst_post_order(ptr->left);
    bst_post_order(ptr->right);
    printNode(ptr);
}
void post_order(Bst* bst)
{
    printf("\nPost-order vist\n--------------");
    bst_post_order(bst->root);
    printf("\n");
}

//SEARCH
Node* bst_search(Node* ptr, int val)
{
    if(!ptr)
        return NULL;
    
    if(ptr->key == val)
        return ptr;
    
    if(val <= ptr->key)
        bst_search(ptr->left, val);
    else
        bst_search(ptr->right, val);
}
Node* search(Bst* bst, int val)
{
    if(isEmpty(bst))
    {
        puts("Empty bst");
        return NULL;
    }
    return bst_search(bst->root, val);
}

//FIND DEPT
int bst_depth(Node* ptr)
{
    int deep = 0;
    while(ptr->parent)
    {
        deep ++;
        ptr = ptr->parent;
    }
    return deep;
}
int depth(Bst* bst, int val)
{
    Node* node = search(bst, val);
    if(!node)
        return -1;
    //printf("Eccolo --> %d", bst_depth(node));
    return bst_depth(node);
}

#endif