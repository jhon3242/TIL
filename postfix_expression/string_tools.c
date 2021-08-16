#include "string_tools.h"


#include "stack.h"



void terminate(char *p){
    printf("ERROR : ");
    printf("%s\n",p);
    exit(1);
}

void read_line(FILE *fp ,char str[], int size){
    int ch,i=0;
    
    while ((ch = getc(fp))!='\n' && i<size)
        str[i++] = ch;
    str[i] = '\0';
}
