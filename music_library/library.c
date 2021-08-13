
#include "library.h"
#include "string_tools.h"

#define NUM_CHAR 256
#define INDEX_TABLE_SIZE 100

Artist *artist_directory[NUM_CHAR]; // 가수 배열
SNode *index_directory[INDEX_TABLE_SIZE]; // 노래 인덱스 배열
int num_index = 0;

void load(FILE *fp){
    char buffer[BUFFER_LENGHTS];
    char *artist, *title, *path;
    while (1){ // infinite loop
        if (read_line(fp, buffer, BUFFER_LENGHTS) <=0){
            break;
        }
        artist =strtok(buffer, "#");
        if (strcmp(artist, " ")==0){
            artist = NULL;
        }else{
            artist = strdup(artist);
        }

        title =strtok(NULL, "#");
        if (strcmp(title, " ")==0){
            title = NULL;
        }else{
            title = strdup(title);
        }


        path =strtok(NULL, "#");
        if (strcmp(path, " ")==0){
            path = NULL;
        }else{
            path = strdup(path);
        }

        add_song(artist, title, path);

    }
}

void initialize(void){
    for (int i = 0; i<NUM_CHAR;i++){
        artist_directory[i] = NULL;
    }
    for (int i = 0; i<INDEX_TABLE_SIZE;i++){
        index_directory[i] = NULL;
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
        ptr_artist->next = artist_directory[(unsigned char)name[0]];
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
    insert_to_index_directory(ptr_song);

}
void insert_to_index_directory(Song *ptr_song){
    SNode *ptr_snode = creat_snod_instatnce(NULL, NULL, ptr_song);
    int index = ptr_song->index % 10; // 노래 인덱스의 일의 자리에 따라서 배열에서 저장되는 위치가 다름

    //add snode to index table
    SNode *p = index_directory[index];
    SNode *q = NULL;
    while (p != NULL && strcmp(p->song->title, ptr_song->title) < 0){
        q = p;
        p = p->next;
    }
    if (q == NULL){ // add first
        index_directory[index] = ptr_snode;
        ptr_snode->next = p;
    }else{ // add after q
        q->next = ptr_snode;
        ptr_snode->next = p;
    }
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

void search_song(char *artist, char *title){

    Artist *ptr_artist = find_artist(artist);
    if (ptr_artist == NULL){
        printf("No such artist.\n");
        return;
    }

    if (title[0] == '\0'){
        print_artist(ptr_artist);
        return;
    }


    SNode *find = find_snode(ptr_artist, title);
    if(find){ // 노래를 찾았으면
        print_song(find->song);
    }


    return;
}
SNode *find_snode(Artist *ptr_artist, char *title){

    SNode *ptr_snode = ptr_artist->head;
    while (ptr_snode != NULL && strcmp(ptr_snode->song->title, title)<0){
        ptr_snode = ptr_snode->next;
    }
    if (ptr_snode != NULL && strcmp(ptr_snode->song->title, title)==0){
        return ptr_snode;
    }
    else{
        printf("No such title.\n");
        return NULL;
    }
}
SNode *find_song(int index){

    SNode *p = index_directory[index % INDEX_TABLE_SIZE];
    while (p != NULL && p->song->index != index){
        p = p->next;
    }
    return p;
}

void play(int index){

    SNode *ptr_snode = find_song(index);
    if (ptr_snode == NULL){
        printf("No such index.\n");
        return;
    }
    //맥에서는 아직 구현하지 못했음


}
void save_song(SNode *p, FILE *fp){
    char *artist, *title, *path;

    artist = p->song->artist->name;
    fprintf(fp,"%s", artist);
    fprintf(fp, "#");

    title = p->song->title;
    if (title == NULL){
        fprintf(fp, " ");
    }else{
        fprintf(fp,"%s", title);
    }
    fprintf(fp, "#");

    path = p->song->path;
    if (path == NULL){
        fprintf(fp, " ");
    }else{
        fprintf(fp,"%s", path);
    }
    fprintf(fp, "#\n");
}
void save_artist(Artist *p, FILE *fp){

    SNode *ptr_snode = p->head;
    while (ptr_snode){
        save_song(ptr_snode, fp);
        ptr_snode = ptr_snode->next;
    }
}

void save(FILE *fp){
    for(int i=0; i<NUM_CHAR; i++){
        Artist *p = artist_directory[i];
        while (p != NULL){
            save_artist(p, fp);
            p = p->next;
        }
    }
}

void removes(int index){
    SNode *q = NULL;
    SNode *p = index_directory[index % INDEX_TABLE_SIZE];

    while (p != NULL && p->song->index != index){
        q = p;
        p = p->next;
    }
    if ( p == NULL){ // 노드가 비어 있거나 내가 찾는 인덱스가 없는 경우
        printf("No such song exist.\n");
        return;
    }


    Song *ptr_song = p->song; // song 노드와 연결된 것들을 삭제하기 위해서

    /* index_directory 에서 해당 snode 삭제*/
    if (q == NULL){ // 맨 처음에 있는 경우
        index_directory[index % INDEX_TABLE_SIZE] = p->next;

    }else{          // q 다음 노드를 삭제하는 경우
        q->next = p->next;
    }
    free(p);

    /* 이중연결리스트 노드 삭제*/
    Artist *ptr_artist = ptr_song->artist;
    SNode *ptr_snode = find_snode(ptr_artist, ptr_song->title);
    if (ptr_snode == NULL){
        printf("Can't find snode. -error\n");
        return;
    }

    remove_snode(ptr_artist, ptr_snode);


    if (ptr_song->title != NULL){
        free(ptr_song->title);
    }
    if (ptr_song->path != NULL){
        free(ptr_song->path);
    }
    free(ptr_song);

}

void remove_snode(Artist *ptr_artist, SNode *ptr_snode){
    SNode *first = ptr_artist->head;
    SNode *last = ptr_artist->tail;

    if (ptr_snode == first && ptr_snode == last){ // 유일한 노드였던 경우
        free(ptr_snode);

        Artist *p = artist_directory[(unsigned)ptr_artist->name[0]];
        Artist *q=NULL;
        while ( p != NULL && strcmp(p->name , ptr_artist->name) < 0){ // 안에서 이름도 알파벳 순서로 정렬되어 있기 떄문이다.
            q = p;
            p = p->next;
        }
        if (q != NULL && p->next != NULL){
            q->next = p->next;
        }
        free(ptr_artist);

        if (q == NULL){
            artist_directory[(unsigned)ptr_artist->name[0]] = NULL;
        }

    }else if (ptr_snode == first){ // 첫 노드였던 경우
        ptr_artist->head =ptr_snode->next;
        free(ptr_snode);
    }else if (ptr_snode == last){ // 마지막 노드였던 경우
        ptr_artist->tail = ptr_snode->prev;
        free(ptr_snode);
    }else{                          // 중간 노드였던 경우
        ptr_snode->prev->next = ptr_snode->next;
        ptr_snode->next->prev = ptr_snode->prev;
        free(ptr_snode);
    }
}


