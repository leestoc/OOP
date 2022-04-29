#include <iostream>
#include <tuple>
#include "point.h"
#include "hexagon.h"
#include "pentagon.h"
#include "rhombus.h"
#include "templates.h"

template<class T>
void init(std::istream& is, std::ostream& os) {
    if constexpr (is_figurelike_tuple<T>::value) {
        int arg;
        std::cin >> arg;
        std::cout << "Input coordinates: " << std::endl;
        if (arg == 4) {
            Point<double> A, B, C, D;
            is >> A >> B >> C >> D;
            auto object = std::make_tuple(A, B, C, D);
            print(os, object);
            os << "Area: " << area(object) << std::endl;
            os << "Center: " << center(object) << std::endl;
        }else if(arg == 5){
            Point<double> A, B, C, D, F;
            is >> A >> B >> C >> D >> F;
            auto object = std::make_tuple(A, B, C, D, F);
            print(os, object);
            os << "Area: " << area(object) << std::endl;
            os << "Center: " << center(object) << std::endl;
        }else if(arg == 6){
            Point<double> A, B, C, D, F, G;
            is >> A >> B >> C >> D >> F >> G;
            auto object = std::make_tuple(A, B, C, D, F, G);
            print(os, object);
            os << "Area: " << area(object) << std::endl;
            os << "Center: " << center(object) << std::endl;
        }
        }else {
        T object(is);
        print(os, object);
        os << '\n' <<"Area: " << area(object) << std::endl;
        os << "Center: " << center(object) << std::endl;
    }
}


int main() {
    char obj_type;
    std:: cout<< " Available input:\n1 - input pentagon\n2 - input Rhombus\n3 - input hexagon\n4 - Tuple\n5 - Exit" <<std::endl;
    while (std::cin >> obj_type){
        if(obj_type == '4') {
            std::cout << "Input number of vertices: " << std::endl;
            init<std::tuple<Point<double>>> (std::cin, std::cout);
        }else if(obj_type == '1'){
            std::cout << "Input pentagon coordinates: " << std::endl;
            init<pentagon<double>>(std::cin, std::cout);
        }else if(obj_type == '2'){
            std::cout << "Input Rhombus coordinates: " << std::endl;
            init<rhombus<double>>(std::cin, std::cout);
        }else if(obj_type == '3'){
            std::cout << "Input hexagon coordinates: " << std::endl;
            init<hexagon<double>>(std::cin, std::cout);
        }else if(obj_type == '5'){
	        return 0;
        }else{
	        std::cout << "Try another key" << std::endl;
        }
    }
}