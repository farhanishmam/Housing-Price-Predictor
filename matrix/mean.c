#include<stdio.h>
#include<stdlib.h>

double *mean(double *a)
{
    double i, j, r = a[0], c = a[1], m;

    double *x;
    x = (double*) calloc(c + 2, sizeof(double));

    x[0] = 1;
    x[1] = c;

    for(j = 0; j < c; j++)
    {
        m = 0;
        for(i = 0; i < r; i++)
            m += a[(int)(i*c + j + 2)];
        x[(int)(j + 2)] = m/r;
    }

    return x;
}

int main()
{
    double X[10] = {4, 2, 1, 2, 3, 4, 5, 6, 7, 8};
    double *p = mean(X);

    double i, j, r = p[0], c= p[1];
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%lf ", p[(int)(i*c + j + 2)]);
        printf("\n");
    }
}
