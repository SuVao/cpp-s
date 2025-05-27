
#include "inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade_lvl(150) {}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat::Bureaucrat(const std::string& name1, int lvl) : name(name1)
{
	if (lvl >150)
		throw Bureaucrat::GradeTooLowException();
	else if (lvl < 1) 
		throw Bureaucrat::GradeTooHighException();
	grade_lvl = lvl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The number is too high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The number is too low!\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->grade_lvl = other.grade_lvl;
	return (*this);
}

const std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade_lvl;
}

std::ostream& operator<<(std::ostream& os,const Bureaucrat& me)
{
	os << me.getName() << ", bureaucrat grade " << me.getGrade();
	return os;
}

void Bureaucrat::decrementGrade()
{
	if (grade_lvl >= 150)
		throw GradeTooLowException();
	grade_lvl++;
}

void Bureaucrat::incrementGrade()
{
	if (grade_lvl <= 1)
		throw GradeTooHighException();
	grade_lvl--;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade_lvl(other.grade_lvl)
{}

void Bureaucrat::signForm(Form& a)
{
	try {
        a.beSigned(*this);
        std::cout << name << " signed " << a.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << name << " couldn't sign " << a.getName()
                  << " because " << e.what() << std::endl;
    }
}