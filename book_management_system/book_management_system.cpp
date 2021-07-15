#include <stdio.h>
int add(struct books *p, int *total_book_num);
int compare(char *str1, char *str2);
int search (struct books *p, int *total_book_num);
int borrow (struct books *p);
int book_return (struct books *p);
enum {usalbe, in_use};
struct books{
    char book_name[100][30]; // 책 이름
    char book_writer[100][30]; // 책 저자
    char book_publisher[100][30]; // 책 출판사
    int book_status[100]={0};
};

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

/* 책 추가하는 함수*/
int add(struct books *p, int *total_book_num){

    printf("책의 이름 :");
    scanf("%s",p -> book_name[*total_book_num]);

    printf("책의 저자 :");
    scanf("%s",p -> book_writer[*total_book_num]);

    printf("책의 출판사 :");
    scanf("%s",p -> book_publisher[*total_book_num]);

    (*total_book_num)++; // 전체 책의 개수에 1 더하기
    return 0;
}
/* 문자열 비교 함수 */
int compare(char *str1, char *str2) {
  while (*str1) {
    if (*str1 != *str2) {
      return 0;
    }

    str1++;
    str2++;
  }

  if (*str2 == '\0') return 1;

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
                printf("책 번호 : %d\n",book_num);
                printf("책 제목 : %s\n",p->book_name[book_num]);
                printf("책 저자 : %s\n",p->book_writer[book_num]);
                printf("책 출판사 : %s\n",p->book_publisher[book_num]);
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
                printf("책 번호 : %d\n",book_num);
                printf("책 제목 : %s\n",p->book_name[book_num]);
                printf("책 저자 : %s\n",p->book_writer[book_num]);
                printf("책 출판사 : %s\n",p->book_publisher[book_num]);
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
                printf("책 번호 : %d\n",book_num);
                printf("책 제목 : %s\n",p->book_name[book_num]);
                printf("책 저자 : %s\n",p->book_writer[book_num]);
                printf("책 출판사 : %s\n",p->book_publisher[book_num]);
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
    return 0;
}
