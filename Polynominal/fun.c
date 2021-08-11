#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fun.h"





/* 항 만드는 함수 */
Term *creat_term_instance(void){
    Term *t = (Term *)malloc(sizeof(Term));
    t->coef = 0;
    t->expo = 0;
    return t;
}


/* 다항식 만드는 함수*/
Polynominal * creat_polynominal_instance(char name){
    Polynominal *ptr_poly = (Polynominal *)malloc(sizeof(Polynominal));
    ptr_poly -> name = name;
    ptr_poly -> size = 0;
    ptr_poly -> first = NULL;
    return ptr_poly;
}

/* 다항식에 항을 더하는 함수 */
void add_term(int c, int e, Polynominal *poly){
    if (c == 0){
        return;
    }
    Term *p = poly -> first, *q = NULL; // 현재 다항식의 첫 항
    while (p != NULL && e < p->expo){
        q = p;
        p = p ->next;
    }
    /* 차수가 같은 경우 */
    if (e == p->expo){
        p->coef += c;
        if (p->coef == 0){ // 더해서 0이 되면
            if (q == NULL){ // 만약 p가 첫 항이였다면
                poly->first = p->next;
            }else{
                q -> next = p -> next;
                poly -> size --;
                free(p);
            }
        }
        return;
    }


    /* 차수가 다른 경우 */
    Term *term = creat_term_instance();
    term -> coef = c;
    term -> expo = e;

    if (q == NULL){ // 맨 앞에 삽입하는 경우
        poly -> first = term;
        term -> next = p;


    } else { //
        q->next = term;
        term -> next = p;
    }
    poly -> size ++;
}

/*
    변수의 값이 주어졌을 떄 주어진 항의 값을 구하는 함수
 */
int eval_term(Term *t, int x){
    int result = x;
    int i=0;
    while (i< (t -> expo)){
        result *= x; // 차수 만큼 곱해줘야 하기 떄문
        i++;
    }
    return (result);
}

/*
    변수의 값이 주어졌을 떄 방정식의 해를 구하는 함수
 */
int eval(Polynominal *poly, int x){
    int result = 0;
    Term *t = poly -> first;
    while (t){
        result += eval_term(t, x);
        t = t->next;
    }
    return (result);
}

/*
    다항식 연산 함수
 */
void handle_calc(char name, char *x_value){
    int i=0,answer=0;
    while (polys[i]->name != name){
        i++;
    }
    answer = eval(polys[i], *x_value);
    printf("%d \n",answer);
}

/*
    다항식을 출력하는 함수
 */
void print_poly(Polynominal *p){

    Term *t = p->first;
    printf("%c = ",p->name);
    while (t){
        printf("%d",t->coef);
        if (t->expo == 0) break;
        printf("x^%d ",t->expo);
        t = t->next;
    }
}

int read_line(FILE *fp,char cmd[], int size){
    int ch, i=0;
    while ((ch = getc(fp)) != '\n' && i<size){
        cmd[i] = ch;
        i++;
    }
    return (i);
}

/*
    주어진 이름의 방정식을 출력하는 함수
 */
void handle_print(char name){
    int i=0;
    Polynominal *p;
    while (i < MAX_POLYS){
        p = polys[i];
        if (p->name == name){
            print_poly(p);
        }
        i++;
    }

}
void erase_blanks(char *expression){
    int i=0,tmp;
    while (expression[i] != '\0'){
        if (expression[i] == ' '){
            tmp = i;
            while (tmp + 1 < BUFFER_LENGHT && expression[tmp] != '\0' ){
                expression[tmp] = expression[tmp+1];
                tmp ++;
            }
            expression[tmp - 1] ='\0';
        }
        i++;
    }
}
/*
    다항식을 파괴하는 함수
 */
void destroy_polynominal(Polynominal *p){
    if (p == NULL){
        printf("pointer p is NULL.\n");
        return;
    }
    Term *t = p->first;
    Term *tmp = NULL;
    while (t){
        tmp = t;
        t = t->next;
        free(tmp);
    }
    free(p);
    printf("destroy success.\n");
}

/*
    term 추가 함수
 */
int prase_and_add_term(char *body,int start, int end, Polynominal *poly){
    int i = start;
    int sign_coef = 1,coef=0,expo;
    if(body[i] == '+'){
        i++;
    }else if (body[i] == '-'){
        sign_coef = -1;
        i++;
    }
    /* 계수 부분을 읽는 부분*/
    while (i<end && body[i] >= '0' && body[i] <= '9'){
        coef = coef*10 + (int)(body[i] - '0');
        i++;
    }
    if (coef == 0){
        coef = sign_coef;
    }else{
        coef *= sign_coef;
    }
    if (i >= end){
        add_term(coef, 0, poly);
        return 1;
    }
    if (body[i] != 'x'){
        return 0;
    }
    i++;
    if (i >= end){
        add_term(coef, 1, poly);
        return 1;
    }
    if (body[i] != '^'){
        return 0;
    }
    i++;
    /* 지수 부분을 읽는 부분*/
    expo = 0;
    while (i<end && body[i] >= '0' && body[i] <= '9'){
        expo = expo*10 + (int)(body[i] - '0');
        i++;
    }
    add_term(coef, expo, poly);
    return 1;
}


