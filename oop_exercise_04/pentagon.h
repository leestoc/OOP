#ifndef PENTAGON_H_
#define PENTAGON_H_
#include <iostream>
#include <cmath>
#include "point.h"



template<class T>
struct pentagon {
  Point<T> p[5];  
  pentagon(std::istream& is);
  double area() const;
  Point<T> center() const;
  void print(std::ostream& os) const;
};



template<class T>
double pentagon<T>::area() const {
    const T d1 = triangle_height(p[0], p[1], p[2]) * sqrt((p[2].x - p[1].x) * (p[2].x - p[1].x) + (p[2].y - p[1].y) * (p[2].y - p[1].y)) / 2;
    const T d2 = triangle_height(p[0], p[2], p[3]) * sqrt((p[3].x - p[2].x) * (p[3].x - p[2].x) + (p[3].y - p[2].y) * (p[3].y - p[2].y)) / 2;
    const T d3 = triangle_height(p[0], p[3], p[4]) * sqrt((p[4].x - p[3].x) * (p[4].x - p[3].x) + (p[4].y - p[3].y) * (p[4].y - p[3].y)) / 2;
    return d1 + d2 + d3;
}


template<class T>
Point<T> pentagon<T>::center() const {
  Point<T> res;
  res.x = (p[0].x + p[1].x + p[2].x + p[3].x + p[4].x) / 5;
  res.y = (p[0].y + p[1].y + p[2].y + p[3].y + p[4].y) / 5;
  return res;
}



template<class T>
void pentagon<T>::print(std::ostream& os) const{
	for(int i = 0; i < 5; ++i){
      os << p[i];
    if(i + 1 != 5){
      os << ' ';
    }
  }
}


template<class T>
pentagon<T>::pentagon(std::istream& is) {
	for(int i = 0; i < 5; ++i){
    is >> p[i];
  }
}

#endif 