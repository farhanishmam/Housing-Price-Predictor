#include<stdio.h>
#include<stdlib.h>
void print(double *a)
{
    double i, j;
    double row = a[0], col = a[1];

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            printf("%lf ", a[(int)(i*col + j + 2)]);
        printf("\n");
    }
}
int main()
{
    double i, j;
    double m[18] = {4, 4, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    print(m);
}

