#include<stdio.h>
#include<stdlib.h>
int *assign(int *a)
{
    int i, j;
    int row = a[0], col = a[1];
    int *x;
    x = (int*) calloc(row*col + 2, sizeof(int));

    x[0] = a[0];
    x[1] = a[1];
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            x[i*col + j + 2] = a[i*col + j + 2];
    }
    return x;
}
int main()
{
    int i, j;
    int m[18] = {4, 4, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    int *p = assign(m);
    int r = *(p + 0), c = *(p + 1);

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d ", p[i*c + j + 2]);
        printf("\n");
    }
}

