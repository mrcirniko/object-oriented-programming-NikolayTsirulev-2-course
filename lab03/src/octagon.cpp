#include "octagon.hpp"

Octagon::Octagon(std::istream& stream) {
    for (size_t i = 0; i < 8; ++i) {
        stream >> vertices[i];
    }
}

Octagon::Octagon(Vertex& v1, Vertex& v2, Vertex& v3, Vertex& v4, Vertex& v5, Vertex& v6, Vertex& v7, Vertex& v8) {
    vertices[0] = v1;
    vertices[1] = v2;
    vertices[2] = v3;
    vertices[3] = v4;
    vertices[4] = v5;
    vertices[5] = v6;
    vertices[6] = v7;
    vertices[7] = v8;
}

void Octagon::print(std::ostream& stream) const {
    for (size_t i = 0; i < 8; ++i) {
        stream << vertices[i] << " ";
    }
    stream << std::endl;
}

Octagon::operator double() const {
    double area{0.0};
    for (size_t i = 0; i < 8; ++i) {
        if (i == 7) {
            area += 0.5 * std::abs((vertices[0].first - vertices[7].first) * (center().second - vertices[7].second) - 
                                   (vertices[0].second - vertices[7].second) * (center().first - vertices[7].first));
        } else {
            area += 0.5 * std::abs((vertices[i+1].first - vertices[i].first) * (center().second - vertices[i].second) - 
                                   (vertices[i+1].second - vertices[i].second) * (center().first - vertices[i].first));
        }

    }
    return area;
}

Vertex Octagon::center() const {
    return {(vertices[0].first + vertices[4].first) / 2.0, (vertices[0].second + vertices[4].second) / 2.0};
}

Figure& Octagon::move(Figure&& other) noexcept {
    const Octagon* otherOctagon = dynamic_cast <const Octagon*> (&other);
    for (size_t i = 0; i < 8; ++i) {
        vertices[i] = std::move(otherOctagon->vertices[i]);
    }
    return *this;
}

Figure& Octagon::operator=(const Figure& other) {
    const Octagon* otherOctagon = dynamic_cast <const Octagon*> (&other);
    for (size_t i = 0; i < 8; ++i) {
        vertices[i] = otherOctagon->vertices[i];
    }
    return *this;
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* otherOctagon = dynamic_cast <const Octagon*> (&other);
    for (size_t i = 0; i < 8; ++i) {
        if (vertices[i].first != otherOctagon->vertices[i].first || vertices[i].second != otherOctagon->vertices[i].second) {
            return false;
        }
    }
    return true;
}