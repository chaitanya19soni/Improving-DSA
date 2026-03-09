#include <stdlib.h>
#include <stdio.h>


typedef struct node{
    int data ;
    struct node *next ;
}*Node;

Node createNode(int data ){
    Node newNode = (Node)malloc(sizeof(Node));
    newNode->data= data ;
    newNode ->next = NULL;
    return newNode;
}

void printNode(Node pr){
    while (pr){

        printf("%d->", pr ->data);
        pr = pr -> next ;
    }
    printf("null\n");
}


Node deletion (Node head , Node nodetodele){
    if (head == nodetodele){
        Node newHead = head->next ;
        free(head);
        return newHead;
    }
     Node current = head;

    while(current->next && current->next !=nodetodele){
        
        current = current ->next ;
    }

    if (current->next ==NULL){
        return head;
    }

    Node temp = current->next ;
    current->next = current ->next ->next ;
    free(temp);

    return head;

    }








int main() {
    

    Node nodeA = createNode(1);
    Node nodeB = createNode(2);
    Node nodeC = createNode(3);
    Node nodeD = createNode(4);
    Node nodeE = createNode(5);


    nodeA->next= nodeB;
    nodeB->next = nodeC;
    nodeC-> next = nodeD;
    nodeD->next = nodeE;
    nodeE-> next = NULL;
    
   nodeA =  deletion(nodeA,nodeB);
    printNode(nodeA);


    free(nodeA); 
    free(nodeC);
    free(nodeD);
    free(nodeE);



    return 0;
}