
#pragma once 

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <vector>

class RPN
{
private:
	std::vector<int> a;
	std::vector<char> b;
public:
	RPN(std::string arg);
	~RPN();
	int multiply(int nb, int nb2);
	int some(int nb, int nb2);
	int division(int nb, int nb2);
	int less(int nb, int nb2);
	class error : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Invalid Arguments!\n";
		}
	};
};
	bool no_signes(const std::string& s);

#endif