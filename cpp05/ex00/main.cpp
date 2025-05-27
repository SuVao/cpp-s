#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("Alice", 2);
		std::cout << a << std::endl;

		std::cout << "Incrementing grade..." << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;

		std::cout << "Trying to increment beyond limit..." << std::endl;
		a.incrementGrade(); // Vai lançar exceção
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---\n" << std::endl;

	try {
		Bureaucrat b("Bob", 149);
		std::cout << b << std::endl;

		std::cout << "Decrementing grade..." << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;

		std::cout << "Trying to decrement beyond limit..." << std::endl;
		b.decrementGrade(); // Vai lançar exceção
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---\n" << std::endl;

	try {
		Bureaucrat c("Charlie", 0); // Muito alto
	} catch (std::exception &e) {
		std::cout << "Exception caught during Charlie creation: " << e.what() << std::endl;
	}

	try {
		Bureaucrat d("David", 151); // Muito baixo
	} catch (std::exception &e) {
		std::cout << "Exception caught during David creation: " << e.what() << std::endl;
	}
}
