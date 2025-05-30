
#include "../inc/Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}


AForm* Intern::makeForm(const std::string& form, const std::string& target)
{
	std::string formNames[3] = { "robotomy request", "shrubberycreation form", "presidentialpardon form" };

	AForm* (*formCreators[3])(const std::string&) = {
		[](const std::string& t) -> AForm* { return new RobotomyRequestForm(t); },
		[](const std::string& t) -> AForm* { return new ShrubberyCreationForm(t); },
		[](const std::string& t) -> AForm* { return new PresidentialPardonForm(t); }
	};

	for (int i = 0; i < 3; ++i) {
		if (form == formNames[i]) {
			std::cout << "Intern creates " << form << std::endl;
			return formCreators[i](target);
		}
	}

	throw TheFormDontExist();
}

const char* Intern::TheFormDontExist::what() const throw()
{
	return "This Form doesn't exist!\n";
}