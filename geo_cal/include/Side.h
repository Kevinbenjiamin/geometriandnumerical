#ifndef SIDE_H
#define SIDE_H

#include<cmath>

#include "Geometry.h"
#include "utils.h"
#include <cassert>


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


#endif // SIDE_H