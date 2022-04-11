#pragma once

#include <iostream>
#include <cstddef>
#include <cstring>
#include <utility>
#include <stdexcept>

template<class TData>
class CArray
{
public:

    CArray();

    CArray(
        const CArray& _array
    );

    ~CArray();

    void push_back(
        const TData& _value
    );

    void insert(
        unsigned int _index,
        const TData& _value
    );

    void erase(
        unsigned int _index
    );

    void clear();

    unsigned int size() const;

    TData& operator[](
        unsigned int _index
        );

protected:
    TData* m_pArr;
    unsigned int m_size;
    unsigned int m_capacity;

    void reallocate();
};