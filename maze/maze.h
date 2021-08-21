

#ifndef MAZE_h
#define MAZE_h


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queueADT.h"

void read_maze(void);
void print_maze(void);
void start(void);
int movable(Position cur, int dir);
Position move_to(Position cur, int dir);

#endif /* library_h */
