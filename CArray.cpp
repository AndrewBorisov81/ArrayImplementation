#include <iostream>
#include <string>
#include "CArray.h"

template <typename TData>
CArray<TData>::CArray()
{
    m_size = 0;
    m_capacity = 4;
    m_pArr = new TData[m_capacity];
}

template <typename TData>
CArray<TData>::CArray(
    const CArray<TData>& _array
)
{
    m_size = _array.m_size;
    m_capacity = _array.m_capacity;
    m_pArr = new TData[m_size];
    for (unsigned int i = 0; i < m_size; i++)
    {
        m_pArr[i] = _array.m_pArr[i];
    }
}

template <class TData>
CArray<TData>::~CArray()
{
    delete[] m_pArr;
}

template <typename TData>
void CArray<TData>::reallocate()
{
    TData* pArr = new TData[m_capacity];
    for (int i = 0; i < m_size; i++)
    {
        pArr[i] = m_pArr[i];
    }
    delete[] m_pArr;
    m_pArr = pArr;
}

template <typename TData>
unsigned int CArray<TData>::size() const
{
    return m_size;
}

template <typename TData>
TData& CArray<TData>::operator[](
    unsigned int _index
    )
{
    return m_pArr[_index];
}

template <typename TData>
void CArray<TData>::clear()
{
    for (unsigned int i = 0; i < m_size; ++i)
    {
        TData* ptr = (TData*)m_pArr;
        ptr->~TData();
    }
    m_size = 0;
}

template <typename TData>
void CArray<TData>::push_back(
    const TData& _value
)
{
    if (m_size == m_capacity)
    {
        m_capacity <<= 2;
        reallocate();
    }
    m_pArr[m_size] = _value;
    ++m_size;
}

template <typename TData>
void CArray<TData>::insert(
    unsigned int _index,
    const TData& _value
)
{
    unsigned int curIndex = _index;
    const TData* it = m_pArr;
    if (_index < 0 || _index > size())
    {
        std::cout << "out of range exception" << std::endl;
        throw _index;
    }

    TData* iit = &m_pArr[it - m_pArr];
    if (m_size == m_capacity)
    {
        m_capacity <<= 2;
        reallocate();
    }
    memmove(iit + 1, iit, (m_size - (it - m_pArr)) * sizeof(TData));
    (*iit) = _value;
    ++m_size;
}

template <typename TData>
void CArray<TData>::erase(
    unsigned int _index
)
{
    const TData* it = m_pArr;
    if (_index < 0 || _index > size())
    {
        std::cout << "out of range exception" << std::endl;
        throw _index;
    }
    TData* iit = &m_pArr[(it + _index) - m_pArr];
    (*iit).~TData();
    memmove(iit, iit + 1, (m_size - ((it + _index) - m_pArr) - 1) * sizeof(TData));
    --m_size;
}

template class CArray<int>;
template class CArray<char>;
template class CArray<std::string>;