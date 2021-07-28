#include <stdlib.h>
#include "book_function.h"
#include "string.h"
#include <stdio.h>

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
            if (from -> book_status == in_use){
                printf("이 책은 이미 반납했습니다\n");
                return 0;
            } else{
                from -> book_status = in_use;
                printf("책을 반납 하였습니다.\n");
                return 0;

            }
        }
        from = from -> next;
    }
    printf("책 번호를 찾을 수 없습니다.\n");
    return 0;
}

/* 책 리스트 출력 함수 */
int print_list(struct books *head){
    struct books *from = head;
    FILE *fp = fopen("/Users/choewonjun/Documents/GitHub/C_TIL/C_learning/C_learning/Library_system/list.txt", "w");
    if (fp == NULL) {
        printf("fp ERROR\n");
        return 0;
    }
    fprintf(fp, "책 번호 / 책 이름 / 저자 / 출판사 / 대출가능\n");
    while (from){
        fprintf(fp, "%d / %s / %s / %s /  ",from->book_num,from->book_name,from->book_writer,from->book_publisher);
        if (from -> book_status == usalbe){
            fprintf(fp, "available\n");
        } else {
            fprintf(fp, "unavailable\n");
        }
        from = from -> next ;
    }
    printf("출력을 완료 했습니다.\n");
    fclose(fp);
    
    
    return 0;
}
