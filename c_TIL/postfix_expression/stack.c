
#include <stdlib.h>
#include "stack.h"
#include "string_tools.h"




Stack creat_stack(void){
    Stack s =(Stack)malloc(sizeof(struct stack));
    if (s == NULL)
        terminate("Could not make stack.");
    s->top = NULL;
    return (s);
}

void push(Stack s,Item data){
    Node n = malloc(sizeof(struct node));
    if (n == NULL)
        terminate("Could not make node.");
    n->data = data;
    n->next = s->top;
    s->top = n;
}


Item pop(Stack s){
    Item p = s->top->data;
    Node n = s->top;
    s->top = s->top->next;
    n->data = 0;                //make NULL
    n->next = NULL;
    free(n);
    
    return (p);
}

Item peek (Stack s){
    return (s->top->data);
}

int is_empty(Stack s){
    if (s->top == NULL)
        return (1);
    return (0);
}
