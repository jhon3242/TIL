
#include <stdio.h>
#include <string.h>
#include "string_tools.h"
#include "library.h"




void process_command(void);
void handle_load(void);
void handle_add(void);
void handle_search(void);
void handle_play(void);
void handle_save(void);
void handle_remove(void);


//int n = 0;

int main(){

    initialize();
    handle_load();
    process_command();

    return 0;
}

void handle_search(void){
    char artist[BUFFER_LENGHTS],title[BUFFER_LENGHTS];

    printf("    Artist : ");
    if (read_line(stdin, artist, BUFFER_LENGHTS) <= 0){
        printf("Artist name required.\n");
        return;
    }
    printf("    Title : ");
    read_line(stdin, title, BUFFER_LENGHTS);

    search_song(artist, title);
}


void handle_load(void){
    char buffer[BUFFER_LENGHTS];

    printf("Date file name : ");
    if (read_line(stdin, buffer, BUFFER_LENGHTS) <=0){
        return;
    }
    FILE *fp = fopen(buffer, "r");
    if (fp == NULL){
        printf("No such file exist.\n");
        return;
    }
    load(fp);
    fclose(fp);

}


void process_command(void){
    char command_line[BUFFER_LENGHTS];
    char *command;
    while (1){ // infinite loop
        printf("$ "); // prompt
        if (read_line(stdin, command_line, BUFFER_LENGHTS) <=0){
            continue ;
        }
        command =strtok(command_line, " ");
        if (strcmp(command,"add")==0){
            handle_add();

        }else if (strcmp(command,"search")==0){
            handle_search();
        }  else if (strcmp(command,"remove")==0){
            handle_remove();
        }  else if (strcmp(command,"save")==0){
            handle_save();
        }else if (strcmp(command,"play")==0){
            handle_play();
        }else if (strcmp(command,"status")==0){
            status();
        }else if (strcmp(command,"exit")==0){
            break;
        }

    }
}
void handle_play(void){
    char *id_str = (char *)strtok(NULL," ");
    if (id_str == NULL){
        printf("Index required.\n");
        return;
    }
    int index = atoi(id_str);
    play(index);
}
void handle_add(void){
    char buffer[BUFFER_LENGHTS];
    char *artist=NULL, *title=NULL, *path=NULL;
    printf("    Artist : ");
    if (read_line(stdin, buffer, BUFFER_LENGHTS) >0){
        artist = strdup(buffer);
    }
    printf("    Title : ");
    if (read_line(stdin, buffer, BUFFER_LENGHTS) >0){
        title = strdup(buffer);
    }
    printf("    Path : ");
    if (read_line(stdin, buffer, BUFFER_LENGHTS) >0){
        path = strdup(buffer);
    }


    /* add to the music library*/
    add_song(artist, title, path);
}

void handle_save(void){
    char *tmp;
    tmp = strtok(NULL, " ");

    if (strcmp(tmp, "as") != 0){
        printf("as is required.\n");
        return;
    }
    tmp = strtok(NULL, " ");

    FILE *fp = fopen(tmp, "w");
    if (fp == NULL){
        printf("file open error.\n");
        return;
    }
    save(fp);
    printf("save successfully.\n");
    fclose(fp);
}

void handle_remove(void){
    char *id_str = (char *)strtok(NULL," ");
    if (id_str == NULL){
        printf("Index required.\n");
        return;
    }
    int index = atoi(id_str);
    removes(index);
}
