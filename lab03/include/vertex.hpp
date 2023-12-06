#pragma once

#include <iostream>
#include <cmath>

typedef std::pair <double, double> Vertex;

bool operator==(Vertex x, Vertex y) noexcept;
std::ostream& operator<<(std::ostream& os, const Vertex & v);
std::istream& operator>>(std::istream& is, Vertex & v);