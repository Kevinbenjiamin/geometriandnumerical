
#ifndef UTILS_H
#define UTILS_H


#include <vector>

#include "Geometry.h"

constexpr double Epsilon = 1e-6;

using Vec = Point;

//计算点积
double DotProduct(const Vec& v1, const Vec& v2){
    return v1.x*v2.x+v1.y*v2.y;
}

//计算叉积
double CrossProduct(const Vec& v1, const Vec& v2){
    return v1.x*v2.y-v2.x*v1.y;
}


//define a sign function
int Sign(double x){
    return x<0?-1:x>0?1:0;
}


#endif // UTILS_H