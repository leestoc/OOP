#ifndef D_HEXAGON_H
#define D_HEXAGON_H

#include <iostream>
#include <cmath>
#include "point.h"



template<class T>
struct hexagon {
  Point<T> p[6];  
  hexagon(std::istream& is);
  double area() const;
  Point<T> center() const;
  void print(std::ostream& os) const;
};



template<class T>
double hexagon<T>::area() const {
    return (-0.5) * ((p[0].x*p[1].y + p[1].x*p[2].y + p[2].x*p[3].y + p[3].x*p[4].y + p[4].x*p[5].y + p[5].x*p[0].y) - ( p[0].y*p[1].x + p[1].y*p[2].x + p[2].y*p[3].x + p[3].y*p[4].x + p[4].y*p[5].x + p[5].y*p[0].x ));
	
}


template<class T>
Point<T> hexagon<T>::center() const {
      Point<T> res;
  res.x = (p[0].x + p[1].x + p[2].x + p[3].x + p[4].x + p[5].x) / 6;
  res.y = (p[0].y + p[1].y + p[2].y + p[3].y + p[4].y + p[5].y) / 6;
  return res;
}



template<class T>
void hexagon<T>::print(std::ostream& os) const{
	for(int i = 0; i < 6; ++i){
      os << p[i];
    if(i + 1 != 6){
      os << ' ';
    }
  }
}



template<class T>
hexagon<T>::hexagon(std::istream& is) {
	for(int i = 0; i < 6; ++i){
    is >> p[i];
  }
}

#endif