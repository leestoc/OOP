#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <cmath>
#include "point.h"
#include "vector.h"
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"

int main() {
	std::vector<Figure *> figures;
	std::string command;
	std::cout << "Operations: Add/ Print/ Area/ Center/ Total_area/ Print_all/ Delete/ Delete_all/ Quit" << std::endl;
	std::cout << "______________________________________" << std::endl;
	while (std::cin >> command) {
		if (command == "Add") {
			std::string fig_type;
			std::cout << "Figures: Triangle/ Square/ Rectangle" << std::endl;
			std::cin >> fig_type;
			Figure *new_fig;
			if (fig_type == "Triangle") {
				new_fig = new Triangle;
			}
			else if (fig_type == "Square") {
				new_fig = new Square;
			}
			else if (fig_type == "Rectangle") {
				new_fig = new Rectangle;
			}
			else {
				std::cout << "Invalid figure type" << std::endl;
				std::cin.clear();
				std::cin.ignore(30000, '\n');
				std::cout << "______________________________________" << std::endl;
				continue;
			}
			try {
				std::cout << "Points: ";
				std::cin >> (*new_fig);
				std::cout << "______________________________________" << std::endl;
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
				std::cout << "______________________________________" << std::endl;
				delete new_fig;
				continue;
			}
			figures.push_back(new_fig);
		}
		else if (command == "Print") {
			unsigned int index;
			std::cout << "Index: ";
			std::cin >> index;
			if (index < 0 || index >= figures.size()) {
				std::cout << "No object at that index" << std::endl;
				std::cout << "______________________________________" << std::endl;
				continue;
			}
			std::cout << "Figure at index " << index << ": " << *figures[index] << std::endl; 
			std::cout << "______________________________________" << std::endl;
		}
		else if (command == "Area") {
			unsigned int index;
			std::cout << "Index: ";
			std::cin >> index;
			if (index < 0 || index >= figures.size()) {
				std::cout << "No object at that index" << std::endl;
				std::cout << "______________________________________" << std::endl;
				continue;
			}
			std::cout << *figures[index] << ". Area: " << figures[index]->Area() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		else if (command == "Center") {
			unsigned int index;
			std::cout << "Index: ";
			std::cin >> index;
			if (index < 0 || index >= figures.size()) {
				std::cout << "No object at that index" << std::endl;
				std::cout << "______________________________________" << std::endl;
				continue;
			}
			std::cout << *figures[index] << ". Center: " << figures[index]->Center() << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		else if (command == "Total_area") {
			double area = 0;
			for (Figure *ptr : figures) {
				area += ptr->Area();
			}
			std::cout << "Total area: " << area << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
		else if (command == "Print_all") {
			for (unsigned int i = 0; i < figures.size(); i++) {
				std::cout << i << ". " << *figures[i] << std::endl;
			}
			std::cout << "______________________________________" << std::endl;
		}
		else if (command == "Delete") {
			unsigned int index;
			std::cout << "Index: ";
			std::cin >> index;
			if (index < 0 || index >= figures.size()) {
				std::cout << "No object at that index" << std::endl;
				std::cout << "______________________________________" << std::endl;
				continue;
			}
			delete figures[index];
			figures.erase(figures.begin() + index);
			std::cout << "______________________________________" << std::endl;
		}
		else if (command == "Delete_all") {
			for (std::vector<Figure *>::iterator i = figures.begin(); i != figures.end(); i++) {
				delete *i;
			}
			figures.clear();
			std::cout << "______________________________________" << std::endl;
		}
		else if (command == "Quit") {
			for (unsigned int i = 0; i < figures.size(); i++) {
				delete figures[i];
			}
			std::cout << "______________________________________" << std::endl;
			return 0;
		}
		else {
			std::cout << "Wrong. Operations: Add/ Print/ Area/ Center/ Total_area/ Print_all/ Delete/ Delete_all/ Quit" << std::endl;
			std::cout << "______________________________________" << std::endl;
		}
	}
	return 0;
}