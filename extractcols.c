#include<stdio.h>
#include<stdlib.h>

int *extractcols(int *a, int start, int end)
{
    int i, j, row, col;

    row = a[0];
    col = a[1];

    if(start < 1 || end > row || end < start)
    {
        printf("extractcols error\n");
        exit(1);
    }

    int *x = (int*) calloc((end - start + 1)*row + 2, sizeof(int));

    x[0] = row;
    x[1] = end - start + 1;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < end - start + 1; j++)
            x[i*(end - start + 1) + j + 2] = a[i*col + (start + j - 1) + 2];
    }

    return x;
}

int main()
{
    int i, j, z[18] = {4, 4, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int *p = extractcols(z, 1, 2);

    for(i = 0; i < p[0]; i++)
    {
        for(j = 0; j < p[1]; j++)
            printf("%d ", p[i*p[1] + j + 2]);
        printf("\n");
    }

}

