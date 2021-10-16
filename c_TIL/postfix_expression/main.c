#include <stdio.h>
#include "stack.h"
#include "library.h"
#include "string_tools.h"
#define BUFFER_SIZE 100
int main(){
    
    char infix[BUFFER_SIZE]={0};
    char *postfix;
    
    read_line(stdin, infix, BUFFER_SIZE);
    printf(" %s = ",infix);
    
    postfix = convert(infix);
    printf("%s\n",postfix);
    
    return (0);
}
