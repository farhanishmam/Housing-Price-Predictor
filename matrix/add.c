#include<stdio.h>
#include<stdlib.h>
double *add(double *a, double *b)
{
    double i, j, row, col;
    double arow = a[0], acol = a[1], brow = b[0], bcol = b[1];

    if(arow != brow || acol != bcol)
    {
        printf("elementwise add error\n");
        exit(1);
    }
    else
    {
        row = arow;
        col = acol;
    }

    double *x;
    x = (double*) calloc(row*col + 2, sizeof(double));

    x[0] = row;
    x[1] = col;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            x[(int)(i*col + j + 2)] = a[(int)(i*col + j + 2)] + b[(int)(i*col + j + 2)];
    }
    return x;
}
int main()
{
    int i, j;
    int m[18] = {2, 2, 6, 9, 6, 9};
    int n[18] = {2, 2, 1, 2, 3, 4};

    int *p = add(m, n);
    int r = *p, c = *(p + 1);

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d ", p[i*c + j + 2]);
        printf("\n");
    }
}
