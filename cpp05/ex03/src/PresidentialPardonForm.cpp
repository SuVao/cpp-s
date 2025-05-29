
#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default")
{
	std::cout << "PresidentialPardonForm constructor called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) : AForm("PresidentialPardonForm", 25, 5), target(name)
{
	std::cout << "PresidentialPardonForm constructor called!\n";
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
	std::cout << "PresidentialPardonForm destructor called!\n";
}


void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!getSigne())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGrade_lvl())
        throw AForm::GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

