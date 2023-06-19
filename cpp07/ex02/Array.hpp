#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template <typename T>
class Array
{
private:
    unsigned int _size;
    T *_array;

public:
    Array<T>() : _size(0), _array(NULL){};

    Array<T>(unsigned int n)
    {
        _array = new T[n];
        _size = n;
    };

    Array<T>(Array<T> const &src) { *this = src; };

    Array<T> &operator=(Array<T> const &rhs)
    {
        _size = rhs.size();
        _array = new T[_size];

        for (unsigned int i = 0; i < _size; i++)
        {
            _array[i] = rhs._array[i];
        }

        return *this;
    };

    T &operator[](int index)
    {
        if (index >= 0 && index < (int)_size)
        {
            return _array[index];
        }
        throw IndexError();
    };

    ~Array<T>() { delete[] _array; };

    unsigned int size() const
    {
        return _size;
    };

    class IndexError : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "index invalide";
        };
    };
};

#endif
