#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next ;

}*Node;

Node createNode (int data){
    Node newNode =(Node )malloc (sizeof(struct node));
    newNode ->data = data;
    newNode ->next  = NULL;
}

void printNode(Node pr){
    while(pr){
        printf("%d ->",pr->data);
        pr= pr->next ;
    }
    printf("null\n");
}
int lowest (Node head){
    int min =  head->data ;
   Node current = head->next;
   while(current){
    if (current->data<min ){
        min =  current->data;
    }
    current =  current->next ;
   }
   return min ;
}

Node insertion (Node head ,Node newNode , int pos){
    if (pos==1){
        newNode ->next =head;
        return newNode ;
    }

    Node current =  head;
    int i ;
    while(i<pos-1 && current !=NULL){
        current = current ->next ;
        i++;
    }

    if (current!=NULL){
        newNode->next =  current->next ;
        current->next =  newNode ;
    }

    return head;
}

Node deletion (Node head ,Node nodetodele){
    if (head ==  nodetodele){
        Node newNode = head->next; 
        free(head);
        return newNode;
    }
    Node current =head;
 while(current->next && current!=nodetodele){
    current =  current->next ;
 } 
 if (current->next == NULL){
    return head;
 }

 Node temp =  current ->next ;
 current ->next  =  current -> next ->next ;
 free(temp);
 return head;

}



int main() {
    Node node1= createNode(56);
    Node node2= createNode(52);
    Node node3= createNode(58);
    Node node4= createNode(54);
    Node node5= createNode(51);

    node1->next = node2;
    node2->next =  node3;
    node3->next = node4;
    node4->next = node5;
    node5->next =  NULL;

    printNode(node1);
    printf("the lowest value is : %d\n",lowest(node1));
    
    Node nodeA = createNode(56);
    node1 = insertion(node1,nodeA,4);
    printf("After the insertion:");
    printNode(node1);

    node1 = deletion(node1,nodeA);
    printf("After deletion ");
    printNode(node1);
    


    return 0;
}