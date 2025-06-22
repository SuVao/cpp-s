
#include "../inc/iter.hpp"

template <typename T>
void print(const T& ele)
{
	std::cout << ele << "\n";
}

template <typename adr, typename len, typename printer>
void iter(adr* adrr, len le, printer a)
{
	for (len i = 0; i < le; i++)
		a(adrr[i]);
}

int main()
{
	std::string phase = "Hello World\n";

	iter(phase.data(), phase.length(), print<char>);
}
