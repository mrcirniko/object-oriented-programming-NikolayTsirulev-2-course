#include <vector>

#include "figure.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include <iomanip>
#include <memory>

int main() {

    std::shared_ptr<Figure<double> > p;
    std::vector<typename Figure<double>::vertex_t> vertices;
    double x, y;
    while (std::cin >> x >> y) {
        vertices.emplace_back(x, y);
    }
    p = std::make_shared<Hexagon<double> >(vertices);
    std::cout << std::fixed << std::setprecision(15) << "Area: " << double(*p) << std::endl;
    std::cout << std::fixed << std::setprecision(15) << "Center: " << p->center().first << " " << p->center().second << std::endl;
}
