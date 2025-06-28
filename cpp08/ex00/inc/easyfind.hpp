
#pragma once

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <string>
#include <exception>
#include <iostream>
#include <vector>
#include <algorithm>


class error : public std::exception
{
public:
	const char* what() const throw()
	{
		return "Occurrence didn't found!\n";
	}
};

template<typename T>
typename T::const_iterator easyfind(const T& a, int A)
{
	typename T::const_iterator res = std::find(a.begin(), a.end(), A);
	if (res == a.end())
		throw error();
	return res;
}

#endif