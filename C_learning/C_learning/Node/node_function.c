#include "node_function.h"
#include <stdio.h>
#include <stdlib.h>
/* 헤더를 만드는 함수 */
struct node* create_node(int data){
    struct node* new_node = (struct node *)malloc(sizeof(struct node));

    new_node -> data = data;
    new_node -> next_node = NULL;
    new_node -> prev_node = NULL;

    return new_node;
}
/* 새로운 노드를 만들어 before 앞에 삽입하는 함수 */
struct node* insert_node(int data, struct node *before){
    struct node* new_node  = (struct node *)malloc(sizeof(struct node));
    struct node* next = before -> next_node;
    
    new_node -> data = data;
    new_node -> prev_node = before;
    new_node -> next_node = next;
    
    before -> next_node = new_node;
    if (next){
        next -> prev_node = new_node;
    }
    
    return new_node;
}

/* from 노드부터 끝까지 노드를 출력하는 함수 */
void print_node(struct node *from){
    printf("-----start print-----\n");
    while(from){
        printf("%d\n", from->data);
        from = from -> next_node;
    }
    printf("------end print------\n");
}
/* delecte 로 전달받은 노드를 삭제하는 함수 */
void delete_node(struct node *delecte, struct node *head){
    if (delecte == head){
        free(head);
    } else{
        struct node *currnet = (struct node *)malloc(sizeof(struct node));
        currnet = head;
        while (currnet){
            if (currnet -> next_node == delecte){
                currnet -> next_node = delecte -> next_node;
                free(delecte);
                break;
            }
            currnet = currnet -> next_node;
        }
    }
    
}

void count_node(struct node *head){
    int count = 0;
    struct node *next = head;
    while (next){
        next = next -> next_node;
        count += 1;
    }
    printf("%d\n",count);
}

/* 특정 값이 주어지면 그 값을 가지고 있는 노드가 있으면 1을 없으면 0을 리턴한다 */
int bool_has_node(struct node *head, int data){
    struct node *next = head;
    while (next){
        if (next ->data == data) return 1;
        next = next -> next_node;
    }
    return 0;
}
/* 마지막에 있는 노드가 헤드를 가리키도록 하는 함수
    따라서 노드가 무한루프처럼 처음과 끝이 없어진다.
 */
void tail_to_head(struct node *head){
    struct node *next = head;
    while (next -> next_node){
        next = next -> next_node;
    }
    next -> next_node = head;
    head -> prev_node = next;
}
