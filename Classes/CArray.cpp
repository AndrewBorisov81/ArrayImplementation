// TestG5Entertainment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "CArray.h"

template <typename TData>
CArray<TData>::CArray() noexcept 
{
	_pArr = new TData[rsrv_sz];
}

template <typename TData>
CArray<TData>::CArray(
  typename CArray<TData>::size_type _n
)
{
	size_type i;
	rsrv_sz = _n << 2;
	_pArr = new TData[rsrv_sz];
	for (i = 0; i < _n; ++i)
		_pArr[i] = TData();
	vec_sz = _n;
}

template <typename TData>
  CArray<TData>::CArray(
  const CArray<TData> & other
) 
{
    vec_sz = other.vec_sz;
    rsrv_sz = other.rsrv_sz;
    _pArr = new TData[vec_sz];
    for (int i = 0; i < vec_sz; i++)
    {
      _pArr[i] = other._pArr[i];
    }
}

template <typename TData>
CArray<TData>::~CArray()
{
	delete[] _pArr;
}

template <typename TData>
typename CArray<TData>::size_type CArray<TData>::size() const noexcept
{
	return vec_sz;
}

template <typename TData>
typename CArray<TData>::size_type CArray<TData>::max_size() const noexcept
{
	return LNI_VECTOR_MAX_SZ;
}

template <typename TData>
typename CArray<TData>::size_type CArray<TData>::capacity() const noexcept
{
	return rsrv_sz;
}

template <typename TData>
inline void CArray<TData>::reallocate() 
{
	TData *tarr = new TData[rsrv_sz];
	memcpy(tarr, _pArr, vec_sz * sizeof(TData));
	delete[] _pArr;
	_pArr = tarr;
}

template <typename TData>
void CArray<TData>::push_back(
  const TData &_val
) 
{
	if (vec_sz == rsrv_sz) {
		rsrv_sz <<= 2;
		reallocate();
	}
	_pArr[vec_sz] = _val;
	++vec_sz;
}

template <typename TData>
void CArray<TData>::push_back(
  const TData && _value
)
{
	if (vec_sz == rsrv_sz) {
		rsrv_sz <<= 2;
		reallocate();
	}
	_pArr[vec_sz] = std::move(_value);
	++vec_sz;
}

template <typename TData>
void CArray<TData>::clear() noexcept 
{
	size_type i;
	for (i = 0; i < vec_sz; ++i)
		_pArr[i].~TData();
	vec_sz = 0;
}

template <typename TData>
typename CArray<TData>::reference CArray<TData>::operator [](
  typename CArray<TData>::size_type _index
  ) 
{
	return _pArr[_index];
}

template <typename TData>
typename CArray<TData>::const_reference CArray<TData>::operator [](
  typename CArray<TData>::size_type _index
  ) const 
{
	return _pArr[_index];
}


template <typename TData>
typename CArray<TData>::iterator CArray<TData>::erase(
  const unsigned int _index)
{
	int curIndex = _index;
	typename CArray<TData>::const_iterator it = _pArr;
	if (_index < 0 || _index > size()) {
		std::cout << "out of range exception" << std::endl;
		throw _index;
	}
	iterator iit = &_pArr[(it + curIndex) - _pArr];
	(*iit).~TData();
	memmove(iit, iit + 1, (vec_sz - ((it + curIndex) - _pArr) - 1) * sizeof(TData));
	--vec_sz;
	return iit;
}

template <typename TData>
typename CArray<TData>::iterator CArray<TData>::insert(
  const unsigned int _index,
  const TData & _value
)
{
	unsigned int curIndex = _index;
	typename CArray<TData>::const_iterator it = _pArr;
    if (_index < 0 || _index > size())
    {
      std::cout << "out of range exception" << std::endl;
      throw _index;
    }
		
	iterator iit = &_pArr[((it + curIndex) - _pArr)];
	if (vec_sz == rsrv_sz) {
		rsrv_sz <<= 2;
		reallocate();
	}
	memmove(iit + 1, iit, (vec_sz - ((it + curIndex) - _pArr)) * sizeof(TData));
	(*iit) = std::move(_value);
	++vec_sz;
	return iit;
}

template <typename TData>
typename CArray<TData>::iterator CArray<TData>::begin() noexcept
{
	return _pArr;
}

template <typename TData>
typename CArray<TData>::const_iterator CArray<TData>::cbegin() const noexcept
{
	return _pArr;
}

template <typename TData>
typename CArray<TData>::iterator CArray<TData>::end() noexcept
{
	return _pArr + vec_sz;
}

template <typename TData>
typename CArray<TData>::const_iterator CArray<TData>::cend() const noexcept
{
	return _pArr + vec_sz;
}

template <typename TData>
typename CArray<TData>::reverse_iterator CArray<TData>::rbegin() noexcept
{
	return reverse_iterator(_pArr + vec_sz);
}

template <typename TData>
typename CArray<TData>::const_reverse_iterator CArray<TData>::crbegin() const noexcept
{
	return reverse_iterator(_pArr + vec_sz);
}

template <typename TData>
typename CArray<TData>::reverse_iterator CArray<TData>::rend() noexcept
{
	return reverse_iterator(_pArr);
}

template <typename TData>
typename CArray<TData>::const_reverse_iterator CArray<TData>::crend() const noexcept
{
	return reverse_iterator(_pArr);
}

template class CArray<int>;
template class CArray<std::string>;