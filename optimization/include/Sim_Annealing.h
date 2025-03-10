


#ifndef SIM_ANNEALING_H
#define SIM_ANNEALING_H


#include <cstdlib>
#include <iostream>
#include <math.h>
#include <ostream>
#include <valarray>

#define SA_DELTA 1e-4
#define SA_EPS 1e-6

/*
 * 使用模拟退火求函数极值点
 */
 double sa_func(double x){
    /**
     * 构造函数
     * x:自变量
     * return：函数值
     */
    return x*x-4*x;
}

/**
*返回制定范围内的随机浮点数
*/
double rnd(double low, double high){
    double rd = rand()/((double)RAND_MAX+1.0);
    return low+rd*(high-low);
}


/**
     * T0:初始温度
     * T_min:温度的下限，若温度T达到T_min，则停止搜索
     * x0:初始迭代值
     * gamma:T_{k+1} = gamma * T_k, 0<gamma<1
     * return:极值点
     */
double Annealing(double T0, double T_min, double x0, double gramma){
    double T = T0;
    double x = x0;
    double x_ = 2;
    double delta_y = 1.0;
    while(fabs(delta_y)>SA_EPS){//如果函数值满足精度，停止搜索
        // while(T>T_min){//温度T达到T_min，则停止搜索
        double x_ = x+rnd(-1, 1);
        //std::cout << x_ << std::endl;
        delta_y = sa_func(x_)-sa_func(x);
        if(delta_y<=0){
            x = x_;
        }
        else{
            if(exp(-delta_y/T)>rnd(0, 1)){
                x = x_;
            }
        }
        T = gramma*T;
        //std::cout << x<<std::endl;
    }
    return x;


}



#endif // SIM_ANNEALING_H