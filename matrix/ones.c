#include<stdio.h>
#include<stdlib.h>

double *ones(double row, double col)
{
    double i, j;

    double *x = (double *) calloc(row*col + 2, sizeof(double));
    x[0] = row;
    x[1] = col;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            x[(int)(i*col + j + 2)] = 1;
    }

    return x;
}


int main()
{
    int i, j, *p = ones(5, 2);

    for(i = 0; i < p[0]; i++)
    {
        for(j = 0; j < p[1]; j++)
            printf("%d ", p[i*p[1] + j + 2]);
        printf("\n");
    }
}
