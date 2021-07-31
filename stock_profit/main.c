#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void buy(int box,float prise ,int *wallet, float *total_buy, float *total_count);
int main(){
    /*
    int wallet = 10000,day=1;
    float prise,profit_ratio,mean_prise=43.3,total_count=0,total_buy=0;


    FILE *fp = fopen("/Users/choewonjun/Desktop/HellowWorld/HellowWorld/close.txt", "r");
    if (fp == NULL){
        printf("fp ERROR");
        return 0;
    }
    while (fscanf(fp,"%f", &prise)!= EOF){
        if (day == 1) {
            buy(500, prise, &wallet, &total_buy, &total_count);
        } else {
            profit_ratio = prise / mean_prise * 100 - 100;
            mean_prise = total_buy / total_count;
            if (profit_ratio >= 10){
     /*           /* sell function */
    /*
            } else if (wallet > 0){
                if (mean_prise > prise ){
     */
                    /* buy 500 box */
    /*
                    buy(500, prise, &wallet,&total_buy,&total_count);
                } else {
     */
                    /* buy 250 box */
    /*
                    buy(250, prise, &wallet,&total_buy,&total_count);
                }

            } else {
                printf("We don't have any money\n");
            }
        }
        printf("%.2f    %.2f\n",profit_ratio,mean_prise);
        day ++;
    }

    fclose(fp);
    */
    int wallet = 10000,day=1;
    float prise,profit_ratio=0,mean_prise=13,total_count=0,total_buy=0;
    int count = 0,days=0,buy_count=0;
    char *record_date,*temp;
    char start_date[20];

    char size[71];

    FILE *fp = fopen("/Users/choewonjun/Downloads/FNGU.csv", "r");

    if (fp == NULL){
        printf("ERROR");
        return 0;
    }



    printf("one day before start date (yyyy-mm-dd) : ");
    scanf("%s",start_date);

    while (1){
        fgets(size, 71, fp); // 하루 주가 정보를 배열에 넣음
        record_date = strtok(size, ","); // 쉼표를 분리
        if (!strcmp(record_date, start_date)) break;
    }
    while (fgets(size, 71, fp) != NULL){
        record_date = strtok(size, ","); // 쉼표를 분리
        printf("%s\n",record_date); // 날짜 출력
        strtok(NULL, ","); // 시작가
        strtok(NULL, ","); // 고가
        strtok(NULL, ","); // 저가
        temp = strtok(NULL, ","); //종가
        prise= atof(temp); // 종가 문자열을 부동소수로 바꾸기
        prise = round(prise * 100) / 100;

        /* 수익률 구하는 부분*/

        if (day == 1) {
            buy(500, prise, &wallet, &total_buy, &total_count);
            mean_prise = prise;
        } else {
            profit_ratio = prise / mean_prise * 100 - 100;
            mean_prise = total_buy / total_count;
            if (profit_ratio >= 10){
               /* sell function */
                buy_count++;

            } else if (wallet > 0){
                if (mean_prise > prise ){
                    /* buy 500 box */
                    buy(500, prise, &wallet,&total_buy,&total_count);
                } else {

                    /* buy 250 box */
                    buy(250, prise, &wallet,&total_buy,&total_count);
                }
            } else {
                printf("We don't have any money\n");
            }
        }
        printf("%.2f    %.2f\n",profit_ratio,mean_prise);
        day ++;
        count ++;
    }
    printf("------------------------\n");
    printf("남은 금액 : %d\n",wallet);
    printf("총 매입 : %f\n",total_buy);
    printf("평단가 : %.2f\n",mean_prise);
    printf("최종 수익률 : %.2f\n",profit_ratio);
    printf("매도 횟수 : %d\n",buy_count);

    fclose(fp);

    return 0;
}

void buy(int box,float prise ,int *wallet, float *total_buy, float *total_count){

    *wallet -= box / prise * prise; // 지갑에서 매입 금액 빼기
    *total_buy += box / prise * prise; // 총 매수에 매입 금액 더하기
    *total_count += box / prise; // 총 매입량에 매입량 더하기

}

void sell(float prise ,int *wallet, float *total_buy, float *total_count, float profit_ratio){

    profit_ratio

    *total_count -= *total_count / 10;

}
