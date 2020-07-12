#include<stdio.h>
#include<stdlib.h>
double sum(double *a)
{
    double i, j, total = 0, col = a[1];
    for(i = 0; i < a[0]; i++)
    {
        for(j = 0; j < a[1]; j++)
            total += a[(int)(i*col + j + 2)];
    }
    return total;
}

int main()
{
    double X[10] = {4, 2, 1, 2, 3, 4, 5, 6, 7, 8};
    double i, j, r = X[0], c= X[1];
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%lf ", X[(int)(i*c + j + 2)]);
        printf("\n");
    }

    printf("\n%lf", sum(X));
}
