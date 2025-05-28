
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) : AForm(name, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() 
{
	std::cout << "PresidentialPardonForm destructor called!\n";
}

void PresidentialPardonForm::exe_AForm(const Bureaucrat& exe)
{
	if (exe.getGrade() < this->getGrade_signe() && exe.getGrade() < this->getGrade_lvl())
		Bureaucrat::signForm(*this);

}