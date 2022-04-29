#include "Stack.h"
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <iostream>
#include <exception>


const std::size_t BLOCK_SIZE = 256;

int main() {
    std::vector<int, linear_allocator_t<int, BLOCK_SIZE> > vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }
    for (int i = 0; i < 10; ++i) {
        vec.pop_back();
    }
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }
    for (const int & elem : vec) {
        std::cout << elem << std::endl;
    }

    std::set<int, std::less<int>, linear_allocator_t<int, BLOCK_SIZE> > s;
    for (int i = 0; i < 10; ++i) {
        s.insert(i);
    }
    for (int elem : s) {
        std::cout << elem << std::endl;
    }

    std::list<int, linear_allocator_t<int, BLOCK_SIZE> > l;
    for (int i = 0; i < 10; ++i) {
        l.push_back(i);
    }
    for (int elem : l) {
        std::cout << elem << std::endl;
    }

    /* I */

    auto Print = [](const auto & elem) {
        std::cout << elem << std::endl;
    };
    size_t n;
    std::cout << "Input number of rectangle in stack" << std::endl;
    std::cin >> n;
    int cordX, cordY, sideA, sideB;
    Stack< Rectangle<int>, linear_allocator_t< Rectangle<int>, BLOCK_SIZE > > st;
    for (size_t i = 0; i < n; ++i) {
        size_t n;
        std::cout << "Enter index to insert a rectangle" << std::endl;
        std::cin >> n;
        std::cout << "Enter your point and sides\n"
                  << "First is point. Enter x and y.\n"
                  << "Second are sides. Enter a and b" << std::endl;
        std::cin >> cordX >> cordY >> sideA >> sideB;
        try {
            auto it = st.begin();
            while (n--) {
                ++it;
            }
            st.insert(it, Rectangle<int>(std::pair<int, int>(cordX, cordY), sideA, sideB));
        } catch (std::runtime_error & exception) {
            std::terminate();
        }
    }
    std::cout << "Your entering:" << std::endl;
    std::for_each(st.begin(), st.end(), Print);
    std::cout << "Enter index to erase from stack" << std::endl;
    std::cin >> n;
    try {
        auto it = st.begin();
        while (n > 1) {
            ++it;
            --n;
        }
        st.erase(it);
    } catch (std::runtime_error & exception) {
        std::terminate();
    }
    std::cout << "After erase:" << std::endl;
    std::for_each(st.begin(), st.end(), Print);
    return 0;
}
