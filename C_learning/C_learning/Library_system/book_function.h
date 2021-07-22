
enum {usalbe, in_use};
struct books{
    char book_name[100][30]; // 책 이름
    char book_writer[100][30]; // 책 저자
    char book_publisher[100][30]; // 책 출판사
    int book_status[100] ;
};

int add(struct books *p, int *total_book_num);
int search (struct books *p, int *total_book_num);
int borrow (struct books *p);
int book_return (struct books *p);
