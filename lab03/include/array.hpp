#include "figure.hpp"

class Array {
public:
    Array();
    Array(const std::initializer_list<Figure*> & t);
    Array(const Array & a);
    Array(Array&& a) noexcept;
    ~Array();
    void remove(size_t index);
    double getTotalArea() const;
    size_t getSize() const;
    void printCenters() const;
    void printAreas() const;
private:
    Figure** _data;
    size_t _size;
};