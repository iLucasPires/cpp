#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <iostream>

template <typename T>
class Array
{
private:
    unsigned int _size;
    T *_array;

public:
    Array<T>() : _size(0), _array(NULL) {};

    Array<T>(unsigned int n) : _size(n)
    {
        this->_array = new T[n];
    };

    Array<T>(Array<T> const &src) { *this = src; };

    Array<T> &operator=(Array<T> const &rhs)
    {
        this->_size = rhs.size();
        this->_array = new T[this->_size];

        for (unsigned int i = 0; i < this->_size; i++)
        {
            this->_array[i] = rhs._array[i];
        }

        return *this;
    };

    T &operator[](int index)
    {
        if (index >= 0 && index < (int)this->_size)
        {
            return this->_array[index];
        }
        throw IndexError();
    };

    ~Array<T>() { delete[] this->_array; };

    unsigned int size() const
    {
        return this->_size;
    };

    class IndexError : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "acessing index out of range";
        };
    };
};

#endif
