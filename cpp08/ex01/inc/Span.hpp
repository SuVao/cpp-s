
#pragma once

#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


class Span
{
private:
	std::vector<int> store;
	unsigned int size;
public:
	Span(unsigned int m);
	~Span();
	void addNumber(int nb);
	int shortestSpan();
	int longestSpan();
	class error : public std::exception
	{
		const char* what() throw()
		{
			return "The store is full\n";
		}
	};
	class error_empty : public std::exception
	{
		const char* what() throw()
		{
			return "The store don't have elements enough!\n";
		}
	};

};

#endif