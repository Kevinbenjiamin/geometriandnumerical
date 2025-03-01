/**
create by kevinzzx on 2025.3.1
*/

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

