
#pragma once

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string target;
public:
	PresidentialPardonForm();
	//PresidentialPardonForm(const std::string& name, int signe, int exe);
	PresidentialPardonForm(const std::string& name);
	~PresidentialPardonForm();
	void  execute(Bureaucrat const & executor) const;
	
};

#endif