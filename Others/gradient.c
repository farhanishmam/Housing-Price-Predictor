#include<stdio.h>
#include<stdlib.h>
#include "matrix.h"
double *gradient(double *X, double *y, double *theta, double alpha, double num_iters)
{
    double iter, m = X[0];;

    double *hTheta = (double*) calloc(X[0] * theta[1] + 2, sizeof(double));
    hTheta[0] = X[0];
    hTheta[1] = theta[1];

    double J;

    double *grad = (double*) calloc(theta[0] * 1 + 2, sizeof(double));
    grad[0] = theta[0];
    grad[1] = theta[1];

    for(iter = 1; iter <= num_iters; iter++)
    {
        hTheta = multiply(X, theta);
        J = multiply_scalar(multiply(trans(subtract(hTheta, y)), subtract(hTheta, y)) , 1/(2*m));

        printf("Printing J\n");
        for(i = 0; i < J[0]; i++)
        {
            for(j = 0; j < J[1]; j++)
                printf("%lf ", J[(int)(i*J[1] + j + 2)]);
            printf("\n");
        }

        grad = multiply_scalar(multiply(trans(X), subtract(hTheta, y)), 1/m);

        theta = subtract(theta, multiply_scalar(grad, alpha));
    }

    return theta;
}

int main()
{

}
