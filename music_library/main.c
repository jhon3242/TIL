
#include <stdio.h>
#include <string.h>
#include "string_tools.h"
#include "library.h"

#define BUFFER_LENGHTS 100

void process_command(void);
void handle_add(void);
//int n = 0;

int main(){

    initialize();
    process_command();

    return 0;
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

        }/* else if (strcmp(command,"search")==0){
            //handle_search();
        } else if (strcmp(command,"remove")==0){
            //handle_remove();
        } else if (strcmp(command,"play")==0){
            //handle_play();
        } else if (strcmp(command,"save")==0){
            //handle_save();
        }*/else if (strcmp(command,"status")==0){
            status();
        }else if (strcmp(command,"exit")==0){
            break;
        }

    }
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
