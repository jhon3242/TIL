#include <stdlib.h>
#include "book_function.h"
#include "string.h"
#include <stdio.h>
#include <string.h>

/* 헤더 노드 생성 함수 */
struct books * add_head( int *total_book_num){
    struct books *p = (struct books *)malloc(sizeof(struct books));
    printf("책의 이름 :");
    scanf("%s",p -> book_name);

    printf("책의 저자 :");
    scanf("%s",p -> book_writer);

    printf("책의 출판사 :");
    scanf("%s",p -> book_publisher);
    
    p -> next = NULL; // 다음 노드에 null 입력
    p -> book_status = usalbe; // 책 상태 기본값 설정
    (*total_book_num)++; // 전체 책의 개수에 1 더하기
    return p;
}

/* 책 추가하는 함수*/
struct books * add(struct books *current, int *total_book_num){
    struct books *p = (struct books *)malloc(sizeof(struct books));
    
    printf("책의 이름 :");
    scanf("%s",p -> book_name);

    printf("책의 저자 :");
    scanf("%s",p -> book_writer);

    printf("책의 출판사 :");
    scanf("%s",p -> book_publisher);
    
    p -> next = current -> next; // 이전 노드가 가리키고 있던것을 가리킴
    p -> book_status = usalbe; // 책 상태 기본값 설정
    p -> book_num = *total_book_num;
    (*total_book_num)++; // 전체 책의 개수에 1 더하기
    current -> next = p; // 이전 노드와 연결
    return p;
}


/* 책 검색하는 함수*/

void search (struct books *head){
    int user_choice,check=1;
    struct books *from = head;
    char contents[30]; // 검색할 내용
    printf("어떤 것을 가지고 검색하실 건가요?\n");
    printf("1. 책 이름\n");
    printf("2. 책 저자\n");
    printf("3. 책 출판사\n");
    printf("입력 :");
    scanf("%d",&user_choice);

    printf("검색할 내용을 입력하세요. :");
    scanf("%s",contents);

    if (user_choice == 1){
        while (from){
            if (compare(contents, from->book_name)){
                printf("-------------------------------\n");
                printf("책 번호 : %d\n",from -> book_num);
                printf("책 제목 : %s\n",from->book_name);
                printf("책 저자 : %s\n",from->book_writer);
                printf("책 출판사 : %s\n",from->book_publisher);
                printf("-------------------------------\n");
                printf("더 찾으려면 1번을, 끝내려면 0을 입력하세요. : ");
                scanf("%d",&check);
 
                /* 계속 찾으려면 check 는 1 아니면 0 */

                if (check == 0) break;
            }
            from = from -> next;
        }
        if (check == 1) printf("검색 결과 없습니다.\n");

    }else if (user_choice == 2){
        while (from){
            if (compare(contents, from->book_writer)){
                printf("-------------------------------\n");
                printf("책 번호 : %d\n",from -> book_num);
                printf("책 제목 : %s\n",from->book_name);
                printf("책 저자 : %s\n",from->book_writer);
                printf("책 출판사 : %s\n",from->book_publisher);
                printf("-------------------------------\n");
                printf("더 찾으려면 1번을, 끝내려면 0을 입력하세요. : ");
                scanf("%d",&check);
 
                /* 계속 찾으려면 check 는 1 아니면 0 */

                if (check == 0) break;
            }
            from = from -> next;
        }
        if (check == 1) printf("검색 결과 없습니다.\n");


    }else if (user_choice == 3){
        while (from){
            if (compare(contents, from->book_publisher)){
                printf("-------------------------------\n");
                printf("책 번호 : %d\n",from -> book_num);
                printf("책 제목 : %s\n",from->book_name);
                printf("책 저자 : %s\n",from->book_writer);
                printf("책 출판사 : %s\n",from->book_publisher);
                printf("-------------------------------\n");
                printf("더 찾으려면 1번을, 끝내려면 0을 입력하세요. : ");
                scanf("%d",&check);
 
                /* 계속 찾으려면 check 는 1 아니면 0 */

                if (check == 0) break;
            }
            from = from -> next;
        }
        if (check == 1) printf("검색 결과 없습니다.\n");
    }
}
 
/* 책 빌리는 함수 */

int borrow (struct books *head){
    int book_num;
    struct books *from = head;
    printf("빌릴 책 번호를 입력해주세요. : ");
    scanf("%d",&book_num);
    while (from){
        if (from->book_num == book_num){
            printf("-------------------------------\n");
            if (from -> book_status == in_use){
                printf("이 책은 대출중입니다.\n");
                return 0;
            } else{
                from -> book_status = in_use;
                printf("책을 대출 하였습니다.\n");
                return 0;

            }
        }
        from = from -> next;
    }
    
    printf("책 번호를 찾을 수 없습니다.\n");
    return 0;
}

/* 책 반납 함수 */

