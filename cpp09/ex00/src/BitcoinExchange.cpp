
#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : a() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::Inserting(const std::string& date, double& valeu)
{
	a[date] = valeu;
}

void BitcoinExchange::Print()
{
	for (std::map<std::string, double>::iterator it = a.begin(); it != a.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

double BitcoinExchange::search_and_multiple(double val, std::string date)
{
	std::map<std::string, double>::iterator it = a.lower_bound(date);
	std::string date1 = it->first;

	if (it != a.end() && it->first == date)
		return it->second * val;
	if (it != a.begin())
	{
		--it;
		return it->second * val;
	}
	return 0; 
}