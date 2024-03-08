#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right, *p;
}Node;

typedef struct{
    Node *root;
}Tree;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Tree* createTree() {
    return (Tree*)malloc(sizeof(Tree));
}

Node* insert(Tree *T, Node *z) {
    Node *x = T->root;       // node being compared with z
    Node *y = NULL;          // y will be parent of z
    while (x != NULL){    // descend until reaching a leaf
        y = x;
        if (z->key < x->key)
            x = x->left;
        else x = x->right;
    }
    z->p = y;          // found the location—insert z with parent y
    if (y == NULL)
        T->root = z;  // tree T was empty
    else if (z->key < y->key)
        y->left = z;
    else y->right = z;
}

void inorder(Node* x) {
    if (x != NULL) {
        inorder(x->left);
        printf("%d ", x->key);
        inorder(x->right);
    }
}

void deleteNodes(Node* x) {
    if (x != NULL) {
        inorder(x->left);
        inorder(x->right);
        free(x);
    }
}

void deleteTree(Tree *t){
    deleteNodes(t->root);
    free(t);
}

int main() {
    Tree *t = createTree();
    insert(t,createNode(15));
    insert(t,createNode(6));
    insert(t,createNode(18));
    insert(t,createNode(3));
    insert(t,createNode(7));
    insert(t,createNode(17));
    insert(t,createNode(20));
    insert(t,createNode(2));
    insert(t,createNode(4));
    insert(t,createNode(13));
    insert(t,createNode(9));
    inorder(t->root);
    deleteTree(t);
    return 0;
}