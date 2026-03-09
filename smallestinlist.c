#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int data;
    struct node *next;

} *Node;

Node createNode(int data)
{

    Node newNode = (Node)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int lowest(Node head)
{

    int min = head->data;
    Node currentValue = head->next;
    while (currentValue)
    {
        if (currentValue->data < min)
        {
            min = currentValue->data;
        }

        currentValue= currentValue->next; //current me value stroed hai gandu//
    }

    return min;
}

int main()
{

    Node node1 = createNode(45);
    Node node2 = createNode(56);
    Node node3 = createNode(23);
    Node node4 = createNode(321);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    printf("The lowest value in the linked list is: %d\n", lowest(node1));
    return 0;
}