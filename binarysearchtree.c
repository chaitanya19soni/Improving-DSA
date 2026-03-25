#include<stdlib.h>
#include <stdio.h>

typedef struct node {
    char data;
    struct node *left ;
    struct node* right ;
}*Node;

Node createNode (char data){
    Node newNode= (Node)malloc(sizeof(struct node));
    newNode ->data = data;
    newNode ->left =  NULL;
    newNode ->right = NULL;
    return newNode;
}

void traversal (Node pr){
    if (pr==NULL){
        return ;
    }
    printf("%d,", pr->data);
    traversal(pr->left);
    traversal(pr->right);
}


int main() {
    Node root =  createNode(1);
    root ->left =createNode(2);
    root -> right = createNode(3);

    root ->left ->left =  createNode(4);
    root ->left ->right =  createNode(5);

    root ->right ->left = createNode(6);
    root ->right ->right = createNode(7);


traversal(root);
    return 0;
}