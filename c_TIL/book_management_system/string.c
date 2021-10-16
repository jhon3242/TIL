//
//  string.c
//  
//
//  Created by 최원준 on 2021/07/15.
//
#include <stdio.h>
#include "string.h"
/* 문자열 비교 함수 */
int compare(char *str1, char *str2) {
  while (*str1) {
    if (*str1 != *str2) {
      return 0;
    }

    str1++;
    str2++;
  }

  if (*str2 == '\0') return 1;

  return 0;
}
