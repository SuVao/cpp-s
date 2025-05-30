
#pragma once

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern();
    ~Intern();
    //Intern(const Intern& other);
    AForm* makeForm(const std::string& form, const std::string& target);
	class TheFormDontExist : public std::exception
	{
		virtual const char* what() const throw();
	};
};

AForm* createPresidential(const std::string& target);
AForm* createShrubbery(const std::string& target);
AForm* createRobotomy(const std::string& target);
	

#endif