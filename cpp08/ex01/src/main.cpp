
#include "../inc/Span.hpp"

int main()
{
	try
	{
		Span sp(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		Span o(10);
		o.addNumber(10);
		o.addNumber(10);
		o.addNumber(10);
		o.addNumber(10);
		o.addNumber(10);
		o.addNumber(10);
		o.addMultiple(7);
		std::cout << "Longest Span: " << o.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Erro: " << e.what() << std::endl;
	}

	return 0;
}