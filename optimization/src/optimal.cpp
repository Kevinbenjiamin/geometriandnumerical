
#include <iostream>
#include "../include/GD_ExtremeValue.h"
#include "../include/Newton_ExtremeValue.h"
#include "../include/Sim_Annealing.h"

using namespace std;


int main(){

    //梯度下降求最值
    cout << "GD: "<< gd_extreme(0, 0.01) << endl;

    //牛顿法求最值
    cout << "Newton: " << Newton(1) << endl;

    //模拟退火
    double T0=200,T_min = 1,x0=2,gamma=0.9;
    cout<<"extreme  value: "<<Annealing(T0,T_min,x0,gamma)<<endl;

    return 0;

}

