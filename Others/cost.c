double cost(double *X, double *y, double *theta)
{
    double m = y[0];

    double *hTheta = multiply(X, theta);
    double *s, total;

    s = multiply_elwise(subtract(hTheta, y), subtract(hTheta, y));
    total = sum(s);
    return total/(2*m);
}
