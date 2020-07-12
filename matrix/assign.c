#include<stdio.h>
#include<stdlib.h>
double *assign(double *a)
{
    double i, j;
    double row = a[0], col = a[1];
    double *x;
    x = (double*) calloc(row*col + 2, sizeof(double));

    x[0] = a[0];
    x[1] = a[1];
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            x[(int)(i*col + j + 2)] = a[(int)(i*col + j + 2)];
    }
    return x;
}
