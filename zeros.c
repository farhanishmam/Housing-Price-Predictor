#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>

int *zeros(int row, int col)
{
    int i, j;

    int *x = (int *) calloc(row*col + 2, sizeof(int));
    x[0] = row;
    x[1] = col;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            x[i*col + j + 2] = 0;
    }

    return x;
}

int main()
{
    int i, j, *p = zeros(5, 2);

    for(i = 0; i < p[0]; i++)
    {
        for(j = 0; j < p[1]; j++)
            printf("%d ", p[i*p[1] + j + 2]);
        printf("\n");
    }
}

