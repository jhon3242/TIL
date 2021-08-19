//
//  queueADT.h
//  HellowWorld
//
//  Created by 최원준 on 2021/08/19.
//

#ifndef queueADT_h
#define queueADT_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

void terminate(const char *message);
int get_size(Queue q);
Queue create(void);


#endif /* queueADT_h */
