#include <stdio.h>
#include "string.h"
#include "book_function.h"



int main(){
    struct books list;
    int total_book_num=0, user_choice;
    printf("test");
    printf("-------------------------------\n");
    printf("안녕하세요 도서 관리 프로그램입니다.\n\n");
    printf("1. 책 추가하기 \n");
    printf("2. 책 검색하기 \n");
    printf("3. 책 빌리기 \n");
    printf("4. 책 반납하기 \n");
    printf("5. 프로그램 종료하기 \n");


    while (1){
        printf("-------------------------------\n");
        printf("어떤 일을 도와드릴까요?\n번호를 입력해주세요 :");

        scanf("%d",&user_choice);

        if (user_choice==1){
            /* 책 추가하는 함수*/
            add(&list, &total_book_num);
        }else if (user_choice==2){
            /* 책 검색하는 함수*/
            search(&list, &total_book_num);
        }else if (user_choice==3){
            /* 책 빌리는 함수*/
            borrow(&list);
        }else if (user_choice==4){
            /* 책 반납하는 함수*/
            book_return(&list);
        }else if (user_choice==5){
            /* 프로그램 종료 */
            break;
        }else{
            printf("번호를 잘못 입력하였습니다.\n");
        }
    }

    return 0;
}
