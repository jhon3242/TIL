#include <stdlib.h>

int make_range(int **range, int min, int max)
{
    int size;
    int i;

    size = max - min;
    if (size < 0)
        return (-1);
    *range = malloc(size * sizeof(int));
    if (!range)
        return (-1);
    i = 0;
    while (i < size){
        (*range)[i] = min;
        i++;
        min++;
    }
    return (size);
}

int main(){
    int arr[5];
    int *p;
    /*
    int **p;
    int a = make_range(p,1,10);
    */
    int a = make_range(&p,1,10);
    return 0;
}