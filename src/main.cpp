#include <iostream>

#include "Figure.hpp"
#include "Hexagon.hpp"
#include "Pentagon.hpp"
#include "Rhomb.hpp"
#include "Vector_figures.hpp"

int main() {
    std::cout << "Inp vector size\n";
    int n;
    std::cin >> n;
    
    Vector_figures v;
    for (size_t i = 0; i < n; ++i) {
        std::cout << "\n1 - hex\n2 - pent\n3 - rhomb\n";
        int f;
        std::cin >> f;

        Figure* now = nullptr;
        if (f == 1) {
            now = new Hexagon;
        } else if (f == 2) {
            now = new Pentagon;
        } else if (f == 3) {
            now = new Rhomb;
        }
        std::cin >> *now;
        v.push_back(now);
    }

    std::cout << v.size() << "\n";

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i]->getArea() << " ";
    }

    std::cout << "\nINPUT ERASE INDEX: ";
    size_t ind;
    std::cin >> ind;
    v.erase(ind);

    std::cout << v.size() << "\n";

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i]->getArea() << "\n";
    }
}
