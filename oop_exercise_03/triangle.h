#ifndef TRIANGLE_H
#define TRIANGLE_H 1

#include "point.h"
#include "figure.h"
#include "vector.h"

class Triangle : public Figure {
	Point A, B, C;
public:
	Triangle();
	Triangle(Point a, Point b, Point c);
	Point Center() const override;
	double Area() const override;
	std::ostream &Print(std::ostream &out) const override; 
	std::istream &Scan(std::istream &in) override;
};

#endif //TRIANGLE_H