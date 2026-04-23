#include <stdlib.h>
#include <stdio.h>

struct node{
    char value;
    struct node * next ;
}*Node;

typedef struct stack {
    struct node *head;
    int size;
}*Stack;

Stack createStack (){
 Stack s = (Stack)malloc(sizeof (struct stack));
 s->head = NULL;
 s->size = NULL;
 return s;
}



int main() {
    
    return 0;
}
