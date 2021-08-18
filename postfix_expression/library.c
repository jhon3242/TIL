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
Stack operator_stack;         //연산자를 저장할 스택

int precedence(char op){        //연산자 우선순위를 리턴
    return PRECEDENCE[is_operator(op)];
}

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

char * convert(char *infix){
    operator_stack = creat_stack();
    
    char *postfix = (char *)malloc(sizeof(infix)+1);    // 후위 표기식
    char *pos = postfix ;       // 다음 데이터를 저장할 위치 저장
    char *token = strtok(infix, " ");
    
    while (token != NULL){
        if(*token >= '0' && *token <= '9'){         //피연산자
            sprintf(pos,"%s ", token);
            pos += (strlen(token) + 1) ;
        }else if (is_operator(*token) > -1){             //연산자
            pos = process_op(*token, pos);
        }else{
            terminate("Invalid character encounter.\n");
        }
        token = strtok(NULL, " ");
    }
    while (!is_empty(operator_stack)){
        Item top_op = pop(operator_stack);
        sprintf(pos,"%c ", top_op);
        pos += 2;
    }
    *pos = '\0';
    return postfix;
    
}

char *process_op(char op, char *pos){
    
    if (is_empty(operator_stack) || op == '(') // 여는 괄호면 무조건 push
        push(operator_stack, op);
    else{
        Item top_op = peek(operator_stack);
        if (precedence(top_op) < precedence(op) ){
            push(operator_stack, op);
        }else{
            while (!is_empty(operator_stack) && precedence(top_op) >= precedence(op)){
                pop(operator_stack);
                if (top_op == '(')          // op가 ')' 인 경우
                    break;
                sprintf(pos, "%c ", top_op);
                pos += 2;
                
                if (!is_empty(operator_stack))
                    top_op = peek(operator_stack);
            }
            if (op != ')')
                push(operator_stack, op);

        }
    }
    return (pos);
    
    
}
