
#include "Form.hpp"

Form::Form() : name("Default"), signe(false), grade_lvl_exe(150), grade_signe(150){}

Form::~Form(){ std::cout << "Form destructor called\n";}

Form::Form(const Form& other) : name(other.name), signe(other.signe), \
	grade_lvl_exe(other.grade_lvl_exe), grade_signe(other.grade_signe){}

Form::Form(const std::string& name1, int grade_signe1, int grade_lvl1) : name(name1), signe(false), grade_signe(grade_signe1), grade_lvl_exe(grade_lvl1)
{
	if (grade_signe < 1 || grade_lvl_exe < 1)
		throw Form::GradeTooHighException();
	else if (grade_signe > 150 || grade_lvl_exe > 150)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		signe = other.signe;
	}
	return *this;
}

const int Form::getGrade_lvl() const
{
	return (grade_lvl_exe);
}

const int Form::getGrade_signe() const
{
	return grade_signe;
}

const std::string Form::getName() const
{
	return name;
}

bool Form::getSigne() const
{
	return signe;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too Low!";
}

void Form::beSigned(Bureaucrat a)
{
	if (a.getGrade() > getGrade_signe())
		throw GradeTooLowException();
	signe = true;
}

std::ostream& operator<<(std::ostream& os, Form& e)
{
	
}