//
//  library.c
//  HellowWorld
//
//  Created by 최원준 on 2021/08/16.
//


#include "library.h"
#include "stack.h"
#include "string_tools.h"


Stack operand_stack;          //피연산자를 저장할 스택

int is_operator(char ch){
    for (int i =0; i < strlen(OPERATIONS);i++){
        if (ch == OPERATIONS[i])
            return (i);
    }
    return (-1);
}

int eval(char *expr){
    Item value;
    operand_stack = creat_stack();
    char *token  = strtok(expr, " ");
    while (token != NULL){
        if(*token >= '0' && *token <= '9'){         //피연산자
            value = *token - '0';
            push(operand_stack, value);
        }else if (is_operator(*token) > -1){             //연산자
            push(operand_stack, eval_op(*token));
        }else{
            terminate("Invalid character encounter.\n");
        }
        token = strtok(NULL, " ");
    }
    printf("%d\n",operand_stack->top->data);
    return 0;
}

Item eval_op(char op){
    Item result = 0;
    if(is_empty(operand_stack)){
        terminate("stack is empty.\n");
    }
    Item back = pop(operand_stack);
    if(is_empty(operand_stack)){
        terminate("stack is empty.\n");
    }
    Item front = pop(operand_stack);
    switch (op) {
        case '+' : result = (front + back); break;
        case '-' : result = (front - back); break;
        case '/' : result = (front / back); break;
        case '*' : result = (front * back); break;
    }
    return (result);
}
