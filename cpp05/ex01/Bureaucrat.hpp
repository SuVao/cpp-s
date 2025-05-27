
#pragma once

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "iostream"
#include "string"
#include <stdexcept>
#include "Form.hpp"

class Bureaucrat
{
private:
	const std::string name;
	int grade_lvl;
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const std::string& name1, int lvl);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	const std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(const Form& a);
	class GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os,const Bureaucrat& me);

#endif