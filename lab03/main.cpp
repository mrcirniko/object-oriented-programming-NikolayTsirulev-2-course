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
    //std::cout << "Area: " << double(*f) << std::endl;
    //std::cout << "Center: " << f->center().first << " " << f->center().second << std::endl;
    std::cout << std::fixed << std::setprecision(15) << "Area: " << double(*f) << std::endl;
    //printf("Area: %f\n", double(*f));
    //printf("Center: %f %f\n", f->get_center().first, f->get_center().second);
    std::cout << std::fixed << std::setprecision(15) << "Center: " << f->center().first << " " << f->center().second << std::endl;
}
