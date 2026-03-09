#include <stdlib.h>
#include <stdio.h>
typedef struct tree{
    char data ;
    struct tree* left;
    struct tree * right ;
}*Tree;

Tree createNode(char data)
{
    Tree newNode = (Tree)malloc(sizeof(Tree));
    newNode -> data = data ;       // PREORDER (ROOT LEFT RIGHT )   //
    newNode -> left =NULL;        // INORDER (LEFT , ROOT, RIGHT)  //     
    newNode ->right = NULL;      //  POSTORDER(LEFT ,RIGHT,ROOT ) //
    return newNode;
}
void preorder(Tree pre){
    if (pre == NULL){
        return;
    }
    printf("%c",pre->data);
    preorder(pre->left);
    preorder(pre->right);
    

}

int main() {
    
    Tree root = createNode('R');    
    Tree nodeA = createNode('A');    
    Tree nodeB= createNode('B');    
    Tree nodeC = createNode('C');    
    Tree nodeD = createNode('D');    
    Tree nodeE = createNode('E');    
    Tree nodeF = createNode('F');    
    Tree nodeG = createNode('G');    

    root->left = nodeA;
    root->right = nodeB;

    nodeA->left = nodeC;
    nodeA->right = nodeD;

    nodeB->left = nodeE;
    nodeB->right = nodeF;

    nodeF->left = nodeG;

    
    
    
    
    
    
    preorder(root);



    return 0;
}