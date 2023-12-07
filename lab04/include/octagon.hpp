#pragma once

#include "figure.hpp"
#include <cmath>


template <CoordType T>
class Octagon : public Figure<T> {
public:
    std::vector< std::pair<T, T> > vertices;

    Octagon() {
        vertices.resize(8, {0, 0});
    }

    Octagon(const std::vector<std::pair<T, T> >& v) : vertices(v) {
        if (v.size() != 8) {
            throw std::logic_error("Octagon must have 8 vertices");
        }
    }

    typename Figure<T>::vertex_t center() const {
    return {(vertices[0].first + vertices[4].first) / 2.0, (vertices[0].second + vertices[4].second) / 2.0};
    }

    Octagon& operator=(const Octagon<T>& other) {
        vertices = other.vertices;
        return *this;
    }

    Octagon& operator=(Octagon<T>&& other) {
        vertices = std::move(other.vertices);
        return *this;
    }

    bool operator==(const Octagon& other) const {
        for (size_t i = 0; i < 8; ++i) {
            if (vertices[i] != other.vertices[i]) {
                return 0;
            }
        }
        return 1;
    }

    operator double() const override;

    ~Octagon() = default;
};

template <CoordType T>
std::istream& operator>>(std::istream& is, Octagon<T>& r) {
    for (size_t i = 0; i < 8; ++i) {
        is >> r.vertices[i].first >> r.vertices[i].second;
    }
    return is;
}

template <CoordType T>
std::ostream& operator<<(std::ostream& os, const Octagon<T>& r) {
    for (size_t i = 0; i < 8; ++i) {
        os << "(" << r.vertices[i].first << ";" << r.vertices[i].second << ")"; 
    }
    return os;
}

template <CoordType T>
Octagon<T>::operator double() const {
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