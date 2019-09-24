#include<stdio.h>
#include<stdlib.h>
int *multiply(int *a, int *b)
{
    int i, j, row, col;
    int arow = a[0], acol = a[1], brow = b[0], bcol = b[1];

    if(acol != brow)
    {
        printf("matrix multiplying error\n");
        exit(1);
    }
    else
    {
        row = arow;
        col = bcol;
    }

    int *x;
    x = (int*) calloc(row*col + 2, sizeof(int));

    x[0] = row;
    x[1] = col;
    int p, q, temp;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            for(p = 0; p < acol; p++)
                x[i*col + j + 2] += a[i*acol + p + 2] * b[p*bcol + j + 2];
        }
    }
    return x;
}
int main()
{
    int i, j;
    int m[18] = {2, 2, 6, 9, 6, 9};
    int n[18] = {2, 2, 1, 2, 3, 4};

    int *p = multiply(m, n);
    int r = *p, c = *(p + 1);

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d ", p[i*c + j + 2]);
        printf("\n");
    }
}

