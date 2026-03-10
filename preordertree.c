#include <stdlib.h>
#include <stdio.h>

typedef struct tree {
    char data;
    struct tree* left ;
    struct tree*right ;
}*Tree;

Tree createNode(char data ){
    Tree newNode = (Tree)malloc(sizeof(struct tree));
    newNode -> data =  data;
    newNode -> left  = NULL;
    newNode ->right  = NULL;

    return newNode;
}   

void traverse (Tree root ){
    if (root == NULL ){
        return;
    }
    
    printf (" %d -> ", root -> data);
    traverse (root->left);
    traverse (root->right );


}

int main() {
    Tree root  = createNode('R');
    Tree nodeA = createNode('A');
    Tree nodeB = createNode('B');
    Tree nodeC = createNode('C');
    Tree nodeD = createNode('D');
    Tree nodeE = createNode('E');
    Tree nodeF = createNode('F');
    Tree nodeG = createNode('G');

    root -> left = nodeA;
    root -> right  = nodeB;

    nodeA -> left = nodeC;
    nodeA ->right  =nodeD;

    nodeB->left = nodeE;
    nodeB -> right = nodeF;

    nodeF -> left = nodeG;

    traverse(root);

    return 0;
}