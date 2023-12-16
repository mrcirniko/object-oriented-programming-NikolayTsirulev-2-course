#pragma once

#include <iostream>

template <class T, class Allocator = std::allocator<T> >
class Stack {
private:
    Allocator allocator;
    T* data;
    size_t _size, _capacity;
public:
    class Iterator {
    private:
        Stack<T, Allocator> &stack;
        size_t id;
        friend class Stack<T, Allocator>;
    public:
        using difference_type = int;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        Iterator(Stack &stack, size_t id) : stack(stack), id(id) {}

        Iterator& operator++() {
            --id;
            return *this;
        }

        reference operator*() {
            return stack.data[id];
        }

        pointer operator->() {
            return &stack[id];
        }

        bool operator==(const Iterator& other) {
            if (this->id != other.id) {
                return false;
            }
            return true;
        }

        bool operator!=(const Iterator& other) {
            if (this->id == other.id) {
                return false;
            }
            return true;
        }
    };

    class ConstIterator {
    private:
        Stack<T, Allocator> &stack;
        size_t id;
        friend class Stack<T, Allocator>;
    public:
        using difference_type = int;
        using value_type = const T;
        using pointer = const T*;
        using reference = const T&;

        ConstIterator(Stack &stack, size_t id) : stack(stack), id(id) {}

        ConstIterator& operator++() {
            --id;
            return *this;
        }

        reference operator*() {
            return stack[id];
        }

        pointer operator->() {
            return &stack[id];
        }

        bool operator==(const ConstIterator& other) {
            if (this->id != other.id) {
                return false;
            }
            return true;
        }

        bool operator!=(const ConstIterator& other) {
            if (this->id == other.id) {
                return false;
            }
            return true;
        }
    };

    Stack() : data(nullptr), _size(0), _capacity(0) {}

    Stack(size_t n) : _size(n), _capacity(n) {
        this->data = this->allocator.allocate(n);
    }

    Stack(const std::initializer_list<T> &list) {
        this->_size = list.size();
        this->_capacity = _size;
        this->data = allocator.allocate(_size);
        size_t i = 0;
        for(auto elem : list) {
            this->data[i++] = elem;
        }
    }

    Stack(const Stack<T>& other) {
        this->_size = other._size;
        this->_capacity = other._capacity;
        this->data = allocator.allocate(_size);
        for (size_t i = 0; i < this->_size; ++i) {
            this->data[i] = other.data[i];
        }
    }

    Stack(Stack<T>&& other) noexcept {
        this->_size = std::move(other._size);
        this->_capacity = std::move(other._capacity);
        this->data = std::move(other.data);
    }

    Stack operator=(const Stack<T>& other) {
        this->_size = other._size;
        this->_capacity = other._capacity;
        this->data = allocator.allocate(other.size());
        for (size_t i = 0; i < this->_size; i++) {
            this->data[i] = other.data[i];
        }
        return *this;
    }

    Stack operator=(Stack<T>&& other) noexcept {
        this->_size = std::move(other._size);
        this->_capacity = std::move(other._capacity);
        this->data = std::move(other.data);
        return *this;
    }

    bool empty() {
        return this->_size == 0;
    }

    size_t size() {
        return this->_size;
    }

    void resize(size_t n) {
        if (n > this->_capacity) {
            this->_capacity = n;
            T* oldData = this->data;
            this->data = this->allocator.allocate(n);
            for(int i = 0; i < this->_size; ++i) {
                this->data[i] = oldData[i];
            }
        }

    }

    void push(const T &a) {
        if (this->_size == this->_capacity) {
            resize(this->_capacity + 1);
        } 
        if (this->_size < this->_capacity) {
            this->data[this->_size++] = a; 
        }
    }

    T pop() {
        if (this->_size > 0) {
            this->_size--;
            return this->data[this->_size];
        } else {
            throw std::logic_error("Stack is empty");
        }
    }

    T top() {
         if (this->_size > 0) {
            return this->data[this->_size - 1];
        } else {
            throw std::logic_error("Stack is empty");
        }
    }

    friend std::ostream& operator<<(std::ostream &stream, const Stack &stack) {
        for (int i = stack._size - 1; i > -1; --i) {
            stream << stack.data[i] << ' ';
        }
        stream<< std::endl;
        return stream;
    }

    Iterator begin() {
        return Iterator(*this, _size - 1);
    }

    Iterator end() {
        return Iterator(*this, -1);
    }

    Iterator constBegin() {
        return ConstIterator(*this, _size - 1);
    }

    Iterator constEnd() {
        return ConstIterator(*this, -1);
    }

};