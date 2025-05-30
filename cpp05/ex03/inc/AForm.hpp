
#pragma once

#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>  // std::rand, std::srand
#include <ctime> 

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool signe;
	const int grade_signe;
	const int grade_lvl_exe;
public:
	AForm();
	virtual ~AForm();
	AForm(const AForm& other);
	AForm(const std::string& name1, int grade_signe1, int grade_lvl1);
	AForm& operator=(const AForm& other);
	virtual AForm& beSigned(Bureaucrat a);
	std::string getName() const;
	bool getSigne() const;
	int getGrade_lvl() const;
	int getGrade_signe() const;
 	AForm(const std::string& target);
	virtual void execute(const Bureaucrat& executor) const = 0;
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, AForm& e);

#endif