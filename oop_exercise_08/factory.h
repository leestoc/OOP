#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include "figure.h"

namespace factory {

    class Factory {
    public:
        std::shared_ptr<figures::Figure> FigureCreate(std::istream& is) const {
            std::string type;
            std::cin >> type;
            if (type == "hexagon") {
                return std::shared_ptr<figures::Figure>(new figures::Hexagon(is));
            }
            else if (type == "octagon") {
                return std::shared_ptr<figures::Figure>(new figures::Octagon(is));
            }
            else if (type == "triangle") {
                return std::shared_ptr<figures::Figure>(new figures::Triangle(is));
            }
            throw std::logic_error("Wrong. Figures: hexagon, octagon, triangle");
        }
    };
}
#endif
