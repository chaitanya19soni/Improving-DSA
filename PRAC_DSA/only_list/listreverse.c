#include<stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node*next;

}*Node ;

Node createNode(int data){
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->data = data;
    newNode ->next = NULL;
    return newNode ;
}

void printNode(Node pr)
{
    while(pr){
        printf("%d->", pr->data);
        pr = pr ->next;
    }
    printf("NULL\n");
}

Node reverseList (Node head){
    Node current = head ;
    Node prev = NULL; 
    Node next = NULL;
    while(current!=NULL){
        next = current ->next ;
        current->next = prev ;
        prev = current ;
        current = next ;
    }
    return prev ;
}


int main() {

Node node1= createNode (1);
Node node2= createNode (2);
Node node3= createNode (3);
Node node4= createNode (4);


node1->next = node2;
node2->next = node3;
node3->next = node4;
node4->next = NULL;

printf("normal list :");
printNode (node1);
    
node1 = reverseList(node1);

printf("reversed list:");
printNode(node1);

    return 0;
}

