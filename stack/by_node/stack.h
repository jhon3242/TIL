#ifndef STACK_H
#define STACK_H

#include <stdbool.h> // bool 타입 사용 가능

typedef int Item; // 코드의 재사용을 위해서 현재는 스택이 int 이지만 다른곳에서는 다른 데이터 형으로 사용할 수 있게 하기 위함
typedef struct stack_type *Stack ;

static void terminate(const char *message);
Stack create(void);
void destory(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);

#endif

