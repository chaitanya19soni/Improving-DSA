#include<stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node*next; 
}*Node;

Node createNode (int data ){
    Node newNode = (Node )malloc(sizeof(struct node));
    newNode->data = data ;
    newNode->next = NULL;
    return newNode ;
}

void printNode(Node pr ){
    while(pr){
        printf("%d-> ", pr ->data);
        pr = pr -> next ;
    }
    printf("null\n");
}


int main() {
    



 
 
    return 0;
}