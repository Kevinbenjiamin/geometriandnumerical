
#include "../include/Binary_SolveEquation.h"
#include "../include/Newton_SolveEquation.h"
#include "../include/GD_SolveEquation.h"
#include <iostream>

using namespace std;

int main(){
    //二分法
    cout << "answer: "<<bisection(0.0,2.0)<<"----prove: "<<func(bisection(0.0,2.0)) <<endl;
    //一维牛顿
    cout<<"answer: "<<Newton(0.5)<<"----prove: "<<func_nt(Newton(0.5)) <<endl;

    //梯度下降
    double a = 1.0,b = 2.0,c =-3.0;
    double x0 = -b/(2*a)-1;
    cout << GradientDescent(a, b, c, x0, 0.01)<< endl;

    return 0;
    
}