#include <stdio.h>
#include <string.h>
#define CAPACITY 100
#define BUFFER_LENGTH 100

typedef struct person{
    char *name;
    char *number;
    char *email;
    char *group;
}Person;
Person directory[CAPACITY];

int read_line(FILE *fp,char str[], int n);
void load(char *file_name);
int compose_name(char str[] ,int limit);
void handle_add(char *name);
void find(char *argument);
int search(char *name);
void save(char *file_name);
void removes(char *argument);
void status(void);
void print_person(Person p);


int n = 0; // 등록된 사람의 수


int main(){
    char command_line[BUFFER_LENGTH];
    char *command, *argument;
    char name_str[BUFFER_LENGTH];
    while (1){
        printf("$ ");
        if (read_line(stdin, command_line, BUFFER_LENGTH)<=0){
            continue; // 입력을 안하면 다시실행
        }
        command = strtok(command_line, " ");
        if (strcmp(command, "read")==0){
            argument = strtok(NULL, " ");
                if (argument == NULL){
                    printf("File name required.\n");
                    continue;
                }
                load(argument);

        } else if (strcmp(command, "add")==0){
            if (compose_name(name_str, BUFFER_LENGTH) <= 0){
                printf("Name required.\n");
                continue;
            }
            handle_add(name_str); // 나머지 정보도 입력 받음


        }else if (strcmp(command, "find")==0){
            if (compose_name(name_str, BUFFER_LENGTH) <= 0){
                printf("Name required.\n");
                continue;
            }
            find(name_str);

        }else if (strcmp(command, "status")==0){
            status();
        }else if (strcmp(command, "delete")==0){
            if (compose_name(name_str, BUFFER_LENGTH) <= 0){
                printf("Name required.\n");
                continue;
            }
            removes(name_str);
        }else if (strcmp(command, "save")==0){

            argument = strtok(NULL, " ");
            if (strcmp(argument, "as") != 0){
                printf("Invalied arguments.\n");
                continue;
            }
            argument = strtok(NULL, " ");
            if (argument == NULL){
                printf("Invalied arguments.\n");
                continue;
            }
            save(argument);
            printf("save successfully.\n");
        } else if (strcmp(command, "exit") == 0){
                break;
        }
    }


    return 0;
}

/* 스트림을 읽고 두 번째 인자에 읽은 문자열을 저장하고 저장한 크기를 리턴한다*/
int read_line(FILE *fp,char str[], int n){
    int ch,i=0;
    while ((ch=getc(fp)) != '\n' && ch != EOF){
        if (i<n){
            str[i++] = ch ;
        }
    }
    str[i] = '\0';
    return i;
}
void add(char *name, char *number, char *email, char *group){
    int i = n-1;
    while (i >=0 && strcmp(directory[i].name, name) >= 0  ){
        directory[i+1] = directory[i];
        i--;
    }
    directory[i+1].name = name;
    directory[i+1].number = number;
    directory[i+1].email = email;
    directory[i+1].group = group;

    n++;
}

/* 파일에 저장된 데이터를 읽어와 구조체에 저장한다 */
void load(char *file_name){
    char buffer[BUFFER_LENGTH];
    char *name, *number, *email, *group;

    FILE *fp = fopen(file_name, "r");
    if(fp == NULL){
        printf("open ERROR\n");
        return;
    }
    while (1){
        if (read_line(fp, buffer, BUFFER_LENGTH) <= 0){
            break;
        }
        name = strtok(buffer, "#");
        number = strtok(NULL, "#");
        email = strtok(NULL, "#");
        group = strtok(NULL, "#");

        add(name, number, email, group);
    }
    fclose(fp);
}
/* 커멘드에서 이름만 빼는 함수 */
int compose_name(char str[] ,int limit){
    char *ptr;
    int length = 0;
    ptr = strtok(NULL, " ");
    if (ptr == NULL){
        printf("Invalied argument.\n");
        return 0;
    }
    strcpy(str, ptr);
    length += strlen(str);

    while ((ptr = strtok(NULL, " ")) != NULL){
        if (length + strlen(ptr) + 1 < limit ){
            str[length ++ ] =" "; // 이름 사이에 빈칸을 넣어줘야하기 때문
            str[length] = '\0'; // strcat 을 위해선 두 문자열이 널 문자(캐릭터)로 끝나있어야 하기 떄문
            strcat(str, ptr);
            length += strlen(ptr);
        }
    }


    return length;
}
/* 'add 이름' 을 했을 때 나머지 정보도 입력 받아서 추가해주는 함수*/
void handle_add(char *name){
    char number[BUFFER_LENGTH], email[BUFFER_LENGTH], group[BUFFER_LENGTH];
    char empty[] = " ";
    printf("Phone : ");
    read_line(stdin, number, BUFFER_LENGTH);

    printf("Email : ");
    read_line(stdin, email, BUFFER_LENGTH);

    printf("Group : ");
    read_line(stdin, group, BUFFER_LENGTH);


    add(name,
        (char *)(strlen(number)>0 ? number : empty),
        (char *)(strlen(email)>0 ? email : empty),
        (char *)(strlen(group)>0 ? group : empty)
        );

}
void find(char *name){

    int index = search(name);
    if (index == -1){
        printf("No person named '%s' exists.\n",name);
    } else {
        print_person(directory[index]);
    }
}
int search(char *name){
    int i=0;
    while (i<n){
        if(strcmp(name, directory[i].name)==0){
            return i;
        }
        i++;
    }
    return -1;
}

void save(char *file_name){
    int i=0;

    FILE *fp = fopen(file_name,"w");
    if(fp == NULL){
        printf("open ERROR\n");
        return;
    }
    while(i<n){
        fprintf(fp, "%s#",directory[i].name);
        fprintf(fp, "%s#",directory[i].number);
        fprintf(fp, "%s#",directory[i].email);
        fprintf(fp, "%s#\n",directory[i].group);
        i++;
    }
    fclose(fp);
}

void print_person(Person p){
    printf("%s:\n",p.name);
    printf("    Phone: %s\n",p.number);
    printf("    Email: %s\n",p.email);
    printf("    Group: %s\n",p.group);
}

void removes(char *name){

    int index = search(name);
    if (index == -1){
        printf("No person named '%s' exists.\n",name);
        return;
    }
    int j = index;
    while (j<n-1){
        directory[j] = directory[j+1];
        j++;
    }
    n--;
    printf("'%s' was deleted successfully.\n",name);
}

void status(void){
    int i=0;
    while (i<n){
        print_person(directory[i]);
        i++;
    }
    printf("Total %d persons.\n",n);
}
