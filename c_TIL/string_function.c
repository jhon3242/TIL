#include <stdio.h>
int length(char *p);
int copy(char *obj,char *val);
int str_sum(char *str1, char *str2);
int compare(char *str1, char *str2);
int main() {

    char a[] = "hi ";
    char b[] = "hi";
    /*
    printf("복사 이전 : %s \n",a);
    copy(a, b);
    printf("복사 이후 : %s \n",a);
    */
    /*
    printf("합치기 전 : %s \n",a);
    str_sum(a, b);
    printf("합치기 전 : %s \n",a);
    */
    printf("두 문자열이 같을까? : ");
    if (compare(a, b)){
        printf("Yes \n");
    } else {
        printf("No \n");
    }


    return 0;

}
/* 문자열을 인자로 받아 그 문자열의 길이를 리턴하는 함수*/
int length(char *p){
    int i=0;
    while (p[i]){
        i++;
    }
    return i+1;
}
/* 첫번째 인자로 바꿀 문자열을 주고 두번째 인자로 바꿀 값을 넣어주어 문자열을 복사하는 함수이다*/
int copy(char *obj,char *val){
    int i=0;
    while (val[i]){
        obj[i] = val[i];
        i++;
    }
    obj[i] = '\0';
    return 1;
}

/* 첫번째 인자로 받은 문자열에 두번째 인자로 받는 문자열을 추가하는 함수이다.*/
int str_sum(char *str1, char *str2){
    int i=0,j=0;
    while (str1[i]){
        i++;
    }
    while (str2[j]){
        str1[i+j] = str2[j];
        j++;
    }
    str1[i+j] = '\0';
    return 1;
}

/* 두개의 문자열을 인자로 받아 둘이 같은지 확인하는 함수이다. 같으면 1을, 틀리면 0을 리턴한다.*/
int compare(char *str1, char *str2){
    int i=0;
    while (str1[i]){
        if (str1[i] != str2[i]){
            return 0;
        }
        i++;
    }
    if (str2[i] =='\0') return 1;

    return 0;
}
