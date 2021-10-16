

#include "queueADT.h"
#include "maze.h"

#define MAX 7
#define ROAD 0
#define WALL 1

int maze[MAX][MAX];


void read_maze(void)
{
    int x,y;
    int p;
    char c;
    
    
    x = 0;
    y = 0;
    FILE *fp = fopen("maze.txt", "r");
    while ((c = fgetc(fp)) != EOF){
        if (c == ' ')
            continue;
        if (c == '\n'){
            x++;
            y=0;
            continue;
        }
        p = atoi(&c);
        maze[x][y] = p;
        y++;
    }
    
}

void print_maze(void)
{
    int x,y;
    
    x=0;
    y=0;
    while (x < MAX && y < MAX){
        printf("%d ",maze[x][y]);
        y++;
        if (y == MAX ){
            printf("\n");
            x++;
            y=0;
        }
    }
    
}

void start(void)
{
    int lenght;
    
    Queue q = create();
    Position cur;
    cur.x = 0;
    cur.y = 0;
    cur.length = -1;
    lenght = 2;
    
    enqueue(q, cur);
    
    maze[0][0] = -1;
    bool found = false;
    
    while (!is_empty(q)){
        
        Position cur = dequeue(q);
        if (cur.x == MAX -1 && cur.y == MAX - 1 ){
            printf("Shortist length : %d\n\n",(-cur.length) -1);
            return;
        }
        for (int dir = 0; dir <4; dir ++){
            if (movable(cur , dir)){
                enqueue(q, move_to(cur, dir));
            }
                
        }
        
        
        
    }
    
}
    
int movable(Position cur, int dir)
{
    int offset[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; // N,E,S,W
    if (cur.x + offset[dir][0] <0 || cur.y + offset[dir][1] <0 ||cur.x + offset[dir][0] > MAX || cur.y + offset[dir][1] >MAX)
        return (0);
    if ((maze[cur.x + offset[dir][0]][cur.y + offset[dir][1]]) == 0)
        return (1);
    return (0);
}

Position move_to(Position cur, int dir)
{
    Position tmp;
    
    int offset[4][2] = {{-1,0},{0,1},{1,0},{0,-1}}; // N,E,S,W
    tmp.x = cur.x + offset[dir][0];
    tmp.y = cur.y + offset[dir][1];
    tmp.length = cur.length - 1;
    maze[tmp.x][tmp.y] = tmp.length;
    
    return (tmp);
}
