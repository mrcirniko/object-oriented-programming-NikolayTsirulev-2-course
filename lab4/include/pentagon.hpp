#pragma once

#include "figure.hpp"
#include <cmath>


template <CoordType T>
class Pentagon : public Figure<T> {
public:
    std::vector< std::pair<T, T> > vertices;

    Pentagon() {
        vertices.resize(5, {0, 0});
    }

    Pentagon(const std::vector<std::pair<T, T> >& v) : vertices(v) {
        if (v.size() != 5) {
            throw std::logic_error("Pentagon must have 5 vertices");
        }
    }

    typename Figure<T>::vertex_t center() const {
        double a = sqrt((vertices[0].first - vertices[3].first) * (vertices[0].first - vertices[3].first) + (vertices[0].second - vertices[3].second) *  (vertices[0].second - vertices[3].second));
        double r = a / (2.0 * sin(M_PI / 5.0));
        return {vertices[0].first, (vertices[0].second - r)};
    }

    Pentagon& operator=(const Pentagon<T>& other) {
        vertices = other.vertices;
        return *this;
    }

    Pentagon& operator=(Pentagon<T>&& other) {
        vertices = std::move(other.vertices);
        return *this;
    }

    bool operator==(const Pentagon& other) const {
        for (size_t i = 0; i < 4; ++i) {
            if (vertices[i] != other.vertices[i]) {
                return 0;
            }
        }
        return 1;
    }

    operator double() const override;

    ~Pentagon() = default;
};

template <CoordType T>
std::istream& operator>>(std::istream& is, Pentagon<T>& r) {
    for (size_t i = 0; i < 5; ++i) {
        is >> r.vertices[i].first >> r.vertices[i].second;
    }
    return is;
}

template <CoordType T>
std::ostream& operator<<(std::ostream& os, const Pentagon<T>& r) {
    for (size_t i = 0; i < 5; ++i) {
        os << "(" << r.vertices[i].first << ";" << r.vertices[i].second << ")"; 
    }
    return os;
}

template <CoordType T>
Pentagon<T>::operator double() const {
    double area = 0.5 * std::abs((vertices[0].first - vertices[1].first) * (vertices[2].second - vertices[1].second) - 
                           (vertices[0].second - vertices[1].second) * (vertices[2].first - vertices[1].first))
          + 0.5 * std::abs((vertices[0].first - vertices[2].first) * (vertices[3].second - vertices[2].second) - 
                           (vertices[0].second - vertices[2].second) * (vertices[3].first - vertices[2].first))
          + 0.5 * std::abs((vertices[0].first - vertices[3].first) * (vertices[4].second - vertices[3].second) - 
                           (vertices[0].second - vertices[3].second) * (vertices[4].first - vertices[3].first));
    return area;
}