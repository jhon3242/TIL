#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 50
#define INIT_CAPACITY 5

char **names;
char **numbers;
char delim[] = " ";
int capacity = INIT_CAPACITY;
int n = 0;


void reallocate(void);
void init_directory(void);
void process_command(void);
void status(void);
void load(char *file_name);
void add(char *argument1, char *argument2);
void find(char *argument1);
void removes(char *argument1);
void save(char *arguement1);
int search(char *buf);
void status(void);

int main(){



    init_directory();
    process_command();
    return 0;
}
int search(char *buf){
    int i=0;
    while (i<n){
        if(strcmp(names[i], buf)==0){
            return i;
        }
        i++;
    }
    return -1;
}
void status(void){
    int i=0;
    while (i<n){
        printf("%s %s\n",names[i],numbers[i]);
        i++;
    }
    printf("Total %d persons.\n",n);
}
void load(char *file_name){

    //char file_name[BUFFER_SIZE];
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];

    //scanf("%s", file_name);
    FILE *fp = fopen(file_name, "r");
    if(fp == NULL){
        printf("open ERROR\n");
        return;
    }
    while(fscanf(fp, "%s",buf1) != EOF){
        fscanf(fp, "%s",buf2);
        add(buf1, buf2);
    }
    fclose(fp);
}
void add(char *name, char *number){
    if (n>=capacity){
        /* 배열 크기 재할당*/
        reallocate();
    }

    int i = n-1;
    while (i>=0 && strcmp(names[i], name) > 0){
        names[i+1] = names[i];
        numbers[i+1] = numbers[i];
        i--;
    }
    names[i+1] = strdup(name);
    numbers[i+1] = strdup(number);
    n++;

    printf("%s was added successfully \n",name);
}
void find(char *argument1){

    int index = search(argument1);
    if (index == -1){
        printf("No person named '%s' exists.\n",argument1);
    } else {
        printf("%s\n",numbers[index]);
    }
}

void removes(char *argument1){


    int index = search(argument1);
    if (index == -1){
        printf("No person named '%s' exists.\n",argument1);
        return;
    }
    int j = index;
    while (j<n-1){
        names[j] = names[j+1];
        numbers[j] = numbers[j+1];
        j++;
    }
    n--;
    printf("'%s' was deleted successfully.\n",names[index]);
}




void save(char *file_name){
    int i=0;

    FILE *fp = fopen(file_name,"w");
    if(fp == NULL){
        printf("open ERROR\n");
        return;
    }
    while(i<n){
        fprintf(fp,"%s %s\n",names[i],numbers[i]);
        i++;
    }
    fclose(fp);
}

// new
int read_line(char str[], int limit){
    int ch,i=0;

    while ((ch = getchar()) != '\n'){
        if (i<limit-1){
            str[i++] = ch;
        }
    }
    str[i++] = '\0';
    return i;

}
void init_directory(void){
    names =(char **)malloc(INIT_CAPACITY* sizeof(char * ));
    numbers =(char **)malloc(INIT_CAPACITY* sizeof(char * ));
}

void process_command(void){
    char command_line[BUFFER_SIZE];
    char *command, *argument1, *argument2;
    while(1){
        printf("$ ");
        if (read_line(command_line, BUFFER_SIZE) <= 0){
            continue; // 다시 반복문의 처음부분으로 돌아가라
        }
        command = strtok(command_line, delim);
        if (command == NULL) continue;

        if (strcmp(command, "read")==0){
            argument1 = strtok(NULL, delim);
            if (argument1 == NULL){
                printf("File name required.\n");
                continue;
            }
            load(argument1);

        } else if (strcmp(command, "add")==0){
            argument1 = strtok(NULL, delim);
            argument2 = strtok(NULL, delim);
            if (argument1 == NULL ||argument2 == NULL ){
                printf("Invalid arguments.\n");
                continue;
            }
            add(argument1, argument2);


        }else if (strcmp(command, "find")==0){
            argument1 = strtok(NULL, delim);
            if (argument1 == NULL){
                printf("Invalid arguments.\n");
                continue;
            }
            find(argument1);

        }else if (strcmp(command, "status")==0){
            status();
        }else if (strcmp(command, "delete")==0){
            argument1 = strtok(NULL, delim);
            if (argument1 == NULL){
                printf("Invalid arguments.\n");
                continue;
            }
            removes(argument1);
        }else if (strcmp(command, "save")==0){
            argument1 = strtok(NULL, delim);
            argument2 = strtok(NULL, delim);
            if (argument1 == NULL || strcmp(argument1, "as") != 0 || argument2 == NULL){
                printf("Invalid arguments.\n");
                continue;
            }
            save(argument2);
            printf("save successfully.\n");
        } else if (strcmp(command, "exit") == 0){
            break;
        }

    }

}

void reallocate(void){
    capacity *= 2;
    char **tmp1 = (char **)malloc(capacity*sizeof(char *));
    char **tmp2 = (char **)malloc(capacity*sizeof(char *));

    for (int i=0;i<n;i++){
        tmp1[i] = names[i];
        tmp2[i] = numbers[i];
    }
    free(names); // names 이나 numbers 가 완전히 사라지는게 아니라 가리키고 있는 메모리 공간이 사라지는 것임
    free(numbers);

    names = tmp1;
    numbers = tmp2;
}
