#include <stdio.h>
int swap(int *pele);
int Bubble(int *arr, int element_count);
int main(){
    int arr[5] = { 5, 1, 4, 2, 8};
    Bubble(arr, 5);
    for(int i = 0; i < 5; i ++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

int swap(int *pele){
    int temp;
    temp = *pele;
    *pele = *(pele + 1);
    *(pele + 1) = temp;

    return 0;
}
int Bubble(int *arr, int element_count){
    for (int j = 0; j <element_count-1 ; j ++){
        for (int i=0; i<element_count -1; i++){
            if (arr[i] > arr[i+1] ){
                int *p = arr + i;
                swap(p);
            }
        }
    }

    return 0;
}
