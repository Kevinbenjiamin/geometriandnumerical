#ifndef BINARY_SOLVEEQUATION_H
#define BINARY_SOLVEEQUATION_H


#include <valarray>
#include <iostream>
#define EPS 1e-6

/**

使用二分法求解方程的根
np.log(x)+x^2=0
*/

double func(double x){
    return log(x)+x*x;
}

double bisection(double a,double b){
    if(a>b){
        std::swap(a,b);
    }
    double y_a = func(a);
    double y_b = func(b);
    if(y_a==0){
        b=a;
        return a;
    }
    else if(y_b==0){
        a=b;
        return a;
    }
    while(b-a>EPS){
        double x = a + (b-a)/2;
        double y = func(x);
        if(y==0){
            a = x;
            b = x;
            break;
        }
        if(y*y_a<=0){
            //在a与x间
            b = x;
        }
        else {
            //在y与b间
            a = x;
        }

    }
    return a;
}

#endif // BINARY_SOLVEEQUATION_H