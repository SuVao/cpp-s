
#pragma once

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool signe;
	const int grade_signe;
	const int grade_lvl_exe;
public:
	Form();
	~Form();
	Form(const Form& other);
	Form(const std::string& name1, int grade_signe1, int grade_lvl1);
	Form& operator=(const Form& other);
	void beSigned(Bureaucrat a);
	const std::string getName() const;
	bool getSigne() const;
	const int getGrade_lvl() const;
	const int getGrade_signe() const;
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, Form& e);

#endif