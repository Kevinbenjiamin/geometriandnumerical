/**
create by kevinzzx on 2025.3.1
*/

#ifndef GEOMETRY_H
#define GEOMETRY_H


#include<iostream>
#include <vector>
#include <cmath>

//点结构定义
struct Point{
    Point()=default;
    Point(double x_in,double y_in): x(x_in), y(y_in){}
    Point(const Point& p): x(p.x),y(p.y){}

    //下面重载运算符，防止冗余，方便点间的计算。
    Point& operator=(const Point& p){
        x = p.x;
        y = p.y;
        return *this;
    }
    //const 在这里表明是一个常量成员函数（即只读函数）
    Point operator+(const Point& p) const {
        return {x + p.x, y + p.y};
    }
    Point operator-(const Point& p) const {
        return {x - p.x, y - p.y};
    }
    Point operator*(const Point& p) const {
        return {x * p.x, y * p.y};
    }
    Point operator*(double k) const {
        return {x*k, y*k};
    }
    friend Point operator*(double k, const Point& p){
        return {p.x*k, p.y*k};
    }
    bool operator==(const Point& p)const{
        return p.x==x&&p.y==y;
    }
    bool operator!=(const Point& p)const{
        return !(p.x==x&&p.y==y);
    }

    //计算
    double modulus()const {
        return sqrt(x * x + y * y);
    }

    double DistanceTo(const Point& other)const{
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx*dx+dy*dy);
    }
    friend std::ostream& operator<<(std::ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }

    double x;
    double y;

};



//定义直线
struct Line{
    Line()=default;
    Line(Point p1_in, Point p2_in): p1(p1_in), p2(p2_in), direction(p2_in-p1_in){}

    friend std::ostream& operator<<(std::ostream& out, const Line& line) {
        out << "Line: " << line.p1 << " ---> " << line.p2;
        return out;
    }
    Point p1;
    Point p2;
    Point direction;
};


//定义线段
struct Segment{
    Segment()=default;
    Segment(Point start_in, Point end_in) : start(start_in), end(end_in),direction(end-start) {
    }
    Segment(const Segment& s):start(s.start), end(s.end), direction(end- start){}

    Segment& operator=(const Segment& s) {
        start = s.start;
        end = s.end;
        return *this;
    }
    Segment operator+(const Segment& rhs)const {
        return {start + rhs.start, end + rhs.end};
    }
    Segment operator-(const Segment& rhs)const {
        return {start - rhs.start, end - rhs.end};
    }

    double length() const{
        return direction.modulus();
    }
    Point unit_direction() const{
        double len = length();
        if (len != 0) {
            return {direction.x / len, direction.y / len};
        } else {
            // Handle the case where the length is zero (avoid division by zero).
            throw std::runtime_error("Cannot calculate unit direction for a segment with zero length.");
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Segment& s) {
        out << "Segment: " << s.start << " ---> " << s.end;
        return out;
    }

    Point start;
    Point end;
    Point direction;
};


//定义折线
struct Polyline{
    
    Polyline()=default;

    Polyline(const std::vector<Point>& pts):points(pts){
        for(int i=0;i<points.size();i++){
            segs.push_back(Segment(points[i-1],points[i]));
        }
    }
    Polyline(const std::vector<Segment>& segs_): segs(segs_){
        for(int i = 0;i<segs.size();++i){
            points.push_back(segs[i].start);
        }
        points.push_back(segs[segs.size()-1].end);
    }

    void append(const Segment& seg) {
        if(!segs.empty() && segs.back().end != seg.start) {
            throw std::invalid_argument("Disconnected Segment");
        }
        segs.push_back(seg);
        points.push_back(seg.end);
    }
    void append(const Point& p) {
        const auto seg = Segment(points.back(),p);
        points.push_back(p);
        segs.push_back(seg);
    }

    Polyline operator+(const Polyline& other) const {
        Polyline result;
        result.segs = this->segs;
        result.points = this->points;
        for(auto& seg : other.segs) {
            result.append(seg);
        }

        return result;
    }

    Segment GetSegmentByIndex(int index) {
        if(index < 0 || index >= segs.size()) {
            throw std::out_of_range("Index out of range");
        }
        return segs[index];
    }
    std::vector<Point> Points() const{
        return points;
    }
    std::vector<Segment> Segments()const{
        return segs;
    }
private:
    std::vector<Segment> segs;
    std::vector<Point> points;

};


#endif // GEOMETRY_H