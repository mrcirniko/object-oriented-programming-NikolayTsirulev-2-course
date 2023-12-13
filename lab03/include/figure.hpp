#pragma once

#include <iostream>
#include <vector>

#include "vertex.hpp"

class Figure {
public:
    virtual Figure& move(Figure&& other) noexcept = 0;
    virtual Figure& operator = (const Figure& other) = 0;
    virtual bool operator == (const Figure& other) const = 0;
    virtual Vertex center() const = 0;
    virtual void print(std::ostream& stream) const = 0;
    virtual operator double() const = 0;
    virtual ~Figure() = default;
};