template <class T>
class Array {
public:
    Array() : __size(0), _array{nullptr} {}

    Array<T>::Array(const Array<T> & t) {
        _size = t._size;
        _array = std::make_unique<T[]>(_size);
        for (size_t i = 0; i < _size; ++i) {
            _array[i] = t._array[i];
        }
    }

    Array<T>::Array(const std::initializer_list<T> & t) {
        _size = t.size();
        _array = std::make_unique<T[]>(_size);
        size_t i = 0;
        for (T elem : t) {
            _array[i] = elem;
            ++i;
        }
    }

    size_t getSize() const { 
        return _size;
    }

    void add(T arrayElem) {
        auto newArray = std::make_unique<T[]>(_size + 1);
        for (size_t i = 0; i < _size; ++i) {
            newArray[i] = std::move(_array[i]);
        }
        newArray[_size] = std::move(arrayElem);
        _array = std::move(newArray);
        ++_size;
    }

    void remove(size_t index) {
        if (index >= _size) {
            throw std::range_error("Out of bounds");
        }
        std::unique_ptr<T[]> newArray = std::make_unique<T[]>(_size - 1);
        size_t j = 0;
        for (size_t i = 0; i < _size - 1; ++i) {
            if (i == index) {
                ++j;
            }
            new_array[i] = _array[j];
            ++j;
        }
        --_size;
        _array = newArray;
    }

    double totalArea() const {
        double sum = 0;
        for (size_t i = 0; i < _size; ++i) {
            sum += (double) *(_array[i]);
        }
        return sum;
    }

    T get(size_t index) {
        if (index < _size) {
            return std::move(_array[index]);
        }
        return nullptr;
    }
private:
    size_t _size;
    std::unique_ptr<T[] > _array;
};