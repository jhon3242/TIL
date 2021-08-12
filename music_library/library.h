#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void initialize(void);
void add_song(char *artist, char *title, char *path);
Artist * find_artist(char *name);
Song * creat_song_instatnce(Artist *ptr_artist, char *title, char *path);
SNode *creat_snod_instatnce(SNode *next, SNode *prev, Song *song);
void insert_node(Artist *ptr_artist, SNode *ptr_snode);
void print_song(Song *p);
void print_artist(Artist *p);
void status(void);
#endif
