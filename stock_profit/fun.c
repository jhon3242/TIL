#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"
int capital,total_count;
float total_buy,mean_prise;

void buy( int box, float prise){
    int count = box / prise; // 구매량
    total_count += count;  // 총 구매량
    total_buy += count * prise; // 총 구입금액
    capital -= count * prise; // 자본
    mean_prise = total_buy / total_count; // 평단가
}

void sell(float prise){
    capital += total_count * prise; // 전량매도
    total_count = 0;
    total_buy = 0;
}

int program(char *start_date, FILE *fp, int start_money){
    char line[80]={}; // csv each line
    char check_date[12]; // checking date
    char last_date[12]; // 40 days later from start date
    char prise_str[12]; // prise made of string
    char *ptr;
    int day = 1, repeat = 0, i=0, box = start_money / 40,  sell_count=0, temp=0;
    float profit=0,  prise=0, current_buy_value=0, net_profit=0;

    capital = start_money;
    total_count = 0;
    mean_prise=0;
    total_buy=0;

    while (1){
        repeat++;
        fgets(line, 80, fp);
        strcpy(check_date, strtok(line, ","));
        if (!strcmp(start_date, check_date)) break;
    }

    for (i =0;i<40;i++){
        if (fgets(line, 80, fp)==NULL) {
            printf("no more 40\n");
            return -1;
        }
    }
    strcpy(last_date, strtok(line, ","));
    fseek(fp, 0, SEEK_SET);

    for (i=0;i<repeat -1;i++){
        fgets(line, 80, fp);
    }

    while (strcmp(check_date, last_date)){
        fgets(line, 80, fp); //line : "check date, prise, prise. ..."
        ptr = strtok(line, ",");
        strcpy(check_date, ptr);
        strtok(NULL, ",");
        strtok(NULL, ",");
        strtok(NULL, ",");
        ptr = strtok(NULL, ",");
        strcpy(prise_str, ptr);
        prise = atof(prise_str);
        prise = round(prise *100) /100;


        if (day - 1 == 0){
            /* first buy */
            buy(box, prise);
            mean_prise = prise;
            //printf("------buy------\n");
            //printf("current prise : %.2f \n",prise);
            //printf("mean    prise : %.2f \n",mean_prise);
            //printf("profit : %.2f \n",profit);
            //printf("D + %d \n\n",day);
        } else {
            /* not day 1*/

            /* 수익률 업데이트 부분 */
            if (mean_prise == 0){
                profit = 0; // 판매 이후에 평단가가 없을 때
            } else {
                profit = (prise / mean_prise) * 100 -100 ; // 구매전 수익률
            }

            /* 수익률이 10% 를 넘었을 때*/
            if (profit >= 10){

                /* sell function */
                sell(prise);
                net_profit += (capital - start_money); // 순이익 추가
                capital = start_money; // 다시 시작 자본으로 바꾸기

                /* reset*/
                mean_prise = 0 ;
                current_buy_value = 0; // current_buy_value reset
                sell_count++;

                /*
                printf("------sell------\n");
                printf("date : %s\n",check_date);
                printf("Total net profit : %.2f \n", net_profit);
                printf("sold date : %s \n\n",check_date);
                 */

            } else { /* buy function */

                if (capital <= 0) {
                    if (net_profit >= box){
                        buy(box, prise); // 이전 이익에서 가져오기
                        temp = box / prise; // 소수점 오차를 줄이기 위해 정수형 temp 를 만들어 사용
                        net_profit -= temp * prise ;
                    } else {
                        printf("No More Money\n");
                        return -1;
                    }

                }

                if (prise < mean_prise || mean_prise ==0 ){
                    buy(box, prise); // 주가가 평단가보다 싸거나 판매 이후 첫 매수일 때
                } else{
                    buy(box/2, prise);
                }
                profit = (prise / mean_prise) * 100 -100 ; // 구매 이후 수익률
                current_buy_value = total_buy + total_buy * profit / 100; // 현재 가치
                /*
                printf("------buy------\n");
                printf("current prise : %.2f \n",prise);
                printf("mean    prise : %.2f \n",mean_prise);
                printf("profit : %.2f %% \n",profit);
                printf("total   buy : %.2f \n",total_buy);
                printf("total   count : %d \n",total_count);
                printf("net   profit : %.2f \n",total_buy * profit/100);
                printf("date : %s\n",check_date);
                printf("total value : %.2f\n\n",current_buy_value + capital );
                printf("D + %d \n\n",day);
                 */
            }
        }

        //printf("D + %d \n",day);
        day ++;
    }
    printf("net profit : %.2f\n",net_profit );
    printf("sell count : %d\n",sell_count);

    return net_profit ;
}
