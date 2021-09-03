#include <stdio.h>
int main(){
    int a;
    int *p;
    int **pp;

    p = &a;
    pp = &p;

    a = 3;

    printf("a : %d // *p : %d // **pp : %d \n", a, *p, **pp);
    printf("&a : %p // p : %p // *pp : %p \n", &a, p, *pp);
    printf("&p : %p // pp : %p \n", &p, pp);




    return 0;
}