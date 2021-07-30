#include <stdio.h>
enum {usalbe, in_use};
struct books{
    int book_num ; // 책 번호
    char book_name[30]; // 책 이름
    char book_writer[30]; // 책 저자
    char book_publisher[30]; // 책 출판사
    int book_status ; // 책 대출가능여부
    struct books *next; // 다음 노드
    
};


struct books * add(struct books *current, int *total_book_num);
struct books * add_head( int *total_book_num);
void search (struct books *head);
int borrow (struct books *head);
int book_return (struct books *head);
void readlist_stream(struct books **phead,struct books ** pnext, int *total_num);
FILE *newlist_stream(void);
int list_print(FILE *fp,struct books *head);
int remove_book(struct books **head,int *total_book_num);
