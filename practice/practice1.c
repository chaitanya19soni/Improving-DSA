#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;  
    struct node * next ;  // here we will create a structure which will store the value of our data//
}*Node;



Node createNode (int data ){
    Node newNode = (Node) malloc(sizeof(struct node));
    newNode ->data = data;          // here we create a create node function in which newNodes are created and 
    newNode ->next = NULL ;         // and we are returning newNode 
    return newNode ;                //pointer is added to the node                                                    
}


void printNode( Node pr ){
    while(pr){
        printf("%d -> " , pr ->data);
        pr = pr ->next ;
    }
    printf("NULL\n");
}


int main() {

Node node1 = createNode(56);
Node node2 = createNode(6);
Node node3 = createNode(6);
Node node4 = createNode(523);
Node node5 = createNode(578);
 
node1 ->next = node2 ;
node2 ->next = node3;
node3 ->next  = node4;
node4 -> next =node5;
node5 ->next =  NULL;

printNode(node1);




    

    return 0;
}