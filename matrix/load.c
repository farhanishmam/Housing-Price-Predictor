#include<stdio.h>
#include<stdlib.h>
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
int main()
{
    int i, j, *p = load("data.txt", 2);

    for(i = 0; i < p[0]; i++)
    {
        for(j = 0; j < p[1]; j++)
            printf("%d ", p[i*p[1] + j + 2]);
        printf("\n");
    }
}
