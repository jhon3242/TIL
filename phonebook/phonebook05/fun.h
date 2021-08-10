#define INIT_CAPACITY 100
#define BUFFER_LENGTH 100

typedef struct {
    char *name;
    char *number;
    char *email;
    char *group;
} Person;

extern Person ** directroy; // 구조체 포인터 배열을 위한 포인터의 포인터
extern int capacity;
extern int n; // 전체 사람 수

void init(void);
int read_line(FILE *fp, char str[], int n);
void add(char *name, char *number, char *email, char *group);
void release_person(Person *p);
void reallocate(void);
void start(void);
void handle_add(char *ad_name);
void find(char *ob_name);
void status(void);
