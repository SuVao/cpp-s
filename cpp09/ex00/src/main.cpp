
#include "../inc/BitcoinExchange.hpp"

int main(int ac, char** av)
{
	if ( ac != 2)
		return write(1,"Invalid Number of arguments!\n", 30);
	(void)av;
	std::ifstream a;
	std::ifstream b;
	BitcoinExchange c;
	b.open(av[1]);
	a.open("data.csv");
	if (!a || !b )
		return write(1,"Database didn't found!\n", 24);
	std::string l;
	std::string n;
	while (std::getline(a, l))
	{
		if (l.empty())
			break;
		
		size_t sep = l.find(',');
		if (sep == std::string::npos)
			continue; 

		std::string date = l.substr(0, sep);
		std::string valueStr = l.substr(sep + 1);
		std::stringstream val_temp(valueStr);
		double val;

		val_temp >> val;
		c.Inserting(date, val);
	}
	//c.Print();
	while (std::getline(b, n))
	{
		if (n.empty())
			break;
		if (!std::isdigit(n[0]))
			continue;
		size_t sep1 = n.find('|');
		if (sep1 == std::string::npos)
			std::cout << "Error bad input => " << n << '\n';
		else
		{
			std::string date1 = n.substr(0, sep1 - 1);
			std::string valueStr1 = n.substr(sep1 + 1);
			std::stringstream val_temp1(valueStr1);

			double val1;
			val_temp1 >> val1;
			val1 = c.search_and_multiple(val1, date1);
			if (val1 > std::numeric_limits<int>::max())
				std::cout << "Error: too large a number.\n";
			else
				std::cout << date1 << " =>" << valueStr1 << " = "<< val1 << '\n';
		}
		
	}

	a.close();
	b.close();
}