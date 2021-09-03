#include <stdio.h>
int main() {
    int a=0;
    int binary[20] = {0,};
    int position = 0;
    a = 8;

    while (1){
        binary[position] = a % 2;
        a = a / 2;
        position += 1;

        if (a == 0) break;
    }

    for (int i = position -1 ; i>=0;i--){
        printf("%d",binary[i]);
    }

    return 0;
}
