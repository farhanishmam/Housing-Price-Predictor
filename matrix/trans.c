#include<stdio.h>
#include<stdlib.h>

double *trans(double *a)
{
    double i, j, r = a[0], c = a[1], temp;

    double *x;
    x = (double*) calloc(r*c + 2, sizeof(double));

    x[0] = c;
    x[1] = r;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            x[(int)(j*r + i + 2)] = a[(int)(i*c + j + 2)];
    }
    return x;
}

int main()
{
    double X[10] = {4, 2, 1, 2, 3, 4, 5, 6, 7, 8};
    double *p = trans(X);

    double i, j, r = p[0], c= p[1];
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%lf ", p[(int)(i*c + j + 2)]);
        printf("\n");
    }
}
