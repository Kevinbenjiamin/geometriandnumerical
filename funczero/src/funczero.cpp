
#include "../include/Binary_SolveEquation.h"
#include "../include/Newton_SolveEquation.h"
#include "../include/GD_SolveEquation.h"
#include "../include/Golden_SolveEquation.h"
#include "../include/Quadratic_SolveEquation.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    //二分法
    cout << "Binary answer: "<<bisection(0.0,2.0)<<"----prove: "<<func(bisection(0.0,2.0)) <<endl;
    //一维牛顿
    cout<<"Newton answer: "<<Newton(0.5)<<"----prove: "<<func_nt(Newton(0.5)) <<endl;

    //梯度下降
    double a = 1.0,b = 2.0,c =-3.0;
    double x0 = -b/(2*a)-1;
    cout <<"GD: "<< GradientDescent(a, b, c, x0, 0.01)<< endl;

    //黄金分割搜索
    vector<double> res = golden_section_search(-3, 3, 20);
    cout <<"Golden search: "<<res[0]<<" "<< res[1]<<endl;

    //抛物线，二次多项式
    cout << "Quadratic: "<< quadratic_fit_search_2(-2, 2, 3, 50)<<endl;

    return 0;
    
}