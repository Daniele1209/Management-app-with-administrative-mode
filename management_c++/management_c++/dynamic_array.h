#pragma once
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include "turret.h"

template <typename T>
class Dynamic_vector
{
private:
	int capacity, size;
	T* elems;

public:
	Dynamic_vector(int cap = 10);
	~Dynamic_vector();
	int get_size() const;
	void add(T elem);
	T& operator[](int position);
	Dynamic_vector(const Dynamic_vector& vector);
	int find_element(std::string str);
	int delete_item(int index);
	T& find(std::string str);
	//Dynamic_vector& operator=(const Dynamic_vector& vector);

private:
	void resize();

public:
	class iterator
	{
	private:
		T* ptr;

	public:
		iterator(T* pointer) : ptr{ pointer } {}
		//T& operator*();
		//bool operator!=(const iterator& it);
		//iterator operator++();
		//iterator operator++(int x);
	};

	//typename iterator begin();
	//typename iterator end();
};

template<typename T>
inline Dynamic_vector<T>::Dynamic_vector(int cap) : capacity{ cap }, size{ 0 }
{
	this->elems = new T[this->capacity];
}

template<typename T>
inline Dynamic_vector<T>::~Dynamic_vector()
{
	delete[] this->elems;
}

template<typename T>
inline int Dynamic_vector<T>::get_size() const
{
	return this->size;
}

template<typename T>
inline int Dynamic_vector<T>::find_element(std::string location) {
	for (int i = 0; i < get_size(); i++)
		if (elems[i].get_location() == location)
			return i;
	return -1;
}

template<typename T>
inline void Dynamic_vector<T>::add(T elem)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size++] = elem;
}

template<typename T>
inline int Dynamic_vector<T>::delete_item(int index)
{	
	for (int i = index + 1; i < this->size; i++)
		this->elems[i - 1] = this->elems[i];
	this->size--;
	return 0;
}

template<typename T>
inline T& Dynamic_vector<T>::operator[](int position)
{
	return this->elems[position];
}

template<typename T>
inline T& Dynamic_vector<T>::find(std::string str)
{
	for (int i = 0; i < this->get_size(); ++i)
		if (elems[i].get_location() == str)
			return 1;
	throw 404;
}

template<typename T>
inline Dynamic_vector<T>::Dynamic_vector(const Dynamic_vector& vector)
{
	this->capacity = vector.capacity;
	this->size = vector.size;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = vector.elems[i];
}
/*
template<typename T>
inline Dynamic_vector<T>& Dynamic_vector<T>::operator=(const Dynamic_vector& vector)
{
	Dynamic_vector<T> temp{ vector };
	std::swap(temp.elems, this->elems);
	std::swap(temp.capacity, this->capacity);
	std::swap(temp.size, this->size);

	return *this;
}
*/

template<typename T>
inline void Dynamic_vector<T>::resize()
{
	this->capacity *= 2;
	T* aux = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		aux[i] = this->elems[i];
	delete[] this->elems;
	this->elems = aux;
}
/*
template<typename T>
inline typename Dynamic_vector<T>::iterator Dynamic_vector<T>::begin()
{
	return iterator{ this->elems };
}

template<typename T>
inline typename Dynamic_vector<T>::iterator Dynamic_vector<T>::end()
{
	return iterator{ this->elems + this->size };
}

template<typename T>
inline T& Dynamic_vector<T>::iterator::operator*()
{
	return *this->ptr;
}

template<typename T>
inline bool Dynamic_vector<T>::iterator::operator!=(const iterator& it)
{
	return this->ptr != it.ptr;
}

template<typename T>
inline typename Dynamic_vector<T>::iterator Dynamic_vector<T>::iterator::operator++()
{
	this->ptr++;
	return *this;
}

template<typename T>
inline typename Dynamic_vector<T>::iterator Dynamic_vector<T>::iterator::operator++(int x)
{
	iterator aux{ *this };
	this->ptr++;
	return aux;
}
*/