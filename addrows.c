#include<stdio.h>
#include<stdlib.h>
int *addrows(int *a, int *b)
{
    int i, j, row, col;
    if(a[1] != b[1])
    {
        printf("addrows error\n");
        exit(1);
    }

    row = a[0] + b[0];
    col = a[1];

    int *x = (int*) calloc(row*col + 2, sizeof(int));

    x[0] = row;
    x[1] = col;

    for(i = 0; i < a[0]; i++)
    {
        for(j = 0; j < col; j++)
            x[i*col + j + 2] = a[i*col + j + 2];
    }

    for(i = a[0]; i < row; i++)
    {
        for(j = 0; j < col; j++)
            x[i*col + j + 2] = b[(i - a[0])*col + j + 2];
    }

    return x;
}
int main()
{
    int i, j;
    int z[18] = {4, 4, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int y[10] = {2, 4, 10, 20, 30, 40, 100, 200, 300, 400};

    int *p = addrows(y, z);

    for(i = 0; i < p[0]; i++)
    {
        for(j = 0; j < p[1]; j++)
            printf("%d ", p[i*p[1] + j + 2]);
        printf("\n");
    }
}
