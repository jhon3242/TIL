#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define INIT_CAPACITY 100



struct node{
    Item data; // 데이터
    struct node *next; // 다음 노드 주소값
};

struct stack_type{
    struct node *top; // top 노드 주소값
};

/*
    오류 출력 함수
        인자로 받은 문자열을 출력하고 프로그램을 종료한다.
        인자 : 출력문자열의 리터럴 스트링
        리턴 : *
 */
static void terminate(const char *message){
    printf("%s\n",message);
    exit(1); // 프로그램 종료
}

/*
    스택 생성 함수
        스택을 새롭게 만들고 만든 스택의 포인터를 리턴한다.
        인자 : *
        리턴 : 스택
 */
Stack create(void){
    Stack s = (Stack)malloc(sizeof(struct stack_type));
    if (s == NULL){
        terminate("Error : stack could not be created.\n");
    }
    s->top = NULL;

    return s;
}

/*
    스택 삭제 함수
        인자로 받은 스택을 삭제하는 함수이다.
        인자 : 스택
        리턴 : *
 */
void destory(Stack s){
    make_empty(s);
    free(s);
    s = NULL;
}

/*
    스택 비우는 함수
        인자로 받은 스택을 지우는 함수로 스택이 비워질때 까지 pop을 한다.
        인자 : 스택
        리턴 : *
 */
void make_empty(Stack s){
    while (!is_empty(s)){
        pop(s);
    }
}

/*
    스택이 비어있는지 확인하는 함수
        인자 : 스택
        리턴 : 비어있으면 TURE(1)를 아니면 FALSE(0)를 리턴
 */
bool is_empty(Stack s){
    return (s->top == NULL) ;
}




/*
    push 함수
        스택에 데이터를 push 하는 함수이다. 새로운 노드를 만들어서 그 노드를 top으로 바꿔준다.
        인자 : 스택 , push 할 데이터
        리턴 : *
 */
void push(Stack s, Item i){
    struct node *new = malloc(sizeof(struct stack_type));
    if (new == NULL){
        terminate("Error : Could not make node.\n");
    }
    new->data = i;
    new->next = s->top;
    s->top = new;

}


/*
    pop 함수
        스택에서 top 에 있는 데이터를 리턴하고 이전 top을 지운다.
        인자 : 스택
        리턴 : Item
 */
Item pop(Stack s){
    struct  node *old_top;
    Item value;

    if (is_empty(s)){
        terminate("Error : stack is empty.\n");
    }
    old_top = s->top;
    value = old_top->data;
    s->top = old_top->next;
    free(old_top);
    old_top->data = 0;
    old_top->next = NULL;
    old_top = NULL;

    return value;
}


/*
    peek 함수
        스택에서 top 에 있는 데이터를 리턴한다.
        인자 : 스택
        리턴 : Item
 */
Item peek(Stack s){
    if (s == NULL){
        terminate("Error : stack is empty.\n");
    }
    return s->top->data;
}

