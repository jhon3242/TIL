#include <stdio.h>
int length(char *str);
int main() {
  char str[] = {"How long this string?"};

  printf("이 문자열의 길이 : %d \n", length(str));

  return 0;
}
int length(char *str) {
  int i = 0;
  while (str[i]) {
    i++;
  }

  return i;
}
