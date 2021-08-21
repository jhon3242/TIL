#include "maze.h"
#include "queueADT.h"
int main(){
    
    read_maze();
    print_maze();
    printf("------------------\n\n");
    start();
    print_maze();
    return (0);
}
