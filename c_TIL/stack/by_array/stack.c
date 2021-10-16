#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define INIT_CAPACITY 100

struct stack_type{
    Item * contents; // 배열
    int top;
    int size; // 배열에 크기
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
    s->contents = (Item *)malloc(INIT_CAPACITY*sizeof(Item));
    if (s->contents == NULL){
        free(s);
        s = NULL;
        terminate("Error : contents could not be created.\n");
    }
    s->top = -1;
    s->size = INIT_CAPACITY;
    return s;
}

/*
    스택 삭제 함수
        인자로 받은 스택을 삭제하는 함수이다.
        인자 : 스택
        리턴 : *
 */
void destory(Stack s){
    free(s->contents);
    s->contents=NULL;
    s->size = '\0';
    s->top = '\0';
    free(s);
    s = NULL;
}

/*
    스택 비우는 함수
        인자로 받는 스택에 내용을 지우는 함수이다. 단순히 top = -1 로만으로도 충분히 원하는 기능을 수행할 수 있다.
        인자 : 스택
        리턴 : *
 */
void make_empty(Stack s){
    s->top = -1;
}

/*
    스택이 비어있는지 확인하는 함수
        인자 : 스택
        리턴 : 비어있으면 TURE(1)를 아니면 FALSE(0)를 리턴
 */
bool is_empty(Stack s){
    return (s->top == -1) ;
}


/*
    스택이 다 찼는지 확인하는 함수
        인자 : 스택
        리턴 : 찼으면 TURE(1)를 아니면 FALSE(0)를 리턴
 */
bool is_full(Stack s){
    return (s->top >= (s->size - 1)) ;
}


/*
    push 함수
        스택에 데이터를 push 하는 함수이다. 만약 스택이 다 찼다면 재할당하여 공간을 늘린다.
        인자 : 스택 , push 할 데이터
        리턴 : *
 */
void push(Stack s, Item i){
    if (is_full(s)){
        reallocate(s);
    }
    s->top++;
    s->contents[s->top] = i;
}


/*
    pop 함수
        스택에서 top 에 있는 데이터를 리턴하고 top - 1 을 한다
        인자 : 스택
        리턴 : Item
 */
Item pop(Stack s){
    if (s == NULL){
        terminate("Error : stack is empty.\n");
    }
    s->top--;
    return s->contents[s->top+1];
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
    return s->contents[s->top];
}

/*
    reallocate 함수
        스택의 contenst 배열의 크기를 2배로 늘려주는 함수로 이전에 contents 배열을 free 한다.
        인자 : 스택
        리턴 : *
 */
void reallocate(Stack s){
    Item *new = (Item *)malloc(s->size * 2 *sizeof(Item));
    if (new == NULL){
        terminate("Error : new stack for reallocating could not be created.\n");
    }
    int i =0;
    while (i < s->size){
        new[i] = s->contents[i];
        i++;
    }
    free(s->contents);
    s->contents = new;
    s->size *= 2;
}
