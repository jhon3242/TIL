#include <stdio.h>
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = &arr[0];
    int i;

    for (i = 0 ; i<10; i++){
        printf("arr[%d]의 주소값 : %p ", i , &arr[i]);
        printf("(p + %d)의 주소값 : %p" ,i, (p + i));

        if (&arr[i] == ( p + i)){
            printf("---> 일치 \n");
        } else {
            printf("---> 불일치 \n");
        }
    }

    return 0;
}