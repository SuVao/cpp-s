
#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) : AForm(name, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() 
{
	std::cout << "PresidentialPardonForm destructor called!\n";
}
/* 
void PresidentialPardonForm::exe_AForm(const Bureaucrat& exe)
{
	if (!getSigne())
		throw AForm::;
} */