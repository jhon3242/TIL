
#include <stdio.h>
#include <string.h>
#include "fun.h"
#define START_MONEY 10000
int main(){
    FILE *fp=NULL;
    FILE *s_fp=NULL;
    char line[80];
    char best_date[12];
    char start_date[12];
    char tiker[10];
    float max=0,temp=1;
    int plus=0,minus=0,sum=0;
    int     choise;


    printf("Tiker : ");
    scanf("%s",tiker);
    

    if (strcmp(tiker, "FNGU") == 0){
        fp = fopen("/Users/choewonjun/Downloads/FNGU.csv", "r");
        s_fp = fopen("/Users/choewonjun/Downloads/FNGU.csv", "r");
    } else if (strcmp(tiker, "SOXL") == 0){
        fp = fopen("/Users/choewonjun/Downloads/SOXL.csv", "r");
        s_fp =fopen("/Users/choewonjun/Downloads/SOXL.csv", "r");
    } else if (strcmp(tiker, "TQQQ") == 0){
        fp = fopen("/Users/choewonjun/Downloads/TQQQ.csv", "r");
        s_fp = fopen("/Users/choewonjun/Downloads/TQQQ.csv", "r");
    }

    if (fp == NULL && s_fp == NULL){
        printf("ERROR");
        return -1;
    }
    //program(start_date, fp, START_MONEY);
    printf("Pick the choise.\n");
    printf("---------------------\n");
    printf("1. Show all days profit.\n");
    printf("2. Show one day profit.\n");
    printf("Chose : ");
    scanf("%d",&choise);
    
    if (choise == 1){
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

            sum += temp;
        }

        printf("\n\n");
        printf("---------------------\n");
        printf("Tiker : %s\n",tiker);
        printf("start capital : %d\n",START_MONEY);
        printf("best date : %s\n",best_date);
        printf("best date net profitR : %.2f\n\n",max);
        printf("plus ratio : %.2f \n", (float)plus *100 /  213 );
        printf("average profit : %d \n",sum / 213);
    }else if (choise == 2){
        for(int i=0;i<213;i++){
            printf("check date(yyyy-mm-dd) : %s",start_date);
            scanf("%s",start_date);
            fseek(fp, 0, SEEK_SET);
            printf("---------------------\n");
            printf("check date : %s\n",start_date);
            
            temp = program_each(start_date, fp, START_MONEY);
            if (temp > 0){
                plus++;
            } else {
                minus++;
            }
            sum += temp;
        }
    }
    fclose(fp);
    fclose(s_fp);


    return 0;
}
