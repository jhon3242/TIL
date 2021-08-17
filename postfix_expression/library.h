//
//  library.h
//  HellowWorld
//
//  Created by 최원준 on 2021/08/16.
//

#ifndef library_h
#define library_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

static  char OPERATIONS[] = "+-/*" ;
static  int  PRECEDENCE[] = {1,1,2,2} ;
int is_operator(char ch);
int eval(char *expr);
Item eval_op(char op);
char *process_op(char op, char *pos);
char * convert(char *infix);
#endif /* library_h */
