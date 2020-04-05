#pragma once
#include <algorithm>
#include <iterator>
#include <iostream>

template <typename T>
class DynamicVector
{
private:
	int capacity, size;
	T* elems;

public:
	DynamicVector(int cap = 10);
	~DynamicVector();
	int getSize() const;
	void add(T elem);
	T& operator[](int position);
	DynamicVector(const DynamicVector& vector);
	DynamicVector& operator=(const DynamicVector& vector);

private:
	void resize();

public:
	class iterator
	{
	private:
		T* ptr;

	public:
		iterator(T* pointer) : ptr{ pointer } {}
		T& operator*();
		bool operator!=(const iterator& it);
		iterator operator++();
		iterator operator++(int x);
	};

	typename iterator begin();
	typename iterator end();
};

template<typename T>
inline DynamicVector<T>::DynamicVector(int cap) : capacity{ cap }, size{ 0 }
{
	this->elems = new T[this->capacity];
}

template<typename T>
inline DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}

template<typename T>
inline int DynamicVector<T>::getSize() const
{
	return this->size;
}

template<typename T>
inline void DynamicVector<T>::add(T elem)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size++] = elem;
}

template<typename T>
inline T& DynamicVector<T>::operator[](int position)
{
	return this->elems[position];
}

template<typename T>
inline DynamicVector<T>::DynamicVector(const DynamicVector& vector)
{
	this->capacity = vector.capacity;
	this->size = vector.size;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = vector.elems[i];
}

template<typename T>
inline DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& vector)
{
	DynamicVector<T> temp{ vector };
	std::swap(temp.elems, this->elems);
	std::swap(temp.capacity, this->capacity);
	std::swap(temp.size, this->size);

	return *this;
}

template<typename T>
inline void DynamicVector<T>::resize()
{
	this->capacity *= 2;
	T* aux = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		aux[i] = this->elems[i];
	delete[] this->elems;
	this->elems = aux;
}

template<typename T>
inline typename DynamicVector<T>::iterator DynamicVector<T>::begin()
{
	return iterator{ this->elems };
}

template<typename T>
inline typename DynamicVector<T>::iterator DynamicVector<T>::end()
{
	return iterator{ this->elems + this->size };
}

template<typename T>
inline T& DynamicVector<T>::iterator::operator*()
{
	return *this->ptr;
}

template<typename T>
inline bool DynamicVector<T>::iterator::operator!=(const iterator& it)
{
	return this->ptr != it.ptr;
}

template<typename T>
inline typename DynamicVector<T>::iterator DynamicVector<T>::iterator::operator++()
{
	this->ptr++;
	return *this;
}

template<typename T>
inline typename DynamicVector<T>::iterator DynamicVector<T>::iterator::operator++(int x)
{
	iterator aux{ *this };
	this->ptr++;
	return aux;
}
