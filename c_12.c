#include<stdio.h>
int main(){
    int a, b;
    float c, d;
    printf("두 숫자를 입력하세요: ");
    scanf("%d %d", &a, &b);
    c = a / b;
    d = (float)a / b;

    printf("두 수의 비율: %f %f \n", c, d);
    return 0;
}