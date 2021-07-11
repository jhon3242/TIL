#include <stdio.h>
int add(const char *name,const char *writer,const char *publish,const char *status, char (*arr)[4][20], int book_num);
int same_title(char (*arr)[4][20], int book_num, const char *name);
int same_writer(char (*arr)[4][20],int book_num, const char *writer);
int same_publisher(char (*arr)[4][20],int book_num, const char *publisher);
int search_title(char (*arr)[4][20], const char *name);
int search_writer(char (*arr)[4][20], const char *writer);
int search_publisher(char (*arr)[4][20], const char *publisher);
int rent(char (*arr)[4][20],int book_num);
int book_return(char (*arr)[4][20],int book_num);

int main(){
    char bookshelf[100][4][20]={NULL};
    add("This is book", "CHOI", "APPLE","대출가능", bookshelf, 0);
    add("That is book", "KIM", "AMAZON","대출가능", bookshelf, 1);
    add("What is book", "LEE", "AMAZON","대출가능", bookshelf, 2);
    add("How's book", "KIM", "AMAZON","대출가능", bookshelf, 3);


    return 0;
}



/* 책이름, 저자, 출판사 3개의 문자열을 작성하면 리스트에 {책이름, 저자, 출판사, 대출상태} 가 추가되는 함수
    인자 : 책이름, 저자, 출판사,대출상태, 리스트, 몇 번째 책
    리턴형 : 문제없이 완료되면 0 리턴
 */

int add(const char *name,const char *writer,const char *publish,const char *status, char (*arr)[4][20], int book_num){
    int i = 0;
    while (name[i]){
        arr[book_num][0][i] = name[i];
        i++;
    }

    i = 0;
    while (writer[i]){
        arr[book_num][1][i] = writer[i];
        i++;
    }

    i = 0;
    while (publish[i]){
        arr[book_num][2][i] = publish[i];
        i++;
    }

    i = 0;
    while (status[i]){
        arr[book_num][3][i] = status[i];
        i++;
    }

    return 0;
}

/* 책 제목이 같은지 확인하는 함수
    책 번호와, 책 제목을 입력하고 책 번호에 해당하는 제목과 일치하는지 확인하는 함수이다
    인자 : 리스트,몇 번째 책, 책 제목
    리턴 : 일치하면 1을 리턴하고 일치하지 않으면 0을 리턴한다.
 */
int same_title(char (*arr)[4][20],int book_num, const char *name){
    int i=0;

    while (name[i]){
        if (arr[book_num][0][i] != name[i]){
            return 0;
        }
        i++;
    }
    if (arr[book_num][0][i] == '\0'){
        return 1;
    } else return 0;

}
/* 책 저자가 같은지 찾는 함수
    책 번호와 책 저자를 입력하면 번호에 맞는 책의 저자가 입력한 저자와 동일하면 1을 리턴하는 함수이다
    인자 : 리스트,책 번호, 책 저자
    리턴 : 있으면 1을 없으면 0을 리턴
 */
int same_writer(char (*arr)[4][20],int book_num, const char *writer){
    int i = 0;
    while (writer[i]){
        if (arr[book_num][1][i] != writer[i] ){
            return 0;
        }
        i++;
    }
    if (arr[book_num][1][i] == '\0'){
        return 1;
    } else return 0;
}
/* 책 출판사가 같은지 찾는 함수
    책 번호와 책 출판사를 입력하면 번호에 맞는 책의 출판사가 입력한 출판사와 동일하면 1을 리턴하는 함수이다
    인자 : 리스트,책 번호, 책 출판사
    리턴 : 있으면 1을 없으면 0을 리턴
 */
int same_publisher(char (*arr)[4][20],int book_num, const char *publisher){
    int i = 0;
    while (publisher[i]){
        if (arr[book_num][2][i] != publisher[i] ){
            return 0;
        }
        i++;
    }
    if (arr[book_num][2][i] == '\0'){
        return 1;
    } else return 0;
}



/* 제목으로 책 찾는 함수
    책 제목이 같은 책이 있는지 리스트에 있는 책들을 전부 확인하는 함수로 same_title 함수를 반복실행하는 함수이다.
    인자 : 리스트, 책 제목
    리턴 : 제목이 같은 책이 있으면 책 정보를 출력하고 없으면 없다고 출력하고 0을 리턴한다.
 */

int search_title(char (*arr)[4][20], const char *name){
    int i = 0;
    while (arr[i][0][0]){
        if (same_title(arr, i, name)){
            printf("책 제목 : %s \n",arr[i][0]);
            printf("책 저자 : %s \n",arr[i][1]);
            printf("책 출판사 : %s \n",arr[i][2]);
            printf("대출상황 : %s \n\n",arr[i][3]);
            return 1;
        }
        i++;
    }
    printf("-------------------------------- \n");
    return 0;

}

/* 저자로 책 찾는 함수
    책 저자와 같은 책이 있는지 리스트에 있는 책들을 전부 확인하는 함수로 same_writer 함수를 반복실행하는 함수이다.
    인자 : 리스트, 책 저자
    리턴 : 저자가 같은 책이 있으면 책 정보를 출력하고 없으면 없다고 출력하고 0을 리턴한다.
 */

int search_writer(char (*arr)[4][20], const char *writer){
    int i = 0;
    while (arr[i][0][0]){
        if (same_writer(arr, i, writer)){
            printf("책 제목 : %s \n",arr[i][0]);
            printf("책 저자 : %s \n",arr[i][1]);
            printf("책 출판사 : %s \n",arr[i][2]);
            printf("대출상황 : %s \n\n",arr[i][3]);
        }
        i++;
    }
    printf("-------------------------------- \n");
    return 0;

}

/* 출판사로 책 찾는 함수
    책 출판사와 같은 책이 있는지 리스트에 있는 책들을 전부 확인하는 함수로 same_publisher 함수를 반복실행하는 함수이다.
    인자 : 리스트, 책 출판사
    리턴 : 출판사가 같은 책이 있으면 책 정보를 출력하고 없으면 없다고 출력하고 0을 리턴한다.
 */

int search_publisher(char (*arr)[4][20], const char *publisher){
    int i = 0;
    while (arr[i][0][0]){
        if (same_publisher(arr, i, publisher)){
            printf("책 제목 : %s \n",arr[i][0]);
            printf("책 저자 : %s \n",arr[i][1]);
            printf("책 출판사 : %s \n",arr[i][2]);
            printf("대출상황 : %s \n\n",arr[i][3]);
        }
        i++;
    }
    printf("-------------------------------- \n");
    return 0;


}
/* 대출 기능을 하는 함수
    책의 상태를 "대출중" 이라고 바꾸는 함수
    인자 : 리스트,책 번호
    리턴 : 무사히 진행되면 1을 리턴
 */
int rent(char (*arr)[4][20],int book_num){
    int i=0;
    char sur[13] = "대출중";
    while (sur[i]){
        arr[book_num][3][i] = sur[i];
        i++;
    }
    arr[book_num][3][i] = '\0';
    return 1;
}


/* 책 반납 함수
    책을 반납하여 대출상황을 다시 "대출가능"으로 바꾸는 함수이다.
    인자 : 리스트, 책 번호
    리턴 : 무사히 실행되면 1을 리턴
 */
int book_return(char (*arr)[4][20],int book_num){
    int i=0;
    char sur[13] = "대출가능";
    while (sur[i]){
        arr[book_num][3][i] = sur[i];
        i++;
    }
    arr[book_num][3][i] = '\0';
    return 1;
}

