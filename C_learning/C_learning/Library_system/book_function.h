
enum {usalbe, in_use};
struct books{
    char book_name[30]; // 책 이름
    char book_writer[30]; // 책 저자
    char book_publisher[30]; // 책 출판사
    int book_status ; // 1이면 대출중 0이면 대출가능
    struct books *next;
    int book_num ;
};

struct books * add(struct books *current, int *total_book_num);
struct books * add_head( int *total_book_num);
void search (struct books *head);
int borrow (struct books *head);
int book_return (struct books *head);
int print_list(struct books *head);

