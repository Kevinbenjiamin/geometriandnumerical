#ifndef DISTANCE_H
#define DISTANCE_H

#include "Geometry.h"
#include "utils.h"

// Get distance between point p1 and point p2.
double GetDistance(const Point& p1,  const Point& p2){
    return p1.DistanceTo(p2);
}

// Get distance between point p and a straight line.
double GetDistance(const Point& p, const Line& line){
    Segment p1p2(line.p1,line.p2);
    Segment p1p(line.p1,p);
    return std::abs(CrossProduct(p1p2.direction,p1p.direction))/p1p2.length();
}

// Get distance between point p and segment(p1,p2).
double GetDistance(const Point& p, const Segment& segment){
    Segment p1p(segment.start,p);
    Segment p2p(segment.end,p);
    const auto c1 = DotProduct(p1p.direction,segment.direction);
    const auto c2 = DotProduct(p2p.direction,segment.direction);
    if(c1<=0){
        //distance(p,segment)=distacne(p1,p).
        return GetDistance(segment.start,p);
    }
    if(c2>=0){
        //distance(p,segment)=distacne(p2,p).
        return GetDistance(segment.end,p);
    }
    return std::abs(CrossProduct(segment.direction,p1p.direction))/segment.length();
}

// Get distance between segment and segment (method 1), method 2 is to be determined.
double GetDistance(const Segment& s1,const Segment& s2){
    const double d1 = GetDistance(s1.start, s2);
    const double d2 = GetDistance(s1.end, s2);
    const double d3 = GetDistance(s2.start, s1);
    const double d4 = GetDistance(s2.end, s1);
    return std::min(std::min(d1, d2), std::min(d3, d4));
}

#endif // DISTANCE_H