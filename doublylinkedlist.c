#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node * prev ;
    struct node* next ;
}*Node;

Node createNode (int data){
    Node newNode =  (Node)malloc(sizeof(struct node));
    newNode->data =data ;
    newNode->next = NULL;
    return newNode;
}

void forward (Node pr) {
    printf("Forward  :");
    while (pr){
    printf("%dd->",pr->data);
    pr= pr ->next ;
}
printf("null\n");
}

void backward (Node pr ){
    printf("Backward :"); 
    while (pr){
        printf("%d->",pr->data);
        pr = pr ->prev;
    }
    printf("null\n");
}

int main() {
 
   
    Node node1 = createNode(12);
    Node node2 = createNode(13);
    Node node3 = createNode(14);
    Node node4 = createNode(15);
    
    node1->next =  node2;
    node2 ->next = node3;
    node3 ->next = node4;
    node4->next = NULL;

    node4->prev = node3;
    node3->prev = node2;
    node2->prev = node1;
    node1->prev = NULL;

    forward(node1);
    backward(node4);
    
    return 0;
}