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

struct queue_type;
void terminate(const char *message);
int get_size(Queue q);
Queue create(void);
void destroy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
bool is_full(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek(Queue q);
void reallocate(Queue q);

#endif /* queueADT_h */
