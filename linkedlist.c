#include <stdlib.h>
#include <stdio.h>
typedef struct node {
    int data;
    struct node * next ;
}*Node;

Node createNode(int data){
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode-> data = data ;
    newNode -> next = NULL;
    return newNode ;
}

void printNode(Node pr){
    while(pr){
        printf("%d->",pr->data);
        pr = pr -> next ;
    }
    printf("NULL\n");
}

Node makeList (Node head , int val){
    Node newNode = createNode(val);

    if (head == NULL){
        return newNode;
    }
    Node current = head ;
    while(current->next != NULL){
        current = current -> next ;
    }
    current->next = newNode;
    return head;
}


int main() {
    int n,val;
    Node head = NULL;
    scanf("%d",&n);

    for (int i =1 ;i<=n;i++){
        printf("put the valu: %d",i);
        scanf("%d",&val);
        head = makeList(head,val);
    }
    printNode(head);
    return 0;
}