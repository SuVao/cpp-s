
#pragma once

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string target;
public:
	ShrubberyCreationForm();
	//ShrubberyCreationForm(const std::string& name, int signe, int exe);
	ShrubberyCreationForm(const std::string& name);
	~ShrubberyCreationForm();
	void  execute(Bureaucrat const & executor) const;
};

#endif