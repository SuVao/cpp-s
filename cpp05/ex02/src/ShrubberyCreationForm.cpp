
#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
	std::cout << "ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) : AForm("ShrubberyCreationForm", 145, 137), target(name)
{
	std::cout << "ShrubberyCreationForm constructor called\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getSigne())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGrade_lvl())
        throw AForm::GradeTooLowException();

    std::ofstream file((target + "_shrubbery").c_str());
    if (!file)
    {
        std::cerr << "Failed to create file: " << target << "_shrubbery" << std::endl;
        return;
    }

    file << "       _-_\n"
            "    /~~   ~~\\\n"
            " /~~         ~~\\\n"
            "{               }\n"
            " \\  _-     -_  /\n"
            "   ~  \\\\ //  ~\n"
            "_- -   | | _- _\n"
            "  _ -  | |   -_\n"
            "      // \\\\" << std::endl;

    file.close();

    std::cout << "ShrubberyCreationForm executed: " << target << "_shrubbery created 🌳" << std::endl;
}