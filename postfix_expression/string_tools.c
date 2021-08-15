#include "string_tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

static  char OPERATIONS[] = "+-/*" ;


int is_operator(char ch){
    for (int i =0; i < strlen(OPERATIONS);i++){
        if (ch == OPERATIONS[i])
            return (1);
    }
    return (0);
}

void terminate(char *p){
    printf("ERROR : ");
    printf("%s\n",p);
    exit(1);
}
