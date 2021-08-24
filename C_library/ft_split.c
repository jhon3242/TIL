#include <stdlib.h>

int is_charset(char ch, char *charsert)
{
    int     i;

    i = 0;
    while (charsert[i])
    {
        if (charsert[i] == ch)
            return (1);
        i++;
    }
    return (0);
}

int count_word(char *str, char *charset)
{
    int     i;
    int     count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (is_charset(str[i],charset) == 0 && is_charset(str[i+1],charset) == 1)
            count++;
        i++;
    }
    return (count);
}
void split_word(char *str, char *charset, char **result)
{
    int     i;
    int     j;
    char*   tmp;

    str ++; // 현재 구분자 위치에 있기 때문에 다음 단어부터 추가하도록 한다.
    tmp = str;
    i = 0;
    while (!is_charset(*str, charset))
    {
        str++;
        i++;
    }
    char *word = (char *)malloc(sizeof(char)*i + 1);
    str = tmp;
    j = 0;
    while (!is_charset(*str, charset) && j<i)
    {
        word[j] = str[j];
        j++;
    }
    word[j] = '\0';
    *result = word;
}


char    **ft_split(char *str, char *charset)
{
    int     i;
    char **result = (char **)malloc(sizeof(char *) * count_word(str, charset));;
    char **tmp;
    i = 0;
    tmp = result ;
    while (str[i] && str[i+1])
    {
        if (is_charset(str[i], charset) == 1 && is_charset(str[i+1], charset) == 0){
            split_word(&str[i],charset,result++);
        }
        i++;

    }

    return (tmp);
}