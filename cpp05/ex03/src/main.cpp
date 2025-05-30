#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Intern.hpp"

int main() {
	try {
		Intern intern;
		Bureaucrat boss("Boss", 1);  // 1 é a nota mais alta
		AForm* rrf = intern.makeForm("robotomy request", "Bender");

		if (rrf) {
			rrf->beSigned(boss);       // Certifique-se que o formulário esteja assinado antes de executar
			rrf->execute(boss);        // ✅ passar o Bureaucrat como argumento
			delete rrf;
		}
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
