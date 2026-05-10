#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data ;
    struct node *next ;
}*Node;

Node createNode (int data ){
    Node newNode =  (Node)malloc(sizeof(struct node));
    newNode ->data = data;
    newNode ->next = NULL;
    return newNode ;
}

void printNode (Node pr ){
    while(pr){
        printf("%d->", pr ->data);
        pr = pr -> next;
    }
    printf("NULL\n");
}

Node concatenate (Node head1, Node head2){
    if (head1== NULL){
        return head2;
    }
    if (head2== NULL){
        return head1;
    }

    Node temp = head1;

    while(temp ->next != NULL) {
            temp = temp ->next ;
    }
    temp ->next = head2;

    return head1;
}


int main() {
        Node node1 = createNode(10);
    Node node2 = createNode(20);
    Node node3 = createNode(30);

    node1 ->next = node2 ;
    node2 ->next = node3 ;              // linking first list
    node3 ->next = NULL ;

    // second linked list : 40 -> 50 -> 60
    Node node4 = createNode(40);
    Node node5 = createNode(50);
    Node node6 = createNode(60);

    node4 ->next = node5 ;
    node5 ->next = node6 ;              // linking second list
    node6 ->next = NULL ;

    printf("List 1 : ");
    printNode(node1);                   // printing first list

    printf("List 2 : ");
    printNode(node4);                   // printing second list

    node1 = concatenate(node1 , node4); // concatenating both lists

    printf("Concatenated List : ");
    printNode(node1);                   // printing final concatenated list

    return 0;
}