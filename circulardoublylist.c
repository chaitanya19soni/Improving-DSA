#include<stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next ;
    struct node*prev ;
}*Node;

Node creatNode(int data){
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next =  NULL;
    newNode->prev  = NULL;
    return newNode ;
}

void forwardcircular(Node pr){
    Node startNode = pr;
    int i = 0 ;
    printf("Forward list :");
    while(pr!= startNode || i==0){
        printf("%d-> ",pr->data);
        pr= pr->next;
        i=1;
    }

    printf("null\n");
}


void backwardcircular(Node pr){
    Node startNode = pr;
    int i = 0 ;
    printf("Backward list :");
    while(pr!= startNode || i==0){
        printf("%d-> ",pr->data);
        pr= pr->prev;
        i=1;
    }
    printf("null\n");
}




int main() {
    Node node1 =  creatNode(12);
    Node node2 =  creatNode(22);
    Node node3 =  creatNode(32);
    Node node4 =  creatNode(42);
    Node node5 =  creatNode(52);
    Node node6 =  creatNode(62);


    node1->next =  node2;
    node2->next = node3;
    node3->next  = node4;
    node4->next = node5;
    node5->next = node6;
    node6 ->next = node1;

    node6->prev =  node5;
    node5->prev = node4;
    node4->prev =  node3;
    node3->prev =  node2;
    node2->prev =  node1;
    node1-> prev = node6;

    forwardcircular(node1);
    backwardcircular(node6);

    return 0;
}