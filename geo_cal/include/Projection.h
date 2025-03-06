

#ifndef PROJECTION_H
#define PROJECTION_H


#include "Geometry.h"
#include "utils.h"

//计算点到线段的投影长度
double ComputeProjectionLength(const Point& p, const Segment& segment){
    const auto& p1p = p-segment.start;
    return DotProduct(p1p, segment.unit_direction());
}

//计算点到线段的投影点
Point ComputeProjection(const Point& p, const Segment& segment){
    double projection_length = ComputeProjectionLength(p, segment);
    return segment.start + segment.unit_direction()*projection_length;
}


#endif // PROJECTION_H
