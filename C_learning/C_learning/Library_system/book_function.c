
#include "book_function.h"
#include "string.h"
#include <stdio.h>

/* 책 추가하는 함수*/
int add(struct books *p, int *total_book_num){

    printf("책의 이름 :");
    scanf("%s",p -> book_name[*total_book_num]);

    printf("책의 저자 :");
    scanf("%s",p -> book_writer[*total_book_num]);

    printf("책의 출판사 :");
    scanf("%s",p -> book_publisher[*total_book_num]);
    
    p -> book_status[*total_book_num] = 0;
    (*total_book_num)++; // 전체 책의 개수에 1 더하기
    return 0;
}



/* 책 검색하는 함수*/
int search (struct books *p, int *total_book_num){
    int user_choice, book_num=0,check=1;
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
        while (book_num < *total_book_num){
            if (compare(contents, p->book_name[book_num])){
                printf("-------------------------------\n");
                printf("책 번호 : %d\n",book_num);
                printf("책 제목 : %s\n",p->book_name[book_num]);
                printf("책 저자 : %s\n",p->book_writer[book_num]);
                printf("책 출판사 : %s\n",p->book_publisher[book_num]);
                printf("-------------------------------\n");
                printf("더 찾으려면 1번을, 끝내려면 0을 입력하세요. : ");
                scanf("%d",&check);
                /* 계속 찾으려면 check 는 1 아니면 0 */
                if (check == 0) break;
            }
            book_num++;
        }
        if (check == 1) printf("검색 결과 없습니다.\n");

    }else if (user_choice == 2){
        while (book_num < *total_book_num){
            if (compare(contents, p->book_writer[book_num])){
                printf("-------------------------------\n");
                printf("책 번호 : %d\n",book_num);
                printf("책 제목 : %s\n",p->book_name[book_num]);
                printf("책 저자 : %s\n",p->book_writer[book_num]);
                printf("책 출판사 : %s\n",p->book_publisher[book_num]);
                printf("-------------------------------\n");
                printf("더 찾으려면 1번을, 끝내려면 0을 입력하세요. : ");
                scanf("%d",&check);
                /* 계속 찾으려면 check 는 1 아니면 0 */
                if (check == 0) break;
            }
            book_num++;
        }
        if (check == 1) printf("검색 결과 없습니다.\n");


    }else if (user_choice == 3){
        while (book_num < *total_book_num){
            if (compare(contents, p->book_publisher[book_num])){
                printf("-------------------------------\n");
                printf("책 번호 : %d\n",book_num);
                printf("책 제목 : %s\n",p->book_name[book_num]);
                printf("책 저자 : %s\n",p->book_writer[book_num]);
                printf("책 출판사 : %s\n",p->book_publisher[book_num]);
                printf("-------------------------------\n");
                printf("더 찾으려면 1번을, 끝내려면 0을 입력하세요. : ");
                scanf("%d",&check);
                /* 계속 찾으려면 check 는 1 아니면 0 */
                if (check == 0) break;
            }
            book_num++;
        }
        if (check == 1) printf("검색 결과 없습니다.\n");
    }
    

    return 0;
}
/* 책 빌리는 함수 */
int borrow (struct books *p){
    int book_num;
    printf("빌릴 책 번호를 입력해주세요. : ");
    scanf("%d",&book_num);

    if (p -> book_status[book_num] == in_use){
        printf("이 책은 대출중입니다.\n");
    } else{
        p -> book_status[book_num] = in_use;
        printf("책을 대출 하였습니다.\n");

    }
    printf("-------------------------------\n");
    return 0;
}

/* 책 반납 함수 */
int book_return (struct books *p){
    int book_num;
    printf("반납할 책 번호를 입력해주세요. : ");
    scanf("%d",&book_num);

    if (p ->book_status[book_num] == usalbe){
        printf("이 책은 이미 반납했습니다.\n");
    } else{
        p ->book_status[book_num] = usalbe;
        printf("책을 반납 하였습니다.\n");

    }
    printf("-------------------------------\n");
    return 0;
}
