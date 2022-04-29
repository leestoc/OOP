#include "triangle.h"
#include "figure.h"
#include "point.h"
#include "vector.h"
#include <cmath>

Triangle::Triangle() : A{Point{}}, B{Point{}}, C{Point{}} {}

Triangle::Triangle(Point a, Point b, Point c) : A{a}, B{b}, C{c} {
	double AB = Length(A, B), BC = Length(B, C), AC = Length(A, C);
	if (AB >= BC + AC || BC >= AB + AC || AC >= AB + BC) {
		throw std::logic_error("Points must not be on the same line.");
	}
}

Point Triangle::Center() const {
	Point mid_of_base{ (A + C) / 2 };

	return { (B + mid_of_base * 2) / 3 };
}

double Triangle::Area() const {
	double AB = Length(A, B), BC = Length(B, C), AC = Length(A, C);
	double perim = AB + BC + AC; 

	return sqrt((perim / 2) * (perim / 2 - AB) * (perim / 2 - BC) * (perim / 2 - AC));
}

std::ostream &Triangle::Print(std::ostream &out) const {
	out << "Triangle: p1 = " << A << ", p2 = " << B << ", p3 = " << C;

	return out;
}

std::istream &Triangle::Scan(std::istream &in) {
	in >> A >> B >> C;
	(*this) = Triangle(A, B, C);

	return in;
}