/*사용자로 부터 5 명의 학생의 수학, 국어, 영어 점수를 입력 받아서
평균이 가장 높은 사람 부터 평균이 가장 낮은 사람까지 정렬되어 출력하도록 하세요.
특히, 평균을 기준으로 평균 이상인 사람 옆에는 '합격', 아닌 사람은 '불합격' 을
출력하게 해보세요 (난이도 : 中上).*/
#include <stdio.h>
int all_avg(int (*p)[3], int r, int c);
int avg(int *p);
int main(){
    int i;
    int arr[4][3] ={{70, 80, 90},{40, 50, 70},{10, 100,60},{70,80,100}};
    int all_avg_num = all_avg(arr,4,3) ;
    int avg_arr[4];
    printf("전체 평균 : %d \n",all_avg_num);

    int max;
    int temp = 9999;
    int max_i;
    int num;
    for (int j = 0 ; j<4; j++){
        max=0;
        for(i=1; i<=4; i++){
            num = avg(arr[i-1]);
            if (temp> num && num >= max){
                max = num;
                max_i = i;
            }

        }
        printf("%d 번째 학생 평균 : %d \n", max_i, max);
        temp = max;
    }




    return 0;
}
int avg(int *p){
    int i,n;
    n=0;
    for (i=0; i<3; i++){
        n += p[i];
    }
    return n/3;
}

int all_avg(int (*p)[3], int r, int c){
    int i,j;
    int n=0;
    for (i = 0; i<r; i++){
        for (j=0; j<c; j++){
            n += p[i][j];
        }
    }

    return n/(r*c);
}
