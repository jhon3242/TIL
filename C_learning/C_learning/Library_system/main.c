#include <stdio.h>
#include "string.h"
#include "book_function.h"



int main(){
    
    int total_book_num=0, user_choice;
    struct books * head=NULL;
    struct books * next=NULL;

    printf("-------------------------------\n");
    printf("안녕하세요 도서 관리 프로그램입니다.\n\n");
    printf("1. 책 추가하기 \n");
    printf("2. 책 검색하기 \n");
    printf("3. 책 빌리기 \n");
    printf("4. 책 반납하기 \n");
    printf("5. 책 리스트 출력하기 \n");
    printf("6. 프로그램 종료하기 \n");
    


    while (1){
        printf("-------------------------------\n");
        printf("현재 등록된 책의 개수 : %d 개\n",total_book_num);
        printf("어떤 일을 도와드릴까요?\n번호를 입력해주세요 :");

        scanf("%d",&user_choice);

        if (user_choice==1){
            /* 책 추가하는 함수*/
            if (total_book_num == 0){
                /* 헤더 노드 생성 */
                next = add_head(&total_book_num);
                head = next;
            } else{
                /* 일반 노드 생성 */
                next = add(next,&total_book_num);
            }
            
        }else if (user_choice==2){
            /* 책 검색하는 함수*/
            search(head);
        }else if (user_choice==3){
            /* 책 빌리는 함수*/
            borrow(head);
        }else if (user_choice==4){
            /* 책 반납하는 함수*/
            book_return(head);
        }else if (user_choice==5){
            /* 책 리스트 출력 함수 */
            print_list(head);
        }else if (user_choice==6){
            /* 프로그램 종료 */
            break;
        }else{
            printf("번호를 잘못 입력하였습니다.\n");
        }
        
    }

    return 0;
}
