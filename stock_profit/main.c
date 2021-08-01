#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void buy(int box,float prise ,int *wallet, float *total_buy, float *total_count);
void sell(float prise ,int *wallet, float *total_buy, float *total_count, float profit_ratio);
int main(){

    int wallet = 5000,day=1;
    float prise,profit_ratio=0,mean_prise=13,total_count=0,total_buy=0;
    int count = 0,sell_count=0;
    char *record_date,*temp;
    char start_date[20]; //= "2021-03-04";

    char size[80];

    FILE *fp = fopen("/Users/choewonjun/Downloads/FNGU.csv", "r");

    if (fp == NULL){
        printf("ERROR");
        return 0;
    }

    printf("one day before start date (yyyy-mm-dd) : \n");
    scanf("%s",start_date);


    while (1){
        fgets(size, 80, fp); // 하루 주가 정보를 배열에 넣음
        record_date = strtok(size, ","); // 쉼표를 분리
        if (!strcmp(record_date, start_date)) break;
    }
    while (strcmp(record_date, "2021-07-29")){
        day = 1;
        while (fgets(size, 80, fp) != NULL){
            record_date = strtok(size, ","); // 쉼표를 분리
            //printf("%s\n",record_date); // 날짜 출력
            strtok(NULL, ","); // 시작가
            strtok(NULL, ","); // 고가
            strtok(NULL, ","); // 저가
            temp = strtok(NULL, ","); //종가
            prise= atof(temp); // 종가 문자열을 부동소수로 바꾸기
            prise = round(prise * 100) / 100;

            /* 수익률 구하는 부분*/

            if (day == 1) {
                buy(125, prise, &wallet, &total_buy, &total_count);
                mean_prise = prise;
            } else {
                profit_ratio = prise / mean_prise * 100 - 100;
                mean_prise = total_buy / total_count;
                if (profit_ratio >= 10){
                   /* sell function */
                    sell(prise, &wallet, &total_buy, &total_count, profit_ratio);
                    printf("날짜 : %s\n",record_date);
                    sell_count++;
                    break;

                } else if (wallet > prise){
                    if (mean_prise > prise ){
                        /* buy 500 box */
                        buy(62, prise, &wallet,&total_buy,&total_count);
                    } else {

                        /* buy 250 box */
                        buy(125, prise, &wallet,&total_buy,&total_count);
                    }
                } else {
                    printf("We don't have any money\n");
                }
            }
            day ++;
            count ++;
        }
    }
    printf("-----------종료--------------\n");
    printf("시작 전 자본금 : 5000\n");
    printf("최종 총 자본금 : %.1f\n",wallet+total_buy);
    printf("매도 횟수 : %d\n",sell_count);
    printf("시작 날짜 : %s\n",start_date);
    printf("종료 날짜 : %s\n",record_date);

    fclose(fp);

    return 0;
}

void buy(int box,float prise ,int *wallet, float *total_buy, float *total_count){

    *wallet -= box / prise * prise; // 지갑에서 매입 금액 빼기
    *total_buy += box / prise * prise; // 총 매수에 매입 금액 더하기
    *total_count += box / prise; // 총 매입량에 매입량 더하기

}

void sell(float prise ,int *wallet, float *total_buy, float *total_count, float profit_ratio){

    float net_profit = prise * (*total_count) - (*total_buy);
    *wallet += net_profit + (*total_buy);
    *total_count = 0;
    *total_buy = 0;
    printf("---------판매 완료----------\n");
    printf("자본금 : %d\n",*wallet);
    printf("순이익 : %.2f\n",net_profit);

}

