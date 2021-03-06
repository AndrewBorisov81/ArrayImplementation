// TestG5Entertainment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

#include <cstddef>
#include <cstring>
#include <utility>
#include <iterator>
#include <stdexcept>
#include <initializer_list>


#ifndef LNI_VECTOR
#define LNI_VECTOR

#define LNI_VECTOR_MAX_SZ 1000000000

/*
*начал 28.08 в 16.00
*конец во вторник
*/
template<class TData>
class CArray
{
public:
	// types:
	typedef TData                                 value_type;
	typedef TData &                               reference;
	typedef const TData &                         const_reference;
	typedef TData *                               pointer;
	typedef const TData *                         const_pointer;
	typedef TData *                               iterator;
	typedef const TData *                         const_iterator;
	typedef std::reverse_iterator<iterator>		  reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef ptrdiff_t                             difference_type;
	typedef unsigned int                          size_type;

	// iterators:
	iterator begin() noexcept;
	const_iterator cbegin() const noexcept;
	iterator end() noexcept;
	const_iterator cend() const noexcept;
	reverse_iterator rbegin() noexcept;
	const_reverse_iterator crbegin() const noexcept;
	reverse_iterator rend() noexcept;
	const_reverse_iterator crend() const noexcept;

	//construct/copy/destroy:
	CArray() noexcept;
	explicit CArray(size_type n);
    //Копирующий конструктор
    CArray(
      const CArray<TData> & other
    );
	~CArray();

	//capacity:
	size_type size() const noexcept;
	size_type max_size() const noexcept;
	size_type capacity() const noexcept;

	// element access
	reference operator [](
      size_type
      );
	const_reference operator [](
      size_type
      ) const;

	void push_back(
      const TData & _value
    );
	void push_back(
      const TData && _value
    );

	iterator insert(
      const unsigned int, 
      const TData & _value
    );

	iterator erase(
      const unsigned int _value
    );
	void clear() noexcept;

protected:
	size_type rsrv_sz = 4;
	size_type vec_sz = 0;
	TData *_pArr;

	inline void reallocate();


//------------------------------------------------------------------------------------------------
	//Конструктор
	/*CArray();

	//Копирующий конструктор
	CArray(
		const CArray & other
	) {};

	//Деструктор
	~CArray() {
		delete[] _pArr;
	};

	//Добавить элемент в конец массива
	void push_back(
		const TData & _value
	) {};

	//Добавить элемент по заданному индексу
	void insert(
		unsigned int _index,
		const TData & _value
	) {};

	//Удалить массив элемента по заданному индексу
	void erase(
		unsigned int _index
	) {};

	//Очистить массив
	void clear() {};

	//Получить размер массива
	unsigned int size()const { return unsigned int; };

	//Получить элемент массива по заданному индексу
	TData & operator[](
		unsigned int _index
		);
protected:
	TData * _pArr;
	unsigned int _n;
	unsigned int _capacity;*/
};


#endif









