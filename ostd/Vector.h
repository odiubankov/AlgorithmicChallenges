#ifndef MEYERSEXAMPLES_VECTOR_H
#define MEYERSEXAMPLES_VECTOR_H

#include <algorithm>
#include <stdexcept>

namespace ostd{

template<typename T>
class Vector
{
    T* data;
    std::size_t size;
    std::size_t capacity;

public:
    Vector()
        : data{nullptr}
        , size{0}
        , capacity{0}
    {}


    Vector(const Vector& other)
    {
        if (other.size > 0)
        {
            copy_from_other(other);
        }
        else
        {
            data = nullptr;
            size = 0;
            capacity = 0;
        }
    }



    Vector& operator=(const Vector& other)
    {
        if (this == &other)
            return *this;

        clean_resources();
        copy_from_other(other);
        return *this;
    }


    ~Vector()
    {
        clean_resources();
    }


    void push_back(const T& val)
    {
        if (size == capacity)
            increase_capacity();

        data[size] = val;
        ++size;
    }


    void pop_back()
    {
        if (0 == size)
            throw std::out_of_range{};

        --size;
        if (size < capacity / 4)
            decrease_capacity();
    }


private:
    void copy_from_other(const Vector& other)
    {
        data = new T[other.size];
        std::copy(other.data, other.data + other.size, data);
        capacity = size = other.size;
    }


    void clean_resources()
    {
        if (nullptr != data)
        {
            delete [] data;
            size = 0;
            capacity = 0;
        }
    }


    void increase_capacity()
    {
        if (capacity == 0)
        {
            capacity = 1;
            data = new T[capacity];
        }
        else
        {
            capacity *= 2;
            applyNewCapacity();
        }
    }


    void decrease_capacity()
    {
        capacity /= 2;
        applyNewCapacity();
    }


    void applyNewCapacity()
    {
        auto tempData = new T[capacity];
        std::copy(data, data + size, tempData);
        std::swap(data, tempData);
        delete [] tempData;
    }
};

}//namespace ostd



#endif //MEYERSEXAMPLES_VECTOR_H
