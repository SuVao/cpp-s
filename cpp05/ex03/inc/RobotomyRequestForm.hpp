
#pragma once 

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string target;
public:
	RobotomyRequestForm();
	//RobotomyRequestForm(const std::string& name, int signe, int exe);
	RobotomyRequestForm(const std::string& name);
	~RobotomyRequestForm();
	void  execute(Bureaucrat const & executor) const;
};

#endif