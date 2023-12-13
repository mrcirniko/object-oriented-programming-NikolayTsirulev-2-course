#include "pentagon.hpp"

Pentagon::Pentagon(std::istream& stream) {
    for (size_t i = 0; i < 5; ++i) {
        stream >> vertices[i];
    }
}

Pentagon::Pentagon(Vertex& v1, Vertex& v2, Vertex& v3, Vertex& v4, Vertex& v5) {
    vertices[0] = v1;
    vertices[1] = v2;
    vertices[2] = v3;
    vertices[3] = v4;
    vertices[4] = v5;
}

void Pentagon::print(std::ostream& stream) const {
    for (size_t i = 0; i < 5; ++i) {
        stream << vertices[i] << " ";
    }
    stream << std::endl;
}

Pentagon::operator double() const {
    double area = 0.5 * std::abs((vertices[0].first - vertices[1].first) * (vertices[2].second - vertices[1].second) - 
                           (vertices[0].second - vertices[1].second) * (vertices[2].first - vertices[1].first))
          + 0.5 * std::abs((vertices[0].first - vertices[2].first) * (vertices[3].second - vertices[2].second) - 
                           (vertices[0].second - vertices[2].second) * (vertices[3].first - vertices[2].first))
          + 0.5 * std::abs((vertices[0].first - vertices[3].first) * (vertices[4].second - vertices[3].second) - 
                           (vertices[0].second - vertices[3].second) * (vertices[4].first - vertices[3].first));
    return area;
}

Vertex Pentagon::center() const {
    double a = sqrt((vertices[0].first - vertices[3].first) * (vertices[0].first - vertices[3].first) + (vertices[0].second - vertices[3].second) *  (vertices[0].second - vertices[3].second));
    double r = a / (2.0 * sin(M_PI / 5.0));
    return {vertices[0].first, (vertices[0].second - r)};
}

Figure& Pentagon::move(Figure&& other) noexcept {
    const Pentagon* otherPentagon = dynamic_cast <const Pentagon*> (&other);
    for (size_t i = 0; i < 5; ++i) {
        vertices[i] = std::move(otherPentagon->vertices[i]);
    }
    return *this;
}

Figure& Pentagon::operator=(const Figure& other) {
    const Pentagon* otherPentagon = dynamic_cast <const Pentagon*> (&other);
    for (size_t i = 0; i < 5; ++i) {
        vertices[i] = otherPentagon->vertices[i];
    }
    return *this;
}

bool Pentagon::operator==(const Figure& other) const {
    const Pentagon* otherPentagon = dynamic_cast <const Pentagon*> (&other);
    for (size_t i = 0; i < 5; ++i) {
        if (vertices[i].first != otherPentagon->vertices[i].first || vertices[i].second != otherPentagon->vertices[i].second) {
            return false;
        }
    }
    return true;
}