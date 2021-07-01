#include <stdio.h>
int running (int num){

    if (num % 2 ==0){
        num = num / 2;
        printf("2 ");
    } else if (num % 3 == 0){
        num /= 3;
        printf("3 ");
    } else if (num % 5 == 0){
        num /= 5;
        printf("5 ");
    } else if (num % 7 == 0){
        num /= 7;
        printf("7 ");
    }

    return num;
}
int factorize(int num){
    while (1){

        int a = running(num);
        num = a;
        if (a >= 2 ){
            printf("X ");

        } else{
            printf("\n");
            return 0;
        }
    }
}

int main(){
    int N;
    printf("What is N? :");
    scanf("%d",&N);
    factorize(N);
    return 0;
}
