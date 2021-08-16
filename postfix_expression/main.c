#include <stdio.h>
#include "stack.h"
#include "library.h"
#include "string_tools.h"
#define BUFFER_SIZE 100
int main(){
    
    char command[BUFFER_SIZE];
    
    read_line(stdin, command, BUFFER_SIZE);
    eval(command);
    
    return (0);
}
