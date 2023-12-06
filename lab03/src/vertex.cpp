#include "vertex.hpp"

const double EPS = 1e-7;

bool operator==(Vertex x, Vertex y) noexcept {
    return (std::fabs(x.first - y.first) < EPS) && (std::fabs(x.second - y.second) < EPS);
}

std::ostream& operator<<(std::ostream& os, const Vertex & v) {
    os << "(" << v.first << "; " << v.second << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vertex & v) {
    is >> v.first >> v.second;
    return is;
}