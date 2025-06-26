
#pragma once 

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
	T* a;
	size_t size1;
public:
	~Array() { delete[] a ;};

	Array() : a(NULL), size1(0) {};

	Array(size_t b) : a(new T[b]), size1((b)) {};

	Array& operator=(const Array& other)
	{
		delete[] a;
		size1 = other.size1;
		a = new T[size1];
		for (size_t i = 0; i < other.size1; i++)
			a[i] = other.a[i];
		return *this;
	};

	Array(const Array& other) : a(new T[other.size1]), size1(other.size1)
	{
		for (size_t i = 0; i < size1; i++)
			a[i] = other.a[i];
	};

	T& operator[](std::size_t index)
	{
	    if (index >= size1)
	        throw std::out_of_range("Index out of bounds");
	    return a[index];
	}

	const T& operator[](std::size_t index) const
	{
	    if (index >= size())
	        throw std::out_of_range("Index out of bounds");
	    return a[index];
	}

	size_t size() const
	{
		return size1;
	}
};

#endif