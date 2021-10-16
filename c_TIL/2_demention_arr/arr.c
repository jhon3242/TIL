#include <stdio.h>
#include <stdlib.h>
#include "arr.h"
void input_arr(int r,int c, int (*arr)[c]){
    int i,j;
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("---------완료---------\n");
}
void print_arr(int r,int c, int (*arr)[c]){
    int i,j;
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("---------완료---------\n");
}

void sum_arr(int r, int c, int (*arr)[c]){
    int i,j,num;
    printf("얼만큼 더할까요? : ");
    scanf("%d",&num);
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            arr[i][j] += num;
        }
    }
    printf("---------완료---------\n");
}


