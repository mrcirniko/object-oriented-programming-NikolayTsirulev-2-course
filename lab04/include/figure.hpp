#pragma once
#include <concepts>
#include <iostream>
#include <utility>

template <typename T>
concept CoordType = std::is_default_constructible<T>::value || std::integral<T> || std::floating_point<T>;

template <CoordType T>
class Figure {
public:
    using vertex_t = std::pair<T,T>;
    Figure() = default;
    virtual vertex_t center() const = 0;
    virtual operator double() const = 0;
    virtual ~Figure() = default;
};