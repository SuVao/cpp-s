#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat bob("Bob", 1); // Grade alto (melhor)
        Bureaucrat tom("Tom", 145); // Grade médio/baixo

        ShrubberyCreationForm shrubForm("Home");
        RobotomyRequestForm robotForm("Bender");
        PresidentialPardonForm pardonForm("Alice");

        std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
        tom.signForm(shrubForm);
        tom.exe_AForm(shrubForm); // Tom pode assinar, mas não executar

        std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
        bob.signForm(robotForm);
        bob.exe_AForm(robotForm);

        std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
        bob.signForm(pardonForm);
        bob.exe_AForm(pardonForm);
    }
    catch (const std::exception& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    return 0;
}
