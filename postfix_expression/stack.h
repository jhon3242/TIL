
#ifndef STACK_H
#define STACK_H


int check_op(int c);
void read_str(void);
typedef int Item;
struct node
{
    Item data;
    struct node *next;
};
struct stack
{
    struct node *top;
};
typedef struct node *Node;
typedef struct stack *Stack;

Stack creat_stack(void);
void push(Stack s,Item data);
Item pop(Stack s);
Item peek (Stack s);
int is_empty(Stack s);

#endif
