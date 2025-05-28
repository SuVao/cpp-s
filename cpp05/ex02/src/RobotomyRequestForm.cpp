
#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
	std::cout << "RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called\n";
}

//RobotomyRequestForm::RobotomyRequestForm(const std::string& name, int signe, int exe) : AForm(name, signe, exe), target(name){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name) : AForm("RobotomyRequestForm", 72, 45), target(name)
{
	std::cout << "RobotomyRequestForm constructor called\n";
}

void  RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getSigne())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getGrade_lvl())
	{
        throw AForm::GradeTooLowException();
	}

	std::cout << "* DRILLING NOISES * 🔧 bzzzzzzzzz...\n";

    std::srand(std::time(0));
    if (std::rand() % 2 == 0)
	{
        std::cout << target << " has been successfully robotomized ✅\n";
	}
    else
	{
        std::cout << "Robotomy failed on " << target << " ❌\n";
	}
}

