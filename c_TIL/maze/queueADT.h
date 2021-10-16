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



typedef struct node *Node;
typedef struct queue_type *Queue;
typedef struct position Position;
struct position
{
    int x;
    int y;
    int length;
};

struct node
{
    struct position p;
    struct node *next;
};

struct queue_type
{
    Node front;
    Node rear;
    int size;
};


void terminate(const char *message);
int get_size(Queue q);
Queue create(void);
void destroy(Queue q);
void make_empty(Queue q);
int is_empty(Queue q);
void enqueue (Queue q, Position i);
Position dequeue(Queue q);


#endif /* queueADT_h */
