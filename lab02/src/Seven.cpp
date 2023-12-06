#include "Seven.h"


Seven::Seven() : _size(0), _number{nullptr}
{
}

Seven::Seven(const std::string& t)
{
    _number = new unsigned char[t.size()];
    size_t i = t.size() - 1;
    for (auto c : t)
    {
        if ((c - '0') < 0 || (c - '0') > 7) {
            throw std::logic_error("incorrect number, character: " + std::to_string(c));
        }
        _number[i--] = c;
    }
    _size = t.size();
}

Seven::Seven(const std::initializer_list<unsigned char> &t)
{
    std::cout << "Initializer list constructor" << std::endl;
    _number = new unsigned char[t.size()];
    size_t i = t.size() - 1;
    for (auto c : t)
    {
        if (c - '0' < 0 || c - '0' > 7) throw std::logic_error("incorrect number");
        _number[i--] = c;
    }
    _size = t.size();
}

Seven::Seven(const Seven &other)
{
    _size  = other._size;
    _number = new unsigned char[_size];

    for (size_t i{0}; i<_size; ++i) _number[i] = other._number[i];
}

Seven::Seven(Seven &&other) noexcept
{
    _size = other._size;
    _number = other._number;

    other._size = 0;
    other._number = nullptr;
}

Seven& Seven::operator = (const Seven &other)
{ 
    if (&other != this)
    {
        _size = other._size;
        delete[] _number;
        _size  = other._size;
        _number = new unsigned char[_size];

        for (size_t i{0}; i < _size; ++i) _number[i] = other._number[i];
    }
    return *this;
}

Seven Seven::operator + (const Seven &other) const
{
    size_t new_size = std::max(other._size, _size) + 1;
    std::string new_string(new_size, '0');
    int temp{0};
    for (int i{0}; i < new_size; i++) 
    {
        int val1{0}, val2{0};
        if (i < _size) val1 = _number[i] - '0';
        if (i < other._size) val2 = other._number[i] - '0';
        int new_value = val1 + val2 + temp;
        if (new_value > 7) 
        {
            
            new_string[i] = (new_value - 8) + '0';
            temp = 1;
        } else
        {
            new_string[i] = new_value + '0';
            temp = 0;
        }

    }
    if (new_string[new_size - 1] == '0') new_string.erase(new_size - 1, 1);
    std::reverse(new_string.begin(), new_string.end());
    return Seven{new_string};
}

Seven Seven::operator - (const Seven &other) const
{
    if (*this == other) return Seven{'0'};
    if (_size < other._size) throw std::logic_error("result can't be negative");
    std::string new_string(_size, '0');
    int temp{0};
    for (int i{0}; i < _size; i++) 
    {
        int val1{0}, val2{0};
        val1 = _number[i] - '0' - temp;
        if (i < other._size) val2 = other._number[i] - '0';
        int new_value = val1 - val2;
        if (new_value < 0) 
        {
            
            new_string[i] = (new_value + 8) + '0';
            temp = 1;
        } else if (new_value > 0)
        {
            new_string[i] = new_value + '0';
            temp = 0;
        }

    }
    if (new_string[_size - 1] == '0') new_string.erase(_size - 1, 1);
    std::reverse(new_string.begin(), new_string.end());
    return Seven{new_string};
}

bool Seven::operator == (const Seven& other) const
{
    size_t n = (_size < other._size) ? _size : other._size;
    for (int i{0}; i < n; i++)
    {
        if (other._number[i] != _number[i]) return false;
    }
    return true;
}

bool Seven::operator != (const Seven& other) const
{
    if (*this == other){
        return false;
    }
    return true;
}

bool Seven::operator < (const Seven& other) const
{
    if (_size < other._size) return true;
    if (_size > other._size) return false;
    for (int i = _size - 1; i >= 0; i--)
    {
        if (_number[i] < other._number[i]) return true;
        if (_number[i] > other._number[i]) return false;

    }
    return false;
}

bool Seven::operator > (const Seven& other) const
{
    if (*this < other || *this == other) return false;
    return true;
}

bool Seven::operator >= (const Seven& other) const
{
    if (*this < other) return false;
    return true;
}

bool Seven::operator <= (const Seven& other) const
{
    if (*this > other) return false;
    return true;
}

std::ostream &Seven::print(std::ostream &os)
{
    for (size_t i = 0; i < _size; ++i)
        os << _number[i];
    return os;
}

Seven::~Seven() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _number;
        _number = nullptr;
    }
}
