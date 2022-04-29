#ifndef Point_H_
#define Point_H_

#include <iostream>
#include <cmath>
#include <limits>

template<class T>
struct Point {
  T x;
  T y;
};

template<class T>
Point<T> operator+(const Point<T>& A, const Point<T>& B) {
    Point<T> res;
    res.x = A.x + B.x;
    res.y = A.y + B.y;
    return res;
}

template<class T>
Point<T> operator/=(Point<T>& A, const double B) { //деление на число
    A.x /= B;
    A.y /= B;
    return A;
}

template<class T>
std::istream& operator>> (std::istream& is, Point<T>& p) {
  is >> p.x >> p.y;
  return is;
}

template<class T>
std::ostream& operator<< (std::ostream& os, const Point<T>& p) {
  os << '(' << p.x << ';' << p.y << ')' ;
  return os;
}

template <class T>
double triangle_height(Point<T> p1, Point<T> p2, Point<T> p3) {
    double A = p2.y - p3.y;
    double B = p3.x - p2.x;
    double C = p2.x*p3.y - p3.x*p2.y;
    return (std::abs(A*p1.x + B*p1.y + C) / std::sqrt(A*A + B*B));
}


#endif