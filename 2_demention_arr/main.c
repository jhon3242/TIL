#include <stdio.h>
#include <stdlib.h>
#include "arr.h"
int main(){
    int r,c,user_choice,running=1;
    
    printf("행의 크기:");
    scanf("%d",&r);
    printf("열의 크기:");
    scanf("%d",&c);
    
    int (*arr)[c] = (int (*)[c])malloc(r * c * sizeof(int));
    input_arr(r, c, arr);
    
    printf("---------------------\n");
    printf("1. 배열 출력\n");
    printf("2. 배열에 숫자 더하기 출력\n");
    printf("3. 종료\n");
    printf("---------------------\n");
    
    
    while (running){
        printf("어떤 업무를 할까요? : ");
        scanf("%d",&user_choice);
        switch (user_choice) {
            case 1:
                /* 배열 출력 함수*/
                print_arr(r, c, arr);
                break;
            case 2:
                /* 배열 숫자 더하기 함수*/
                sum_arr(r, c, arr);
                break;
            case 3:
                /* 종료 */
                running = 0;
                break;
                
            default:
                printf("맞는 숫자를 입력해주세요.\n");
                break;
            
        }
    }
    free(arr);
    
    
    
    return 0;
}

