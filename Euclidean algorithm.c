#include <stdio.h>
int Euclidean(int big, int small);
int rest_check(int a, int b);
int main(){
    int a,b;
    printf("a : ");
    scanf("%d",&a);
    printf("b : ");
    scanf("%d",&b);

    printf("answer : %d \n",Euclidean(a,b));

    return 0;
}
int Euclidean(int big, int small){
    // biger one switch
    if (small >= big){
        int temp;
        temp = big;
        big = small;
        small = temp;
    }


    do {
        int check = rest_check(big, small);
        if (check != 0){
            return check;
        }
        int temp;
        temp = big;
        big = small;
        small = temp % small;
    } while (small > 1);






    return 0;
}
// check if the rest is 0
int rest_check(int a, int b){
    int rest;
    rest = a % b;
    if (rest == 0){

        return b;
    }
    return 0;
}
