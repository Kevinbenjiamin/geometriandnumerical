#ifndef GOLDEN_SOLVEEQUATION_H
#define GOLDEN_SOLVEEQUATION_H

#include <cmath>
#include <valarray>
#include <iostream>
#include <vector>

#define GOD_EPS 1e-6


/**
使用黄金分割法求解迭代n次后的含最小值区间：f(x) = x^2-5
具有线性收敛速度
*/


double god_func(double x){
    return pow(x,2)-5;
}


std::vector<double> golden_section_search(double a, double b, double n){
    /**
    含最小值区间[a,b]
    n：迭代次数
    */
    double rho = (std::sqrt(5)-1)/2; //0.618 point
    double c = rho*a+(1-rho)*b;// (a,b) near a point
    double d = rho*b+(1-rho)*a;//(a,b) near b point
    while(n--){
        if(god_func(c)>god_func(d)){
            //这时(c, b)是含最小值区间, d是(c, b)的中靠近c的黄金分割点, 仍用a, b表示含最小值区间，c表示靠近a的黄金分割点
            a=c;
            c=d;
            d= rho*b+(1-rho)*a;//(a,b)中靠近b的黄金分割点
        }
        else{
            //这时(a, d)是含最小值区间,c是区间(a,d)的靠近d的黄金分割点,仍用a, b表示含最小值区间，d表示靠近b的黄金分割点
            b=d;
            d=c;
            c=rho*a+(1-rho)*b;
        }
    }
    return {a,b};
}

#endif // GOLDEN_SOLVEEQUATION_H