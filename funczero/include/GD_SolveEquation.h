#ifndef GD_SOLVEEQUATION_H
#define GD_SOLVEEQUATION_H


#include <iostream>
#include <valarray>

#define GDDELTA 1e-4
#define GD_EPS 1e-6

/**
使用梯度下降法求解方程的根

*/
double gd_func(double a,double b,double c,double x){
    return a*pow(x,2)+b*x+c;
}

double gd_loss_func(double a,double b,double c,double x){
    return pow(gd_func(a, b, c, x)-0,2);
}
//导数
double gd_loss_func_prime(double a,double b,double c,double x){
    return (gd_loss_func(a,b,c,x+GDDELTA)-gd_loss_func(a,b,c,x))/GDDELTA;
}

double GradientDescent(double a,double b,double c,double x0,double leaningrate){
    double x = x0;
    while(abs(gd_loss_func(a, b, c, x))>GD_EPS){
        x = x - leaningrate*gd_loss_func_prime(a, b, c, x);
    }
    return x;
}


#endif // GD_SOLVEEQUATION_H

