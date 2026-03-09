#include <stdio.h>
#include <stdlib.h>
typedef struct node{
int data ;
struct node * next ;
}*Node;

Node createNode(int data){
Node newNode = (Node)malloc(sizeof(Node));
 
newNode ->data = data ;
newNode->next  =  NULL; 
return newNode ; 
}

void printNode(Node pr)
{
    while(pr)
{
    printf("%d ->", pr -> data);
 pr = pr -> next ;
}
 printf("null\n");
}


int main() {
    Node node1 = createNode(12); 
    Node node2 = createNode(13);
    Node node3 = createNode(14); 
    Node node4 = createNode(15) ;
    Node node5 = createNode(16) ;

 node1->next = node2;
 node2->next = node3;
 node3->next = node4;
 node4->next = node5;
 node5->next = NULL;    
   
   printNode(node1);
   
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
   
   
   return 0;
}