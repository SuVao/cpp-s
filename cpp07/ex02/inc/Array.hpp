
#pragma once 

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>

template <typename T>
class Array
{
private:
	T a;
public:
	Array();
	Array(const unsigned int a);
	Array& operator=();
};

#endif