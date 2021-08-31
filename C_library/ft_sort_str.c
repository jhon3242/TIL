int ft_strcmp(char *st1, char *st2)
{
    int     i;
    i = 0;
    while (st1[i] || st2[i])
    {
        if (st1[i] != st2[i])
            return (st1[i] - st2[i]);
        i++;
    }
    return 0;
}


int count_word(char **tab)
{
    int     i;
    i = 0;
    while (tab[i] != 0)
        i++;
    return (i);
}

void ft_sort_string_tab(char **arr)
{
    int     i;
    int     j;
    int     size;
    char *  tmp;
    
    i = 1;
    
    size = count_word(arr);
    
    while (i < size){
        j = i - 1;
        tmp = arr[i];
        while (j >= 0)
        {
            if (ft_strcmp(arr[j], tmp) > 0)
            {
                
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
            j--;
        }
        i++;
    }

}
