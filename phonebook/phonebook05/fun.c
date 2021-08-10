#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fun.h"

void init(void){
    directroy = (Person **)malloc(INIT_CAPACITY * sizeof(Person *));
    capacity = INIT_CAPACITY;
    n=0;
}

int read_line(FILE *fp, char str[], int n){
    int ch,i=0;
    while ((ch = fgetc(fp)) != '\n' && ch != EOF){
        if (i < n) str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

void load(char *file_name){
    char buffer[BUFFER_LENGTH];
    char *name,*number,*email,*group, *token;

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL){
        printf("open fail.\n");
        return;
    }

    while (1){
        if (read_line(fp, buffer, BUFFER_LENGTH) <= 0) break; // no argument
        name = strtok(buffer, "#"); // there a nothing which dosen't have name
        name = strdup(name);
        token = strtok(NULL, "#");
        if (strcmp(token, " ")==0){
            number = NULL;
        } else {
            number = strdup(token);
        }
        token = strtok(NULL, "#");
        if (strcmp(token, " ")==0){
            email = NULL;
        } else {
            email = strdup(token);
        }
        token = strtok(NULL, "#");
        if (strcmp(token, " ")==0){
            group = NULL;
        } else {
            group = strdup(token);
        }
        add(name,number,email,group);

    }
    fclose(fp);
    printf("load success.\n");
}

void add(char *name, char *number, char *email, char *group){
    int i = n-1;
    if (n >= capacity){
        //reallocate
    }
    while (i >= 0 && strcmp(directroy[i]->name, name)>0){
        directroy[i+1] = directroy[i];
        i--;
    }
    directroy[i+1] = (Person *)malloc(sizeof(Person));
    directroy[i+1] -> name = name;
    directroy[i+1] -> number = number;
    directroy[i+1] -> email = email;
    directroy[i+1] -> group = group;
    n++;
}

void reallocate(void){
    capacity *= 2; // 용량 2 배로 늘리기
    Person **tmp = (Person **)malloc(capacity * sizeof(Person *));
    for (int i=0;i<n;i++){
        tmp[i] = directroy[i];
    }
    free(directroy);
    directroy = tmp;
}

int search(char *name){
    int i = 0;
    while (i<n){
        if (strcmp(directroy[i]->name, name) == 0) return i;
        i++;
    }
    return -1;
}

void removes(char *name){
    int i = search(name);
    if (i < 0){
        printf("No person named '%s'.\n",name);
        return;
    }
    //free(directroy[i]); 이렇게 간단히 할 수 없는 이유는 구조체 안에 있는 배열들 또한 malloc으로 할당되었기 때문에(strdup) 이것들 또한 free 해줘야하기 때문이다.
    Person *p = directroy[i];
    while (i < n){
        directroy[i] = directroy[i+1];
        i++;
    }
    release_person(p);
    printf("'%s' was deleted successfully.\n",name);
    n--;

}
/* 구조체를 free 하는 함수 */
void release_person(Person *p){
    free(p->name);
    if (p->number != NULL) free(p->number); // NULL이면 free 하면 안되기 때문이다.
    if (p->email != NULL) free(p->email);
    if (p->group != NULL) free(p->group);
    free(p);
}
void handle_add(char *ad_name){
    char *name,*number,*email,*group;
    char empty[] = " ";
    name = (char *)malloc(BUFFER_LENGTH*sizeof(char));
    number = (char *)malloc(BUFFER_LENGTH*sizeof(char));
    email = (char *)malloc(BUFFER_LENGTH*sizeof(char));
    group = (char *)malloc(BUFFER_LENGTH*sizeof(char));
    strcpy(name, ad_name);
    printf("Phone : ");
    if (read_line(stdin, number, BUFFER_LENGTH) == 0){
        free(number);
        number = empty;
    }
    printf("Email : ");
    if (read_line(stdin, email, BUFFER_LENGTH) == 0){
        free(email);
        email = empty;
    }
    printf("Group : ");
    if (read_line(stdin, group, BUFFER_LENGTH) == 0){
        free(group);
        group = empty;
    }

    add(name, number, email, group);
}
void find(char *ob_name){
    int i=0;
    i = search(ob_name);
    if (i < 0){
        printf("No person named '%s'.\n",ob_name);
    } else{
        printf("%s\n",ob_name);
        printf("    phone : %s\n",directroy[i]->number);
        printf("    email : %s\n",directroy[i]->email);
        printf("    group : %s\n",directroy[i]->group);
    }

}
void status(void){
    int i =0;
    while (i<n){
        printf("%s\n",directroy[i]->name);
        printf("    number : %s\n",directroy[i]->number);
        printf("    email  : %s\n",directroy[i]->email);
        printf("    group  : %s\n",directroy[i]->group);
        i++;
    }
    printf("Total %d persons.\n",n);
}
void save(char *file_name){
    int i=0;
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL){
        printf("open fail.\n");
        return;
    }
    while (i<n){
        fprintf(fp, "%s#",directroy[i]->name);
        fprintf(fp, "%s#",directroy[i]->number);
        fprintf(fp, "%s#",directroy[i]->email);
        fprintf(fp, "%s#\n",directroy[i]->group);
        i++;
    }
    fclose(fp);
    printf("save success.\n");
}
void start(void){

    char command_line[BUFFER_LENGTH];
    char *command, *argument;
    while (1){
        printf("$ ");
        directroy;
        if (read_line(stdin, command_line, BUFFER_LENGTH)<=0) continue;;
        command = strtok(command_line, " ");
        if (strcmp(command, "read")==0){
            argument = strtok(NULL, " ");
            if (argument == NULL){
                printf("Invalid argument.\n");
                continue;
            }
            load(argument);
        }else if (strcmp(command, "add")==0){
            argument = strtok(NULL, " ");
            if (argument == NULL){
                printf("Name required.\n");
                continue;
            }
            handle_add(argument);
        }else if (strcmp(command, "find")==0){
            argument = strtok(NULL, " ");
            if (argument == NULL){
                printf("Name required.\n");
                continue;
            }
            find(argument);
        }else if (strcmp(command, "status")==0){
            status();
        }else if (strcmp(command, "save")==0){
            argument = strtok(NULL, " ");
            if (strcmp(argument, "as") != 0){
                printf("'as' required.\n");
                continue;
            }
            argument = strtok(NULL, " ");
            if (argument == NULL){
                printf("Name required.\n");
                continue;
            }
            save(argument);
        }else if (strcmp(command, "exit")==0){
            break;
        }
    }
}


