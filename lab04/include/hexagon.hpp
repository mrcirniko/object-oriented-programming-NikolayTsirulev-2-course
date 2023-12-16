#pragma once

#include "figure.hpp"
#include <cmath>


template <CoordType T>
class Hexagon : public Figure<T> {
public:
    std::vector< std::pair<T, T> > vertices;

    Hexagon() {
        vertices.resize(6, {0, 0});
    }

    Hexagon(const std::vector<std::pair<T, T> >& v) : vertices(v) {
        if (v.size() != 6) {
            throw std::logic_error("Hexagon must have 6 vertices");
        }
    }

    typename Figure<T>::vertex_t center() const {
        return {(vertices[0].first + vertices[3].first) / 2.0, (vertices[0].second + vertices[3].second) / 2.0};

    }

    Hexagon& operator=(const Hexagon<T>& other) {
        vertices = other.vertices;
        return *this;
    }

    Hexagon& operator=(Hexagon<T>&& other) {
        vertices = std::move(other.vertices);
        return *this;
    }

    bool operator==(const Hexagon& other) const {
        for (size_t i = 0; i < 6; ++i) {
            if (vertices[i] != other.vertices[i]) {
                return 0;
            }
        }
        return 1;
    }

    operator double() const override;

    ~Hexagon() = default;
};

template <CoordType T>
std::istream& operator>>(std::istream& is, Hexagon<T>& r) {
    for (size_t i = 0; i < 6; ++i) {
        is >> r.vertices[i].first >> r.vertices[i].second;
    }
    return is;
}

template <CoordType T>
std::ostream& operator<<(std::ostream& os, const Hexagon<T>& r) {
    for (size_t i = 0; i < 6; ++i) {
        os << "(" << r.vertices[i].first << ";" << r.vertices[i].second << ")"; 
    }
    return os;
}

template <CoordType T>
Hexagon<T>::operator double() const {
    return 3.0 * (sqrt(3.0) / 2.0) * ((vertices[1].first - vertices[0].first) * (vertices[1].first - vertices[0].first)
    + (vertices[1].second - vertices[0].second) * (vertices[1].second - vertices[0].second));
}