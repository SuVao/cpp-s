
#include "Harl.hpp"

void    Harl::info( void )
{
	std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
    enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl;
    std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming for \
    years, whereas you started working here just last month." << std::endl;
}

void Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl;
    std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain( std::string level )
{
    std::string level1[] = { "WARNING", "DEBUG", "INFO", "ERROR" };
	void (Harl::*functions[])() = { &Harl::warning, &Harl::debug, &Harl::info, &Harl::error};
	int flag = 0;

	//switch case

	for (int i = 0; i < 4; i++)	
	{
		if (level1[i] == level || flag == 1)
		{
			(this->*functions[i])();
			flag = 1;
			if (i == 3)
				return ;
		}
	}
	std::cout << "Level not founded!" << std::endl;
}
