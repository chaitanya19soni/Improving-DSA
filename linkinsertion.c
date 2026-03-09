#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *next;
}*Node;

Node createNode(int data){
    Node newNode= (Node)malloc(sizeof(Node));
    newNode->data =data;
    newNode->next = NULL;
    return newNode;
}

void printNode(Node pr){
    while (pr){
        printf("%d->", pr ->data);
        pr = pr ->next;
    }
    printf("null\n");
}

Node insertion (Node head , Node newNode , int pos ){
if (pos == 1 ){
    newNode->next = head;
    return newNode;
}
int i = 1;
Node current = head; 
while (i< pos-1 && current!=NULL){
    current = current -> next ;
    i++;
}

if (current !=NULL){
    newNode ->next =  current ->next ;
    current -> next  = newNode ;
}

return newNode;
}


int main() {

    Node node1 = createNode(21);
    Node node2 = createNode(22);
    Node node3 = createNode(23);
    Node node4 = createNode(24);
    Node node5 = createNode(25);
    Node node6 = createNode(26);
    Node node7 = createNode(27);
    Node node8 = createNode(28);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;


    printNode(node1);

    Node noded = createNode(78);
   node1 = insertion(node1,noded,2);
    printNode(node1);

    return 0;
}