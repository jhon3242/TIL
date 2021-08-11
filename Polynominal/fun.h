#define BUFFER_LENGHT 100
#define BUFFER_SHORT 20
#define MAX_POLYS 3
/* 항 연결 리스트 */
typedef struct term{
    int coef; // 계수
    int expo; // 지수
    struct term *next; // 다음 노드
}Term;


/* 다항식 연결 리스트 */
typedef struct polynominal{
    char name; // 다항식 이름
    Term *first; // 다항식의 첫 계수
    int size; // 다항식의 항의 개수
}Polynominal;

extern Polynominal *polys[MAX_POLYS]; // 다항식들에 대한 포인터 배열
extern int n; // 전체 다항식의 개수

Term *creat_term_instance(void);
Polynominal * creat_polynominal_instance(char name);
void add_term(int c, int e, Polynominal *poly);
int eval_term(Term *t, int x);
int eval(Polynominal *poly, int x);
void print_poly(Polynominal *p);
int read_line(FILE *fp,char cmd[], int size);
void handle_print(char name);
void erase_blanks(char *expression);
void handle_definition(char *exprssion);
void process_command(void);
int prase_and_add_term(char *body,int start, int end, Polynominal *poly);
Polynominal *creat_by_parse_polynominal(char name, char *body);
void insert_polynominal(Polynominal *p);
Polynominal *creat_by_add_two_polynominal(char name, char f, char g);
void handle_calc(char name, char *x_value);
