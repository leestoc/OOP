#ifndef POINT_H
#define POINT_H 1

#include <iostream>

class Point {
	double x;
	double y;
public:
	Point();
	Point(double a, double b);
	Point(const Point &other);
	double X() const;
	double Y() const;
	Point operator+(const Point &a) const;
	Point operator-(const Point &a) const;
	Point operator*(double a) const;
	Point operator/(double a) const;
	friend std::ostream &operator<<(std::ostream &out, const Point &a);
	friend std::istream &operator>>(std::istream &in, Point &a);
};

#endif // POINT_H