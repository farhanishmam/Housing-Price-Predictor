double cost(double *X, double *y, double *theta)
{
    double m = y[0];

    double *hTheta = multiply(X, theta);
    double *s, total;

    s = multiply_elwise(subtract(hTheta, y), subtract(hTheta, y));
    total = sum(s);
    return total/(2*m);
}

double *gradient(double *X, double *y, double *theta, double alpha, double num_iters)
{
    double i, j, iter, m = X[0];;

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
        J = cost(X, y, theta);

        grad = multiply_scalar(multiply(trans(X), subtract(hTheta, y)), 1/m);

        theta = subtract(theta, multiply_scalar(grad, alpha));
    }

    return theta;
}
