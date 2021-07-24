#include <stdio.h>
void put(char *path);
void print(char *path);
int main() {
    char path[100]= "/Users/choewonjun/Desktop/HellowWorld/HellowWorld/test.txt";
    int choice=0;
    printf("-------------------------\n");
    printf("텍스트 파일 저장 프로그램\n");
    printf("1. 파일 입력하기\n");
    printf("2. 파일 출력하기\n");
    printf("3. 종료하기\n");
    printf("-------------------------\n\n");


    while (1){

        printf("번호를 입력해주세요 : ");
        scanf("%d",&choice);
        if (choice == 1){
            /* 파일 입력 함수 */

            put(path);
        } else if (choice == 2){
            /* 파일 출력 함수 */
            print(path);
        } else if (choice == 3){
            return 0;
        } else {
            printf("번호를 다시 입력해주세요\n");
        }
    }


    return 0;
}

/* 파일 입력 함수 */
void put(char *path){
    FILE *fp;
    char contents[100]={};

    fp = fopen(path, "w");
    if (fp == NULL) {
        printf("ERROR\n");
    }
    printf("내용을 입력해주세요 : ");
    //scanf("%s",contents);
    //getchar(); // 왜인지 모르겠지만 stadin에 \n이 있어서 이 함수를 사용하지 않으면 입력안되고 그냥 넘어간다.. scanf 를 사용하면 문자입력은 되지만 띄어쓰기 포함시 번호 입력 부분이 띄어쓰기 개수 만큼 계속 반복된다.
    fgets(contents, 100, stdin);
    fputs(contents, fp);

    printf("입력을 완료하였습니다. \n");
    fclose(fp);

}

void print(char *path){
    FILE *fp;
    char contents[100];


    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("ERROR\n");
    }
    fgets(contents, 100, fp);
    printf("%s\n",contents);

    fclose(fp);
}
