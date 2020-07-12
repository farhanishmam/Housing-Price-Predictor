#include<stdio.h>
#include<stdlib.h>
int *func(int *a)
{
    int i, size = 25;
    int *x;
    x = calloc(size, sizeof(int));

    for(i = 1; i < size; i++)
        x[i] = a[i];
    return x;
}
int main()
{
    int i, a[5][5] = {4, 1, 2, 3, 4, 5, 6, 7, 8};
    int *p = func(a);

    for(i = 0; i <5; i++)
        for(int j = 0; j<5; j++)
        printf("%d ", p[i*5+j]);
}
