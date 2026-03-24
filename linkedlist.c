#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data ;
    struct node *next ;

}*Node ;

Node createNode(int data){
    Node newNode =  (Node )malloc (sizeof(struct node));
    newNode ->data = data;
    newNode  -> next  = NULL;
    return newNode ; 
} 


void printNode(Node pr ){
    while(pr){
        printf("%d->",pr->data);
        pr = pr->next ;
    }
    printf("null\n");
}
int main() {
    Node node1= createNode(12);
    Node node2 =  createNode(45);

    node1->next = node2;
    node2->next =  NULL;
    printNode(node1);
    return 0;
}