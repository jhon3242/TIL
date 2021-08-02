#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void buy(int box,float prise ,int *wallet, float *total_buy, float *total_count);
void sell(float prise ,int *wallet, float *total_buy, float *total_count, float profit_ratio);
void inf_buy(char *start_date,char *record_date, char *size, FILE *fp, int *box, int *wallet, float *total_buy);
int main(){

    int wallet = 10000;
    float total_buy=0;

    int box = wallet / 40;
    char *record_date;
    char start_date[20] = "2020-07-31";

    char size[80];
    //char s_size[80];

    FILE *fp = fopen("/Users/choewonjun/Downloads/FNGU.csv", "r");
    //FILE *s_fp = fopen("/Users/choewonjun/Downloads/FNGU.csv", "r");
    if (fp == NULL){
        printf("ERROR");
        return 0;
    }

    //printf("one day before start date (yyyy-mm-dd) : \n");
    //scanf("%s",start_date);


    while (1){
        //fgets(s_size, 80, s_fp);
        fgets(size, 80, fp); // 하루 주가 정보를 배열에 넣음
        record_date = strtok(size, ","); // 쉼표를 분리
        if (!strcmp(record_date, start_date)) break;
    }

    inf_buy(start_date, record_date, size, fp, &box, &wallet, &total_buy);


    fclose(fp);
    //fclose(s_fp);

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

void inf_buy(char *start_date,char *record_date, char *size, FILE *fp, int *box, int *wallet, float *total_buy){
    int start_money = *wallet;
    float prise,profit_ratio=0,mean_prise=0,total_count=0;
    int day=1,sell_count=0;
    char *temp;
    while (strcmp(record_date, "2021-07-29")){
        day = 1;
        while (fgets(size, 80, fp) != NULL){

            record_date = strtok(size, ","); // 쉼표를 분리
            strtok(NULL, ","); // 시작가
            strtok(NULL, ","); // 고가
            strtok(NULL, ","); // 저가
            temp = strtok(NULL, ","); //종가
            prise= atof(temp); // 종가 문자열을 부동소수로 바꾸기
            prise = round(prise * 100) / 100;

            /* 수익률 구하는 부분*/

            if (day == 1) {
                buy(*box, prise, wallet, total_buy, &total_count);
                mean_prise = prise;
            } else {
                profit_ratio = prise / mean_prise * 100 - 100;
                mean_prise = *total_buy / total_count;
                if (profit_ratio >= 10){
                   /* sell function */
                    sell(prise, wallet, total_buy, &total_count, profit_ratio);
                    *box = *wallet / 40;
                    printf("날짜 : %s\n",record_date);
                    sell_count++;
                    break;

                } else if (*wallet > prise){
                    if (mean_prise < prise ){
                        /* buy box/2 */
                        buy(*box/2, prise, wallet,total_buy,&total_count);
                    } else {
                        /* buy box */
                        buy(*box, prise, wallet,total_buy,&total_count);
                    }
                } else {
                    printf("---------reset----------\n");
                    printf("We don't have any money\n");
                    printf("reset day : %s\n",record_date);
                    day = 1;
                    mean_prise = prise;
                    *wallet = start_money;
                    *total_buy = 0;
                    total_count = 0;
                    strcpy(start_date, record_date);
                }
            }
            day ++;

        }
    }
    printf("-----------종료--------------\n");
    printf("시작 전 자본금 : %d\n",start_money);
    printf("최종 총 자본금 : %.1f\n",*wallet + *total_buy);
    printf("매도 횟수 : %d\n",sell_count);
    printf("시작 날짜 : %s\n",start_date);
    printf("종료 날짜 : %s\n",record_date);

}
