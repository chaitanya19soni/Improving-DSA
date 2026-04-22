#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
   struct  node *next ; 
}*Node;

Node createNode (int data){
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode ->data = data ;
    newNode ->next = NULL;
    return newNode ;
}

void printNode(Node pr ){
    while(pr){
        printf("%d->", pr ->data);
        pr = pr->next ;
    }
    printf("NULL\n");
}


int main() {
    Node node1 = createNode(56);
    Node node2 = createNode(57);
    Node node3 = createNode(58);
    Node node4 = createNode(59);


    node1->next = node2;
    node2->next= node3;
    node3->next = node4;
    node4->next = NULL;

    printNode(node1);




    return 0;
}