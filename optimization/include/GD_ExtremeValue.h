

#ifndef GD_EXTREMEVALUE_H
#define GD_EXTREMEVALUE_H

#include <math.h>
#include <valarray>

/**
这里采用梯度下降法求解函数的极值
f(x) = x^2-4x

*/

#define GD_DELTA 1e-4
#define GD_EPS 1e-6


double gd_func(double x){
    return pow(x, 2)-4*x;
}


double gd_func_prime(double x){
    return (gd_func(x+GD_DELTA)-gd_func(x-GD_DELTA))/(2*GD_DELTA);
}

double gd_extreme(double x0, double learningrate){

    double x = x0;
    double x_last = 0.5;
    while(fabs(x-x_last)>GD_EPS){
        x_last = x;
        x = x_last -learningrate*gd_func_prime(x_last);
    }
    return x;
}


#endif // GD_EXTREMEVALUE_H
