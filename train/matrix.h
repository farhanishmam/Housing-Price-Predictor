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

double *addcols(double *a, double *b)
{
    double i, j, row, col;
    if(a[0] != b[0])
    {
        printf("addcols error\n");
        exit(1);
    }

    row = a[0];
    col = a[1] + b[1];

    double *x = (double*) calloc(row*col + 2, sizeof(double));

    x[0] = row;
    x[1] = col;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < a[1]; j++)
            x[(int)(i*col + j + 2)] = a[(int)(i*a[1] + j + 2)];
    }

    for(i = 0; i < row; i++)
    {
        for(j = a[1]; j < col; j++)
            x[(int)(i*col + j + 2)] = b[(int)(i*b[1] + (j - a[1]) + 2)];
    }

    return x;
}

double *addrows(double *a, double *b)
{
    double i, j, row, col;
    if(a[1] != b[1])
    {
        printf("addrows error\n");
        exit(1);
    }

    row = a[0] + b[0];
    col = a[1];

    double *x = (double*) calloc(row*col + 2, sizeof(double));

    x[0] = row;
    x[1] = col;

    for(i = 0; i < a[0]; i++)
    {
        for(j = 0; j < col; j++)
            x[(int)(i*col + j + 2)] = a[(int)(i*col + j + 2)];
    }

    for(i = a[0]; i < row; i++)
    {
        for(j = 0; j < col; j++)
            x[(int)(i*col + j + 2)] = b[(int)((i - a[0])*col + j + 2)];
    }

    return x;
}

double *assign(double *a)
{
    double i, j;
    double row = a[0], col = a[1];
    double *x;
    x = (double*) calloc(row*col + 2, sizeof(double));

    x[0] = a[0];
    x[1] = a[1];
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            x[(int)(i*col + j + 2)] = a[(int)(i*col + j + 2)];
    }
    return x;
}

double *extractcols(double *a, double start, double end)
{
    double i, j, row, col;

    row = a[0];
    col = a[1];

    if(start < 1 || end > row || end < start)
    {
        printf("extractcols error\n");
        exit(1);
    }

    double *x = (double*) calloc((end - start + 1)*row + 2, sizeof(double));

    x[0] = row;
    x[1] = end - start + 1;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < end - start + 1; j++)
            x[(int)(i*(end - start + 1) + j + 2)] = a[(int)(i*col + (start + j - 1) + 2)];
    }

    return x;
}

double *extractrows(double *a, double start, double end)
{
    double i, j, row, col;

    row = a[0];
    col = a[1];

    if(start < 1 || end > row || end < start)
    {
        printf("extractrows error\n");
        exit(1);
    }

    double *x = (double*) calloc((end - start + 1)*col + 2, sizeof(double));

    x[0] = end - start + 1;
    x[1] = col;

    for(i = 0; i < end - start + 1; i++)
    {
        for(j = 0; j < col; j++)
            x[(int)(i*col + j + 2)] = a[(int)((i + start - 1)*col + j + 2)];
    }

    return x;
}

double *load(char *s, double features)
{
    FILE *f = fopen(s, "r");

    if(f == NULL)
    {
        printf("file reading error\n");
        exit(1);
    }

    double i, j, a, *x;
    x = (double*)calloc(1000*10, sizeof(double));

    i = 0;
    features++;
    while(!feof(f))
    {
        for(j = 0; j < features; j++)
        {
            fscanf(f, "%lf", &a);
            x[(int)(features*i + j + 2)] = a;
        }
        i++;
    }

    x[0] = i;
    x[1] = features;

    fclose(f);

    return x;
}

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

double *multiply_scalar(double *a, double b)
{
    double i, j;
    double row = a[0], col = a[1];

    double *x;
    x = (double*) calloc(row*col + 2, sizeof(double));

    x[0] = row;
    x[1] = col;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            x[(int)(i*col + j + 2)] = a[(int)(i*col + j + 2)] * b;
    }
    return x;
}

double *multiply(double *a, double *b)
{
    double i, j, row, col;
    double arow = a[0], acol = a[1], brow = b[0], bcol = b[1];

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

    double *x;
    x = (double*) calloc(row*col + 2, sizeof(double));

    x[0] = row;
    x[1] = col;
    double p, q, temp;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            for(p = 0; p < acol; p++)
                x[(int)(i*col + j + 2)] += a[(int)(i*acol + p + 2)] * b[(int)(p*bcol + j + 2)];
        }
    }
    return x;
}

double *multiply_elwise(double *a, double *b)
{
    double i, j, row, col;
    double arow = a[0], acol = a[1], brow = b[0], bcol = b[1];

    if(arow != brow || acol != bcol)
    {
        printf("elementwise multiply error\n");
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
            x[(int)(i*col + j + 2)] = a[(int)(i*col + j + 2)] * b[(int)(i*col + j + 2)];
    }
    return x;
}

double *ones(double row, double col)
{
    double i, j;

    double *x = (double *) calloc(row*col + 2, sizeof(double));
    x[0] = row;
    x[1] = col;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            x[(int)(i*col + j + 2)] = 1;
    }

    return x;
}

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

double *subtract(double *a, double *b)
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
            x[(int)(i*col + j + 2)] = a[(int)(i*col + j + 2)] - b[(int)(i*col + j + 2)];
    }
    return x;
}

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

double *zeros(double row, double col)
{
    double i, j;

    double *x = (double *) calloc(row*col + 2, sizeof(double));
    x[0] = row;
    x[1] = col;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            x[(int)(i*col + j + 2)] = 0;
    }

    return x;
}
