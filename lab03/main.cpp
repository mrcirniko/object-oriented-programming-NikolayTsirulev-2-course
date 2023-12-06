#include <vector>

#include "figure.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include "vertex.hpp"
#include <iomanip>

int main() {
    Figure *f;
    
    f = new Octagon(std::cin);
    f->print(std::cout);
    std::cout << std::fixed << std::setprecision(15) << "Area: " << double(*f) << std::endl;
    std::cout << std::fixed << std::setprecision(15) << "Center: " << f->center().first << " " << f->center().second << std::endl;
    
}
