#ifndef FIGURE_H
#define FIGURE_H 1

#include "point.h"
#include <iostream>

class Figure {
public:
	virtual Point Center() const = 0;
	virtual double Area() const = 0;
	virtual std::ostream &Print(std::ostream &out) const = 0; 
	virtual std::istream &Scan(std::istream &in) = 0;
	virtual ~Figure() = default;
};

std::ostream &operator<<(std::ostream &out, const Figure &fig);
std::istream &operator>>(std::istream &in, Figure &fig);

#endif //FIGURE_H