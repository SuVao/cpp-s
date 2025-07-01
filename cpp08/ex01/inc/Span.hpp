
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
	void addMultiple(unsigned int nbrs);
	class error : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "The store is full\n";
		}
	};
	class error_empty : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "The store don't have elements enough!\n";
		}
	};
	class error_nbrs : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Too many numbers for the store\n";
		}
	};

};

#endif