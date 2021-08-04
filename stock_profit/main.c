
#include <stdio.h>
#include <string.h>
#include "fun.h"
#define START_MONEY 10000
int main(){
    char line[80];
    char best_date[12];
    char start_date[12]="2020-09-02" ;
    float max=0,temp=1;
    int plus=0,minus=0;
    FILE *fp = fopen("/Users/choewonjun/Downloads/FNGU.csv", "r");
    FILE *s_fp = fopen("/Users/choewonjun/Downloads/FNGU.csv", "r");
    if (fp == NULL && s_fp == NULL){
        printf("ERROR");
        return -1;
    }
    //program(start_date, fp, START_MONEY);

    for(int i=0;i<213;i++){
        fgets(line, 80, s_fp);
        strcpy(start_date, strtok(line, ","));
        fseek(fp, 0, SEEK_SET);
        printf("---------------------\n");
        printf("check date : %s\n",start_date);
        temp = program(start_date, fp, START_MONEY);
        if (temp > 0){
            plus++;
        } else {
            minus++;
        }
        if (temp > max){
            max = temp;
            strcpy(best_date, start_date);
        }
    }

    printf("\n\n");
    printf("---------------------\n");
    printf("best date : %s\n",best_date);
    printf("best date value : %.2f\n\n",max);
    printf("plus ratio : %.2f \n", (float)plus *100 /  213 );
    fclose(fp);
    fclose(s_fp);


    return 0;
}
