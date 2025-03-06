#ifndef SIDE_H
#define SIDE_H

#include<cmath>

#include "Geometry.h"
#include "utils.h"
#include <cassert>
#include <stdexcept>


enum class Side{
    // When the segment's length is zero, it's useless to determine the side, so we use DEFAULT_NO_SIDE to show.
    DEFAULT_NO_SIDE=0,
    LEFT,
    RIGHT,
    // The three below states mean that the point is in line.
    ON_AFTER,
    ON_BEFORE,
    WITHIN
};


// Determine which side of the segment the point is.
Side GetSide(const Point& p,const Segment& s){
    const auto& p0 = s.start;
    const auto& p2 = s.end;
    const auto& a = p-p0;
    const auto& b = p2-p0;
    const auto cross_product = CrossProduct(a,b);
    if(cross_product!=0){
        // Returns LEFT if p0,p,p2 are clockwise position, returns RIGHT means p0,p,p2 are counter-clockwise position.
        return cross_product<0?Side::LEFT:Side::RIGHT;
    }
    const auto dot_product = DotProduct(a,b);
    if(dot_product<0){
        return Side::ON_BEFORE;
    }else if(dot_product>0){
        if(b.modulus()<a.modulus()){
            return Side::ON_AFTER;
        }else{
            return Side::WITHIN;
        }
    }else{
        if(a.modulus()==0){
            return Side::WITHIN;
        }
        return Side::DEFAULT_NO_SIDE;
    }
}

// Determine which side of two segments the point is.
// Method 2: through the side of p to one segment to determine, and except left/right side, we also provide other options.
Side GetSide(const Point &p, const Segment &s1, const Segment &s2){
    //判断是否线段相连
    if(s1.end!=s2.start){
        throw std::runtime_error("Error:the two segments are not connect.");
    }
    const auto side_1 = GetSide(p,s1);
    const auto side_2 = GetSide(p,s1);
    if(side_1==side_2){
        return side_1;
    }
    if(side_1==Side::WITHIN || side_2==Side::WITHIN){
        return Side::WITHIN;
    }
    //工程方法，通过向量间叉乘判断是在左边还是右边
    const auto &p0p = p-s1.start;
    const auto &p1p = p-s2.start;
    const auto c1 = CrossProduct(s1.direction, p0p);
    const auto c2 = CrossProduct(s2.direction, p1p);
    return std::abs(c2)>std::abs(c1)?side_2:side_1;


}



#endif // SIDE_H