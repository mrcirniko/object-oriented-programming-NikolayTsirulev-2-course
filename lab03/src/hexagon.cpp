#include "hexagon.hpp"

Hexagon::Hexagon(std::istream& stream) {
    for (size_t i = 0; i < 6; ++i) {
        stream >> vertices[i];
    }
}

Hexagon::Hexagon(Vertex& v1, Vertex& v2, Vertex& v3, Vertex& v4, Vertex& v5, Vertex& v6) {
    vertices[0] = v1;
    vertices[1] = v2;
    vertices[2] = v3;
    vertices[3] = v4;
    vertices[4] = v5;
    vertices[5] = v6;
}

void Hexagon::print(std::ostream& stream) const {
    for (size_t i = 0; i < 6; ++i) {
        stream << vertices[i] << " ";
    }
    stream << std::endl;
}

Hexagon::operator double() const {
    return 3.0 * (sqrt(3.0) / 2.0) * ((vertices[1].first - vertices[0].first) * (vertices[1].first - vertices[0].first)
    + (vertices[1].second - vertices[0].second) * (vertices[1].second - vertices[0].second));
}

Vertex Hexagon::center() const {
    return std::make_pair((vertices[0].first + vertices[3].first) / 2.0, (vertices[0].second + vertices[3].second) / 2.0);
}

Figure& Hexagon::move(Figure&& other) noexcept {
    const Hexagon* otherHexagon = dynamic_cast <const Hexagon*> (&other);
    for (size_t i = 0; i < 6; ++i) {
        vertices[i] = std::move(otherHexagon->vertices[i]);
    }
    return *this;
}

Figure& Hexagon::operator=(const Figure& other) {
    const Hexagon* otherHexagon = dynamic_cast <const Hexagon*> (&other);
    for (size_t i = 0; i < 6; ++i) {
        vertices[i] = otherHexagon->vertices[i];
    }
    return *this;
}

bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* otherHexagon = dynamic_cast <const Hexagon*> (&other);
    for (size_t i = 0; i < 6; ++i) {
        if (vertices[i].first != otherHexagon->vertices[i].first || vertices[i].second != otherHexagon->vertices[i].second) {
            return false;
        }
    }
    return true;
}