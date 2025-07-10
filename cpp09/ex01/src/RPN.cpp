
#include "../inc/RPN.hpp"

bool no_signes(const std::string& s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/')
			return true;
	}
	return false;
}


RPN::RPN(std::string str)
{
	if (!no_signes(str))
	{
		std::cerr << "Error: not enough operandors\n";
		return ;
	}
	for (size_t i = 0; i < str.length();i++)
	{
		/* if (a.size() < 2)
		{
			std::cerr << "Error: not enough operands\n";
			break;
		} */
		if (std::isspace(str[i]))
    		continue;
		if (isdigit(str[i]))
		{
			int val1 = str[i] - '0';
			a.push_back(val1);
		}
		if (str[i] == '+')
		{
			if (a.size() < 2)
			{
				std::cerr << "Error: not enough operands\n";
				break;
			}
			int top1 = a.back();
			a.pop_back();
			int top2 = a.back();
			a.pop_back();
			a.push_back(some(top2, top1));
		}
		else if (str[i] == '-')
		{
			if (a.size() < 2)
			{
				std::cerr << "Error: not enough operands\n";
				break;
			}
			int top1 = a.back();
			a.pop_back();
			int top2 = a.back();
			a.pop_back();
			a.push_back(less(top2, top1));
		}
		else if (str[i] == '*')
		{
			if (a.size() < 2)
			{
				std::cerr << "Error: not enough operands\n";
				break;
			}
			int top1 = a.back();
			a.pop_back();
			int top2 = a.back();
			a.pop_back();
			a.push_back(multiply(top2, top1));
		}
		else if (str[i] == '/')
		{
			if (a.size() < 2)
			{
				std::cerr << "Error: not enough operands\n";
				break;
			}
			int top1 = a.back();
			if (top1 == 0)
			{
				std::cerr << "Division by 0! \n";
				break;
			}
			a.pop_back();
			int top2 = a.back();
			a.pop_back();
			a.push_back(division(top2, top1));
		}
	}
	if (a.size() == 1)
		std::cout << a.back() << '\n';
}

RPN::~RPN() {}

int RPN::multiply(int nb, int nb2)
{
	int res = nb * nb2;
	return res;
}

int RPN::some(int nb, int nb2)
{
	int res = nb + nb2;
	return res;
}

int RPN::division(int nb,int nb2)
{
	int res = nb / nb2;
	return res;
}

int RPN::less(int nb, int nb2)
{
	int res = nb - nb2;
	return res;
}