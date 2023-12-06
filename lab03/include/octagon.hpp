#pragma once

#include "vertex.hpp"
#include "figure.hpp"


class Octagon : public Figure {
public:
    Octagon() = default;
    Octagon(Vertex& v1, Vertex& v2, Vertex& v3, Vertex& v4, Vertex& v5, Vertex& v6, Vertex& v7, Vertex& v8);
    Octagon(std::istream& stream);
    void print(std::ostream& stream) const;
    Vertex center() const;
    Figure& move(Figure&& other) noexcept;
    Figure& operator = (const Figure& other);
    bool operator == (const Figure& other) const;
    operator double() const;
    virtual ~Octagon() = default;
private:
    Vertex vertices[8];

};