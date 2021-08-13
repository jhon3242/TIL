#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_LENGHTS 100

typedef struct song Song;
typedef struct snode SNode;
typedef struct artist Artist;


struct artist{
    char *name;
    Artist *next;
    SNode *head,*tail;
};

struct snode{
    SNode *next, *prev;
    Song *song;

};

struct song{
    Artist *artist;
    char *title;
    char *path;
    int index;
};
void load(FILE *fp);
void initialize(void);
void add_song(char *artist, char *title, char *path);
Artist * find_artist(char *name);
Song * creat_song_instatnce(Artist *ptr_artist, char *title, char *path);
SNode *creat_snod_instatnce(SNode *next, SNode *prev, Song *song);
void insert_node(Artist *ptr_artist, SNode *ptr_snode);
void print_song(Song *p);
void print_artist(Artist *p);
void status(void);
void search_song(char *artist, char *title);
SNode *find_snode(Artist *ptr_artist, char *title);
void insert_to_index_directory(Song *ptr_song);
void play(int index);
void save_artist(Artist *p, FILE *fp);
void save(FILE *fp);
void removes(int index);
void remove_snode(Artist *ptr_artist, SNode *ptr_snode);

#endif
