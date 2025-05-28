/* #include "Bureaucrat.hpp"
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
        tom.executeForm(shrubForm); // Tom pode assinar, mas não executar

        std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
        bob.signForm(robotForm);
        bob.executeForm(robotForm);

        std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
        bob.signForm(pardonForm);
        bob.executeForm(pardonForm);
    }
    catch (const std::exception& e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    return 0;
}
 */
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void separator(const std::string &title) {
    std::cout << "\n\033[1;34m=== " << title << " ===\033[0m\n" << std::endl;
}

int main() {
    try {
        separator("BUREAUCRATS");
        Bureaucrat top("TopGrade", 1);
        Bureaucrat low("LowGrade", 150);
        Bureaucrat mid("MidGrade", 100);

        separator("SHRUBBERY FORM");
        ShrubberyCreationForm shrub("Backyard");

        // Tentativa de executar antes de assinar
        try {
            top.executeForm(shrub);
        } catch (const std::exception &e) {
            std::cerr << "Expected error (not signed): " << e.what() << std::endl;
        }

        // Baixo demais para assinar
        low.signForm(shrub);

        // Meio termo assina (grade >= 145)
        Bureaucrat signer("Signer", 145);
        signer.signForm(shrub);

        // Execução com grade insuficiente
        low.executeForm(shrub);

        // Execução com sucesso
        Bureaucrat executor("Executor", 137);
        executor.executeForm(shrub);

        separator("ROBOTOMY FORM");
        RobotomyRequestForm robot("RoboTarget");

        // Assina com sucesso
        top.signForm(robot);

        // Execução com baixa autoridade
        mid.executeForm(robot); // Falha (precisa de 45)

        // Execução com sucesso (top grade)
        top.executeForm(robot);

        // Executar várias vezes para testar aleatoriedade
        for (int i = 0; i < 5; ++i) {
            top.executeForm(robot);
        }

        separator("PRESIDENTIAL PARDON FORM");
        PresidentialPardonForm pardon("Criminal");

        // Assinar com grade baixa — deve falhar
        signer.signForm(pardon);

        // Assinar com sucesso
        top.signForm(pardon);

        // Tentar executar com grade insuficiente
        mid.executeForm(pardon);

        // Executar com sucesso
        top.executeForm(pardon);

        separator("EXECUTAR FORMULÁRIO NÃO ASSINADO");
        PresidentialPardonForm unsignedForm("UnluckyOne");
        try {
            top.executeForm(unsignedForm); // Deve lançar exceção
        } catch (const std::exception &e) {
            std::cerr << "Expected error: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Caught exception in main: " << e.what() << std::endl;
    }

    return 0;
}
