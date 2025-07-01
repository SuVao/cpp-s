
#include "../inc/Span.hpp"

Span::~Span() {}

Span::Span(unsigned int m) : size(m) 
{
	store.reserve(size);
}

void Span::addNumber(int nb) 
{
	if (store.size() >= store.capacity())
		throw error();
	store.push_back(nb);
}

int Span::shortestSpan()
{
	if (store.size() < 2)
		throw error_empty();
	std::vector<int> a = store;
	std::sort(a.begin(), a.end());

	int minS = std::abs(a[1] - a[0]);
	for (size_t i = 1; i < a.size() - 1; i++)
	{
		int newM = std::abs(a[i+1] - a[i]);
		if (newM < minS)
			minS = newM;
	}
	return (minS);
}


int Span::longestSpan()
{
	if (store.size() < 2)
		throw error_empty();
	int min = *std::min_element(store.begin(), store.end());
	int max = *std::max_element(store.begin(), store.end());
	return max - min;
}

void Span::addMultiple(unsigned int nbrs)
{
	if (store.size() + nbrs > store.capacity())
		throw error_nbrs();
	for (unsigned int i = 0; i < nbrs; i++)
	{
		int o = std::rand() % 1000;
		store.push_back(o);
	}
}