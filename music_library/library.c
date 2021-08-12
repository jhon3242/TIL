
#include "library.h"

#define NUM_CHAR 256
Artist *artist_directory[NUM_CHAR]; // 가수 배열
int num_index = 0;

void initialize(void){
    for (int i = 0; i<NUM_CHAR;i++){
        artist_directory[i] = NULL;
    }
}

/* 새로운 가수 노드를 만드는 함수*/
Artist *creat_artist_instance(char *name){
    Artist *ptr_artist = (Artist *)malloc(sizeof(Artist));
    ptr_artist->name = name;
    ptr_artist->head = NULL;
    ptr_artist->next = NULL;
    ptr_artist->tail = NULL;

    return (ptr_artist);
}

/* 새로운 노래 노드를 만드는 함수*/
Song * creat_song_instatnce(Artist *ptr_artist, char *title, char *path){
    Song *ptr_song = (Song *)malloc(sizeof(Song));
    ptr_song->artist = ptr_artist;
    ptr_song->title = title;
    ptr_song->path = path;
    ptr_song->index = num_index;

    num_index++;

    return (ptr_song);
}
/* 새로운 snode 를 만드는 함수*/
SNode *creat_snod_instatnce(SNode *next, SNode *prev, Song *song){
    SNode *ptr_snode = (SNode *)malloc(sizeof(SNode));
    ptr_snode->next = next;
    ptr_snode->prev = prev;
    ptr_snode->song = song;

    return (ptr_snode);
}

/* 가수를 추가하는 함수 */
Artist *add_artist(char *name){
    Artist * ptr_artist = creat_artist_instance(name);
    Artist *p = artist_directory[(unsigned char)name[0]]; // first node
    Artist *q = NULL;

    while (p != NULL && strcmp(p->name, name) < 0){
        q = p;
        p = p->next;
    }
    if (p == NULL && q == NULL){ // 노드가 아무것도 없는 경우
        artist_directory[(unsigned char)name[0]] = ptr_artist;
    }else if (q == NULL){ // 노드를 맨 앞에 추가하는 경우
        ptr_artist->next = artist_directory[(unsigned char)name[0]] = ptr_artist;;
        artist_directory[(unsigned char)name[0]] = ptr_artist;
    }else { // q 다음에 노드를 추가하는 경우
        ptr_artist->next = p;
        q -> next = ptr_artist;
    }

    return (ptr_artist);
}
/* 노래를 추가하는 함수 */
void add_song(char *artist, char *title, char *path){

    Artist *ptr_artist =  find_artist(artist); // 추가할 노래의 가수 찾기
    if (ptr_artist == NULL){// 가수가 존재하지 않는 경우 가수 리스트에 새롭게 추가
        ptr_artist = add_artist(artist);
    }
    Song *ptr_song = creat_song_instatnce(ptr_artist, title, path);
    SNode *ptr_snode = creat_snod_instatnce(NULL, NULL, ptr_song);

    /* insert node */
    insert_node(ptr_artist, ptr_snode);


}
void insert_node(Artist *ptr_artist, SNode *ptr_snode){
    SNode *snode_p = ptr_artist->head;

    while (snode_p != NULL && strcmp(snode_p->song->title, ptr_snode->song->title) < 0){
        snode_p = snode_p->next;
    }
    if (ptr_artist->head == NULL){ // 1. empty
        ptr_artist->head = ptr_snode;
        ptr_artist->tail = ptr_snode;
    }else if (snode_p == ptr_artist->head){ // 2. at the front
        ptr_snode->next =  ptr_artist->head;
        ptr_artist->head->prev = ptr_snode;
        ptr_artist->head = ptr_snode;

    }else if (snode_p == NULL){ // 3. at the end
        ptr_artist->tail->next = ptr_snode;
        ptr_snode->prev = ptr_artist->tail;
        ptr_artist->tail = ptr_snode;
    }else{ // 4. before p
        snode_p->prev->next = ptr_snode;
        ptr_snode->prev = snode_p->prev;
        snode_p->prev = ptr_snode;
        ptr_snode->next = snode_p;
    }
}


/* 가수를 찾는 함수 */
Artist * find_artist(char *name){
    Artist *p = artist_directory[(unsigned)name[0]]; // name의 첫글자로 인덱스를 지정, 글자 하나는 1 바이트로 00000000~11111111 까지 가능한데 맨 앞 비트가 1이면 음수로 해석되기 때문에 unsinged 를 해준다.
    while ( p != NULL && strcmp(p->name , name) < 0){ // 안에서 이름도 알파벳 순서로 정렬되어 있기 떄문이다.
        p = p->next;
    }
    if (p != NULL && strcmp(p->name , name) == 0){
        return (p);
    }else{
        return (NULL);
    }

}
void print_song(Song *p){
    printf("    %d : %s, %s\n",p->index,p->title,p->path);
}
void print_artist(Artist *p){
    printf("%s\n",p->name);
    SNode *ptr_snode = p->head;
    while (ptr_snode){
        print_song(ptr_snode->song);
        ptr_snode = ptr_snode->next;
    }
}
void status(void){
    for(int i=0; i<NUM_CHAR; i++){
        Artist *p = artist_directory[i];
        while (p != NULL){
            print_artist(p);
            p = p->next;
        }
    }
}