int book_return (struct books *head){
    int book_num;
    struct books *from = head;
    printf("반납할 책 번호를 입력해주세요. : ");
    scanf("%d",&book_num);
    while (from){
        if (from->book_num == book_num){
            printf("-------------------------------\n");
            if (from -> book_status == usalbe){
                printf("이 책은 이미 반납했습니다\n");
                
                return 0;
            } else{
                from -> book_status = usalbe;
                printf("책을 반납 하였습니다.\n");
                
                return 0;

            }
        }
        from = from -> next;
    }
    printf("책 번호를 찾을 수 없습니다.\n");
    return 0;
}


/* 기존에 파일에 있던 내용을 읽고 노드에 추가하고 스트림을 리턴하는 함수 */
void readlist_stream(struct books **phead,struct books ** pnext, int *total_num){
    struct books *current=NULL;
    char num[10]={},usable[20]={};
    int first = 1;
    FILE *fp = fopen("/Users/choewonjun/Documents/GitHub/C_TIL/C_learning/C_learning/Library_system/list.txt", "r+");
    /* 기존 파일을 읽어서 노드에 등록하는 작업*/
    fseek(fp, strlen("책번호 이름 저자 출판사 대출여부\n"), SEEK_SET);
    
    while (fscanf(fp,"%s",num) != EOF){
        struct books *p = (struct books *)malloc(sizeof(struct books));
        if (first == 1){
            /* 헤드 노드 생성*/
            p->book_num = *total_num;
            fscanf(fp,"%s",p->book_name);
            fscanf(fp,"%s",p->book_writer);
            fscanf(fp,"%s",p->book_publisher);
            fscanf(fp,"%s",usable);
            
            if (strcmp("available", usable) == 0){
                p->book_status = usalbe;
                
            } else {
                p->book_status = in_use;
            }
            p -> next = NULL; // 다음 노드에 null 입력
            *total_num += 1  ;
            *phead = p;
            current = p;
            first = 0; // 다음부터는 헤드 생성을 안하게 한다.
        } else {
            
            /* 일반 노드 생성*/
            p->book_num = *total_num;
            fscanf(fp,"%s",p->book_name);
            fscanf(fp,"%s",p->book_writer);
            fscanf(fp,"%s",p->book_publisher);
            fscanf(fp,"%s",usable);
            if (strcmp("available", usable) == 0){
                p->book_status = usalbe;
            } else {
                p->book_status = in_use;
            }
            p -> next = current -> next; // 이전 노드가 가리키고 있던 것을 가리킴
            current->next = p ; // 이전 노드와 연결
            *total_num += 1;
        }
        current = p;
    }
    *pnext = current;
    fseek(fp, 0, SEEK_SET);
    
    fclose(fp);
    
}

/* 새로운 스트림을 만드는 함수 */
FILE *newlist_stream(void){
    FILE *fp = fopen("/Users/choewonjun/Documents/GitHub/C_TIL/C_learning/C_learning/Library_system/list.txt", "w+");
    if (fp == NULL){
        printf("stream ERROR\n");
        return fp;
    }
    fputs("책번호 책이름 저자 출판사 대출여부\n", fp);
    fseek(fp, 0, SEEK_SET);
    return fp;
}

/* 노드에 있는 내용들을 파일에 입력하는 함수 */
int list_print(FILE *fp,struct books *head){
    struct books *from = head;
    fseek(fp, 0, SEEK_SET); // 읽는 작업에서 입력하는 작업으로 바뀌기 때문에 해준다.
    fputs("책번호 이름 저자 출판사 대출여부\n",fp);
    while (from){
        fprintf(fp, "%d %s %s %s ",from->book_num,from->book_name,from->book_writer,from->book_publisher);
        if (from -> book_status == usalbe){
            fputs("available",fp);
        } else {
            fputs("unavailable",fp);
        }
        fputs("\n", fp);
        from = from -> next ;
    }
    
    printf("출력을 완료 했습니다.\n");
    return 0;
}

/* 책 삭제 함수
    번호에 해당하는 책을 삭제하는 함수이다.
    인자 : 헤드 노드 포인터, 책 전체 개수 변수 포인터
    리턴 : 0
 */
int remove_book(struct books **head,int *total_book_num){
    struct books *from=NULL;
    struct books *before=NULL;
    int book_num;
    from = *head;
    
    printf("삭제할 책 번호를 입력하세요 : ");
    scanf("%d",&book_num);
    if (book_num == 0){
        *head = from -> next;
        
        free(from);
        *total_book_num -= 1;
        printf("-------------------------------\n");
        printf("삭제를 완료했습니다.\n");
        return 0;
    }
    while (from){
        if (from -> book_num == book_num){
            before -> next = from -> next;
            free(from);
            *total_book_num -= 1;
            printf("-------------------------------\n");
            printf("삭제를 완료했습니다.\n");
            return 0;
        }
        before = from;
        from = from -> next;
    }
    printf("-------------------------------\n");
    printf("해당 번호의 책이 존재하지 않습니다.\n");
    return 0;
}


