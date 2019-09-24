#include<stdio.h>
#include<stdlib.h>
int *multiply_scalar(int *a, int b)
{
    int i, j;
    int row = a[0], col = a[1];

    int *x;
    x = (int*) calloc(row*col + 2, sizeof(int));

    x[0] = row;
    x[1] = col;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            x[i*col + j + 2] = a[i*col + j + 2] * b;
    }
    return x;
}
int main()
{
    int i, j;
    int m[18] = {2, 2, 6, 9, 6, 9};

    int *p = multiply_scalar(m, 4);
    int r = *p, c = *(p + 1);

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d ", p[i*c + j + 2]);
        printf("\n");
    }
}

