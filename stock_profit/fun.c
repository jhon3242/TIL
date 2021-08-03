#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"
void buy(int *total_count, int box, float prise, int *capital, float *total_buy, float *mean_prise){
    *total_count += box / prise;  // 총 구매량
    *total_buy += (box / prise) * prise; // 총 구입금액
    *capital -= (box / prise) * prise; // 자본
    *mean_prise = *total_buy / *total_count; // 평단가
}

void sell(int *total_count, float prise, int *capital, float *total_buy){
    *capital += (*total_count) * prise; // 전량매도
    *total_count = 0;
    *total_buy = 0;
}

int program(char *start_date, FILE *fp, int start_money){
    char line[80]={}; // csv each line
    char check_date[12]; // checking date
    char last_date[12]; // 40 days later from start date
    char prise_str[12]; // prise made of string
    char *ptr;
    int day = 1, capital = start_money, repeat = 0, i=0, box = start_money / 40, total_count=0, sell_count=0;
    float profit=0, mean_prise=0, total_buy=0, prise=0, current_buy_value=0,net_profit=0;

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
            buy(&total_count, box, prise, &capital, &total_buy, &mean_prise);

        } else {
            /* not day 1*/
            profit = (prise / mean_prise) * 100 -100 ; // 수익률
            current_buy_value = total_buy + total_buy * profit / 100; // 현재 가치
            if (profit >= 10){

                /* sell function */
                sell(&total_count, prise, &capital, &total_buy);
                net_profit += (capital - start_money); // 순이익

                /* reset*/
                mean_prise = prise ; // to make profit 0
                current_buy_value = 0; // current_buy_value reset
                sell_count++;


                //printf("------sell------\n");
                //printf("date : %s\n\n",check_date);
                //printf("now capital : %d \n",capital);
                //printf("sold date : %s \n\n",check_date);

            } else {
                /* buy function */
                if (capital <= 0) {
                    printf("No More Money\n");

                    return -1;
                }
                if (prise >= mean_prise ){
                    buy(&total_count, box / 2, prise, &capital, &total_buy, &mean_prise);

                } else{
                    buy(&total_count, box, prise, &capital, &total_buy, &mean_prise);
                }
                profit = (prise / mean_prise) * 100 -100 ; // 수익률
                //printf("------buy------\n");
                //printf("current prise : %.2f \n",prise);
                //printf("mean    prise : %.2f \n",mean_prise);
                //printf("profit : %.2f \n",profit);
                //printf("date : %s\n\n",check_date);
                //printf("total value : %.2f\n",current_buy_value + capital );
                //printf("D + %d \n\n",day);
            }
        }

        //printf("D + %d \n",day);
        day ++;
    }
    printf("net profit : %.2f\n",net_profit );
    printf("sell count : %d\n",sell_count);

    return net_profit ;
}
