#include <iostream>
#include <vector>
#include "../inc/easyfind.hpp"

int main()
{
	std::vector<int> a;
	a.push_back(9);
	a.push_back(10);
	a.push_back(2);
	a.push_back(22);
	a.push_back(7);
	a.push_back(1);
	a.push_back(4);
	a.push_back(8);
	int o = 2;

	try
	{
		std::vector<int>::const_iterator it = easyfind(a, o);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
