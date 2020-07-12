#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "matrix.h"

double *std(double *a)
{
    double i, j, r = a[0], c = a[1], s;

    double *x, *m;
    x = (double*) calloc(c + 2, sizeof(double));

    x[0] = 1;
    x[1] = c;

    m = mean(a);

    for(j = 0; j < c; j++)
    {
        s = 0;
        for(i = 0; i < r; i++)
            s +=   (a[(int)(i*c + j + 2)] - m[(int)(j + 2)])   *   (a[(int)(i*c + j + 2)] - m[(int)(j + 2)]);
        x[(int)(j + 2)] = sqrt(s/r);
    }

    return x;
}



int main()
{
    double X[10] = {4, 2, 1, 2, 3, 4, 5, 6, 7, 8};
    double *p = std(X);

    double i, j, r = p[0], c= p[1];
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%lf ", p[(int)(i*c + j + 2)]);
        printf("\n");
    }
}

