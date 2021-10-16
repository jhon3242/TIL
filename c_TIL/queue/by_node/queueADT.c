//
//  queueADT.c
//  HellowWorld
//
//  Created by 최원준 on 2021/08/19.
//

#include "queueADT.h"

struct node
{
    Item data;
    struct node *next;
};

struct queue_type
{
    Node front;
    Node rear;
    int size;
};

void terminate(const char *message)
{
    printf("ERROR : %s",message);
    exit(EXIT_FAILURE);
}

int get_size(Queue q)
{
    return q->size;
}

Queue create(void)
{/* 새로운 Queue 생성 */
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Queue could not be created.\n");
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return (q);
}

void destroy(Queue q)
{ /* Queue를 메모리에서 지움 */
    make_empty(q);
    free(q);
}

void make_empty(Queue q)
{ /* Queue를 비움 */
    while (is_empty(q)){
        dequeue(q);
    }
}


int is_empty(Queue q)
{ /* Queue가 비어있는지 확인 */
    return (q->front == NULL);
}

void enqueue (Queue q, Item i)
{ /* 데이터 추가 함수 (push) */
    Node new = malloc(sizeof(struct node));
    if (new == NULL)
        terminate("Node could not be created.\n");
    new->data = i;
    new->next = NULL;
    if (is_empty(q))
        q->front = new;
    else
        q->rear->next = new;
    q->rear = new;
    q->size ++;
}

Item dequeue(Queue q)
{ /* 데이터 추출 함수 (pop)*/
    if (is_empty(q))
        terminate("Queue is empty.\n");
    Node temp = q->front->next;
    Item i = q->front->data;
    q->front->data = 0;
    q->front->next = 0;
    free(q->front);
    q->size --;
    q->front = temp;
    if (q->front == NULL)
        q->rear = NULL;
    return (i);
}

Item peek(Queue q)
{
    if (is_empty(q))
        terminate("Queue is empty.\n");
    return (q->front->data);
}

