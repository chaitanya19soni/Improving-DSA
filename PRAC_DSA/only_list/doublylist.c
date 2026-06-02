#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *Node;

Node createNode(int data)
{
    Node newNode = (Node)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void forward(Node pr)
{

    while (pr)
    {
        printf("%d->", pr->data);
        pr = pr->next;
    }
    printf("NULL\n");
}
void backward(Node pr)
{

    while (pr)
    {
        printf("%d->", pr->data);
        pr = pr->prev;
    }
    printf("NULL\n");
}

int main()
{

    Node node1 = createNode(1);
    Node node2 = createNode(2);
    Node node3 = createNode(3);
    Node node4 = createNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    node4->prev = node3;
    node3->prev = node2;
    node2->prev = node1;
    node1->prev = NULL;

    printf("list:");
    forward(node1);

    printf("list :");
    backward(node4);

    return 0;
}