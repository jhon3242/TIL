//
//  queueADT.c
//  HellowWorld
//
//  Created by 최원준 on 2021/08/19.
//

#include "queueADT.h"

#define INIT_CAPACITY 100

struct queue_type {
    Item *contents; // 배열
    int front;
    int rear;
    int size;       // 저장된 데이터의 개수
    int capacity;   // 배열 contents 의 크기
};

void terminate(const char *message)
{
    printf("ERROR : %s",message);
    exit(EXIT_FAILURE);
}

int get_size(Queue q)
{
    return (q->size);
}

Queue create(void)
{
    Queue q = (Queue)malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Queue could not be created.\n");
    q->contents = (Item *)malloc(INIT_CAPACITY*sizeof(Item));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = INIT_CAPACITY;
    
    return (q);
}

void destory(Queue q)
{
    free(q->contents);
    q->contents = NULL;
    free(q);
    q = NULL;
}

void make_empty(Queue q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool is_empty(Queue q)
{
    return (q->size == 0);
}

bool is_full(Queue q)
{
    return (q->size == q->capacity);
}


void enqueue(Queue q, Item i)
{
    if (is_full(q)){
        //reallocate(q);
    }
    q->rear = (q->rear + 1)%q->capacity;
    q->contents[q->rear] = i;
    q->size ++;
}

Item dequeue(Queue q)
{
    if (is_empty(q))
        terminate("Queue is empty.\n");
    Item result = q->contents[q->front];
    q->contents[q->front] = '\0';
    q->front = (q->front + 1) % q->capacity;
    q->size -- ;
    return  (result);
}

Item peek(Queue q)
{
    if (is_empty(q))
        terminate("Queue is empty.\n");
    return q->contents[q->front];
}

void reallocate(Queue q)
{
    Item *tmp = (Item *)malloc(q->capacity * 2 * sizeof(Item));
    if (tmp == NULL)
        terminate("Queue could not be expanded.\n");
    for (int i = 0 ; i < q->size ; i++){
        tmp[i] = q->contents[q->front];
        q->front = (q->front + 1) % q->size;
    }
    free(q->contents);
    q->contents = tmp;
    q->capacity *= 2;
    q->front = 0;
    q->rear = q->size - 1;
}
