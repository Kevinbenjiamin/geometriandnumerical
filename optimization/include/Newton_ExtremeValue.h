

#ifndef NEWTON_EXTREMEVALUE_H
#define NEWTON_EXTREMEVALUE_H

#include <valarray>
#include <math.h>

#define NE_DELTA 1e-4
#define NE_EPS 1e-6
/*
 * 使用牛顿法求函数极值点
 */
double nt_func(double x){
    /**
     * 构造函数
     * x:自变量
     * return：函数值
     */
    return x*x-4*x;
}

double nt_func_prime(double x){
    /**
     * 计算函数导数,以导数定义的方式求解
     */
    return (nt_func(x+NE_DELTA)-nt_func(x-NE_DELTA))/(2*NE_DELTA);
}
double nt_func_prime_prime(double x){
    /**
     * 计算函数二阶导,以导数定义的方式求解
     */
    return (nt_func_prime(x+NE_DELTA)-nt_func_prime(x-NE_DELTA))/(2*NE_DELTA);
}


double Newton(double x0){
    double x = x0;
    double x_last=0.1;
    while(fabs(x-x_last)>NE_EPS){
        x_last=x;
        x=x_last-nt_func_prime(x_last)/ nt_func_prime_prime(x_last);
    }
    return x;
}




#endif // NEWTON_EXTREMEVALUE_H