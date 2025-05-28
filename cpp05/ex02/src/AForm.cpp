
#include "../inc/AForm.hpp"

AForm::AForm() : name("Default"), signe(false), grade_signe(150), grade_lvl_exe(150){}

AForm::~AForm(){ std::cout << "AForm destructor called\n";}

AForm::AForm(const AForm& other) : name(other.name), signe(other.signe), \
	grade_signe(other.grade_signe), grade_lvl_exe(other.grade_lvl_exe){}

AForm::AForm(const std::string& name1, int grade_signe1, int grade_lvl1) : name(name1), signe(false), grade_signe(grade_signe1), grade_lvl_exe(grade_lvl1)
{
	if (grade_signe < 1 || grade_lvl_exe < 1)
		throw AForm::GradeTooHighException();
	else if (grade_signe > 150 || grade_lvl_exe > 150)
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		signe = other.signe;
	}
	return *this;
}

int AForm::getGrade_lvl() const
{
	return (grade_lvl_exe);
}

int AForm::getGrade_signe() const
{
	return grade_signe;
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getSigne() const
{
	return signe;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too Low!";
}

AForm& AForm::beSigned(Bureaucrat a)
{
	if (a.getGrade() > getGrade_signe())
		throw GradeTooLowException();
	signe = true;
	return *this;
}

std::ostream& operator<<(std::ostream& os, AForm& e)
{
	os << "AForm \"" << e.getName()
		<< "\", signed: " << (e.getSigne() ? "yes" : "no")
		<< ", grade to sign: " << e.getGrade_signe()
		<< ", grade to execute: " << e.getGrade_lvl();
	return os;
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form cannot be executed because it is not signed.";
}
