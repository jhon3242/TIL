#include <stdio.h>

int max_number(int *parr);
int main() {
    int arr[10] ={100, 50, 102, 300, 900, 700, 550, 400, 800, 600};

    max_number(arr);

    return 0;
}
int max_number(int *parr) {
    int length = 10;
    int temp=9999;
    int i,j;

    for (j=0;j<length;j++){
        int max = parr[0];
        for (i=1;i<length;i++){
            if (temp > parr[i] && parr[i] > max){
                max = parr[i];
            }
        }
        printf("%d \n",max);
        temp = max;

    }
    return 0;

}
