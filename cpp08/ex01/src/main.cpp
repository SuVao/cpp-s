
#include "../inc/Span.hpp"

int main()
{
	try
	{
		Span sp(5); // Cria um Span com capacidade para 5 números

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Erro: " << e.what() << std::endl;
	}

	return 0;
}