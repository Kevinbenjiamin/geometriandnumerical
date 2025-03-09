#ifndef QUADRATIC_SOLVEEQUATION_H
#define QUADRATIC_SOLVEEQUATION_H

#include<iostream>
#include <valarray>

/*
 * 使用抛物线法求解 x*x-5的最小值点(二次多项式)
 */


 double quad_func(double x){
     /**
      * 构造函数
      * x:自变量
      * return：函数值
      */
 //    return pow(x*x-5,2);
     return x*x-5;
 }
 
 double quadratic_fit_search(double a,double b,double c,int n){
     /**
      * 抛物线法；
      * 区间(a,b)；
      * a<c<b
      * n: 迭代次数
      */
     while(n--){
         double beta_1 = 1/(b-a)*((quad_func(b)-quad_func(c))/(b-c)-(quad_func(c)- quad_func(a))/(c-a));
         double beta_2 = (quad_func(c)-quad_func(a))/(c-a)-beta_2*(c+a);
          double x = -beta_1/(2*beta_2);
          if(x<c){
              b=c;
              c=x;
          }else{
              a=c;
              c=x;
          }
      }
      return c;
 }
 
 double quadratic_fit_search_2(double a,double b,double c,int n){
     /**
      * 抛物线法；
      * 区间(a,c)；
      * a<b<c
      * n: 迭代次数
      * return: 最小值点
      */
     while(n--){
         double y_a=quad_func(a),y_b=quad_func(b),y_c=quad_func(c);
         double x = 0.5*(y_a*(b*b-c*c)+y_b*(c*c-a*a)+y_c*(a*a-b*b))/(y_a*(b-c)+y_b*(c-a)+y_c*(a-b));
         double y_x = quad_func(x);
         if(x>b){
              if(y_x>y_b){   //用 a < b < x 作为新的起点
                  c=x;
              }else{     //用 b < x < c作为新的起点
                  a=b;
                  b=x;
              }
         }else if(x<b){
              if(y_x>y_b){   //用 x < b < c作为新的起点
                  a=x;
              }else{     //用 a < x < b作为新的起点
                  c=b;
                  b=x;
              }
         }
 
      }
     return b;
 
 }


#endif // QUADRATIC_SOLVEEQUATION_H