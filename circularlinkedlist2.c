#include<stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node* next ;
}*Node;

Node createNode(int data){
    Node newNode = (Node)malloc (sizeof(struct node));
    newNode->data =data;
    newNode ->next =  NULL;
    return newNode;
}

void circular(Node pr ){
    int i =0;
    Node startNode = pr ;
    while(startNode != pr || i==0 ){
        printf("%d ->", pr ->data);
        pr =  pr ->next ;
        i =1;
    }
    printf("null\n");
}


int main() {
    
Node node1= createNode(1);
Node node2= createNode(2);
Node node3= createNode(3);
Node node4= createNode(4);
Node node5= createNode(5);
Node node6= createNode(6);


node1->next = node2;
node2->next = node3;
node3->next = node4;
node4 ->next= node5;
node5 ->next= node6;
node6->next = node1 ;

    circular (node1);

    return 0;
}