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


typedef int Item;
typedef struct node *Node;
typedef struct queue_type *Queue;

void terminate(const char *message);
int get_size(Queue q);
Queue create(void);
void destroy(Queue q);
void make_empty(Queue q);
int is_empty(Queue q);
void enqueue (Queue q, Item i);
Item dequeue(Queue q);


#endif /* queueADT_h */
