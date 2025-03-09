
#ifndef NEWTON_SOLVEEQUATION_H
#define NEWTON_SOLVEEQUATION_H


#include <cmath>
#include <iostream>
#include <math.h>
#include <valarray>

#define DELTA 1e-4
#define NT_EP 1e-6

/**
使用牛顿法求解方程的根
*/
double func_nt(double x){
    return log(x)+x*x;
}

double func_prime(double x){
    return (func_nt(x+DELTA)-func_nt(x-DELTA))/(2*DELTA);
}


double Newton(double x0){
    double x = x0;
    double x_last = 0.1;
    while(abs(x-x_last)>NT_EP){
        
        x_last = x;
        x = x_last - func_nt(x_last)/func_prime(x_last);
    }
    return x;

}

#endif // NEWTON_SOLVEEQUATION_H