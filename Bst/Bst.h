#ifndef BST_H
#define BST_H

#include "Node.h"
#include "Queue.h"

typedef struct Bst
{
    Node* root;
}Bst;

//IS-EMPTY
bool isEmpty(Bst* bst){return !bst->root;}

//IS-LEAF
bool isLeaf(Node* node){return(!node->right && !node->left);}

//IS-LEFT-CHILD
bool isLeftChild(Node* node)
{
    if(node->parent)
        return node == node->parent->left;
    return false;
}

//IS-RIGHT-CHILD
bool isRightChild(Node* node)
{
    if(node->parent)
        return node == node->parent->right;
    return false;
}

//SWAP-KEYS
void swap_keys(Node* x, Node* y)
{
    int swap = x->key;
    x->key = y->key;
    y->key = swap;
}

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
    if(isEmpty(bst))
    {
        puts("Empty bst");
        return;
    }
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
    if(isEmpty(bst))
    {
        puts("Empty bst");
        return;
    }
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
    if(isEmpty(bst))
    {
        puts("Empty bst");
        return;
    }
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

//MAX
Node* bst_max(Node* from)
{
    Node* ptr = from;
    while(ptr->right)
        ptr = ptr->right;
    return ptr;
}
Node* max(Bst* bst)
{
    if(isEmpty(bst))
    {
        puts("Empty bst");
        return NULL;
    }
    return bst_max(bst->root);
}

//MIN
Node* bst_min(Node* from)
{
    Node* ptr = from;
    while(ptr->left)
        ptr = ptr->left;
    return ptr;
}
Node* min(Bst* bst)
{
    if(isEmpty(bst))
    {
        puts("Empty bst");
        return NULL;
    }
    return bst_min(bst->root);
}

//SUCCESSOR
Node* bst_successor(Node* x)
{
    if(x->right) 
        return bst_min(x->right);

    Node* y = x->parent;
    while(x && isRightChild(x))  //until x is a right-child
    {
        x = y;
        y = y->parent;
    }
    return y;
}
Node* successor(Bst* bst, int val)
{
    Node* ptr = search(bst, val);
    if(!ptr || ptr == max(bst))
    {
        puts("...successor doesn't exist...");
        return NULL;
    }
    return bst_successor(ptr);
}

//PREDECESSOR
Node* bst_predecessor(Node* x)
{
    if(x->left) 
        return bst_max(x->left);

    Node* y = x->parent;
    while(x && isLeftChild(x))  //until x is a left-child
    {
        x = y;
        y = y->parent;
    }
    return y;
}
Node* predecessor(Bst* bst, int val)
{
    Node* ptr = search(bst, val);
    if(!ptr || ptr == min(bst))
    {
        puts("...predecessor doesn't exist...");
        return NULL;
    }
    return bst_predecessor(ptr);
}

//REMOVE
Node* bst_removeNode(Node* node)
{
    //Case 1: the node to be removed is a leaf
    if(isLeaf(node))
    {
        if(isLeftChild(node))
            node->parent->left = NULL;

        if(isRightChild(node))
            node->parent->right = NULL;

        return node;
    }

    //Case 2: the node to be removed has just one child
    if(!node->right && node->left)
    {
        node->left->parent = node->parent;

        if(isLeftChild(node))
            node->parent->left = node->left;

        if(isRightChild(node))
            node->parent->right = node->left;

        return node;
    }

    if(!node->left && node->right)
    {
        node->right->parent = node->parent;

        if(isLeftChild(node))
            node->parent->left = node->right;

        if(isRightChild(node))
            node->parent->right = node->right;

        return node;
    }

    return NULL;
}
Node* removeNode(Bst* bst, int val)
{
    Node* node = search(bst, val);

    //  Empty tree or missing node with key searched
    if(!node)
        return NULL;
    
    Node* toremove = bst_removeNode(node);

    //  if I am not in the third case I get back the value of 
    //  the node(deleted with "bst_removeNode(node)")
    if(toremove)
        return toremove;

    // Case 3: the node to be removed has two children
    Node* succ = bst_successor(node);
    swap_keys(node, succ);

    // definitely case 1 or case 2
    toremove = bst_removeNode(succ);
    return toremove;

}

//DISTANCE-FROM-SUCCESSOR
int from_successor(Bst* bst, int val)
{
    Node* ptr = search(bst, val);
    int count = 0;
    if(!ptr || ptr == max(bst))
        return -1;

    //Case 1: node has a right subtree
    if(ptr->right)
    {
        ptr = ptr->right;
        count ++;
        while(ptr->left)
        {
            ptr = ptr->left;
            count ++;
        }
        return count;
    }

    //Case 2: node hasn't a right subtree
    Node* y = ptr->parent;
    count ++;
    while(ptr && isRightChild(ptr))
    {
        ptr = ptr->parent;
        y = y->parent;
        count ++;
    }
    return count;
}

//DISTANCE-BETWEEN-NODES
int from_start(Node* node_h, Node* start)
{
    if(node_h->key == start->key)
        return 0;
    
    Node* tmp = start;
    int count = 0;

    while(tmp && tmp->key != node_h->key)
    {
        if(node_h->key > tmp->key)
            tmp = tmp->right;
        else
            tmp = tmp->left;
        count ++;
    }

    if(!tmp)
        return -1;
    else    
        return count;
}
int between_nodes(Bst* bst, int k, int h)
{
    Node* node_k = search(bst, k);
    Node* node_h = search(bst, h);
    
    if(!node_k || !node_h)
    {
        puts("Chiavi errate");
        exit -1;
    }
    int count = 0;

    if(k <= h)
    {
        Node* tmp = node_k;
        bool flag = true;

        while(tmp && flag)
        {
            int distance = from_start(node_h, tmp);

            if(distance == 0)
                flag = false;

            else if(distance == -1)
            {
                tmp = tmp->parent;
                count ++;
            }
            else
            {
                count += distance;
                flag = false;
            }
        }
        return count;

    }        
    else
        return between_nodes(bst, h, k);
}

//DEPT
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

/*//LEVEL-ORDER
void bst_level_order(Node* x)
{
    Queue* l = (Queue*)malloc(sizeof(Queue));
    push(l, x);
    while(!Empty(l))
    {
        Node* cur = (Node*)malloc(sizeof(Node));
        cur = pop(l);

        if(!cur)
            printf("(NIL) ");
        else
        {
            printf("(%d) ", cur->key);
            push(l, cur->left);
            push(l, cur->right);
        }
    }
    free(l);
}*/

void bst_level_order(Node* root, int level) 
{
    if (!root ) 
        return;
    
    bst_level_order(root->left, level + 1);
    printf("%-8d  lv.%d\n", root->key, level);
    bst_level_order(root->right, level + 1);
}

void level_order(Bst* bst)
{
    if(isEmpty(bst))
    {
        puts("Empty bst");
        return;
    }
    printf("\nLevel-order vist\n--------------\n");
    bst_level_order(bst->root, 0);
    printf("\n");
}

#endif
