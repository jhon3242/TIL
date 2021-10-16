#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

Person ** directroy; // 구조체 포인터 배열을 위한 포인터의 포인터
int capacity;
int n; // 전체 사람 수

int main(){
    init();
    start();
    return 0;
}