/*
    새로 정의한 다항식을 추가하는 함수
 */
Polynominal *creat_by_parse_polynominal(char name, char *body){
    int i=0,begin_index=0,result;
    Polynominal *p = creat_polynominal_instance(name);
    while (i < strlen(body)){
        if (body[i] == '+' || body[i] == '-'){
            i++;
        }
        while (i<strlen(body) && body[i] != '+' && body[i] != '-'){
            i++;
        }
        result = prase_and_add_term(body,begin_index,i,p);//term 추가 함수
        if (result == 0){ // 오류 발생시
            destroy_polynominal(p); // 다항식 파괴
        }
        begin_index = i;
    }
    return p;

}
/*
    다항식 리스트에 추가하는 함수
 */
void insert_polynominal(Polynominal *p){
    for (int i=0; i<n ; i++){
        if(polys[i]->name == p->name){
            destroy_polynominal(polys[i]);
            polys[i] = p;
            return;
        }
    }
    polys[n++] = p;
}
/*
    두 다항식을 더하는 함수
 */
Polynominal *creat_by_add_two_polynominal(char name, char f, char g){
    Polynominal *p= creat_polynominal_instance(name);
    Term *t;
    int i=0;
    while (polys[i]->name != f){
        i++;
    }
    t = polys[i]->first;

    while (t){
        add_term(t->coef, t->expo, p);
        t = t->next;
    }

    i = 0;
    while (polys[i]->name != g){
        i++;
    }
    t = polys[i]->first;

    while (t){
        add_term(t->coef, t->expo, p);
        t = t->next;
    }


    return p;
}

/*

 */
void handle_definition(char *exprssion){
    Polynominal *p=NULL;
    char *ex_name, *ex_body;
    erase_blanks(exprssion);
    ex_name = strtok(exprssion, "=");
    if (ex_name == NULL && strlen(ex_name) != 1)  {
        printf("Invalied name.\n");
        return;
    }
    ex_body = strtok(NULL, "=");
    if (ex_body == NULL && strlen(ex_body) <=0){
        printf("Invalied polynominal.\n");
        return;
    }
    // 경우의 수를 두가지로 나눔 (1. 기존의 함수의 연산/ 2. 새로운 함수 정의 )
    if (ex_body[0] >= 'a' && ex_body[0]<='z' && ex_body[0] !='x'){
        // 경우의 수 1.
        char *former = strtok(ex_body, "+");
        if (former == NULL || strlen(former) != 1){
            printf("Invalied expression format");
            return;
        }
        char *later = strtok(NULL, "+");
        if (later == NULL || strlen(later) != 1){
            printf("Invalied expression format");
            return;
        }
        p =creat_by_add_two_polynominal(ex_name[0], former[0], later[0]);// 두 다항식을 더하는 함수
        insert_polynominal(p); // 만들어진 다항식을 배열에 넣는 함수

    }else{
        // 경우의 수 2.
        p = creat_by_parse_polynominal(ex_name[0],ex_body);
        insert_polynominal(p);
    }

}

/*
    명령어를 수행하는 함수
 */
void process_command(void){
    char command_line[BUFFER_LENGHT], copy[BUFFER_LENGHT];
    char *command=NULL, *argument1, *argument2;
    while(1){
        printf("$ ");
        if(read_line(stdin, command_line, BUFFER_LENGHT) <= 0) continue;
        strcpy(copy,command_line);
        command = (char *)strtok(command_line, " ");

        if (strcmp(command, "print")==0){
            argument1 = strtok(NULL, " ");
            if (argument1 == NULL) {
                printf("Invalied argument.\n");
                continue;
            }
            handle_print(*argument1);
        }else if(strcmp(command, "calc")==0){
            argument1 = strtok(NULL, " ");
            if (argument1 == NULL) {
                printf("Invalied argument.\n");
                continue;
            }
            argument2 = strtok(NULL, " ");
            if (argument2 == NULL) {
                printf("Invalied argument.\n");
                continue;
            }

            handle_calc(argument1[0], argument2);
        }else if(strcmp(command, "exit")==0){
            break;

        }else{

            handle_definition(copy);
        }
    }
}
