#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try 
    {
        Bureaucrat alice("Alice", 5);
        Bureaucrat bob("Bob", 150);
        Form contract("Top Secret Contract", 10, 5);
        std::cout << contract << std::endl;
        std::cout << "\nTrying to sign with Bob (grade too low):\n";
        bob.signForm(contract); // Deve falhar
        std::cout << "\nTrying to sign with Alice:\n";
        alice.signForm(contract); // Deve funcionar
        std::cout << "\nForm state after signing attempts:\n";
        std::cout << contract << std::endl;
    } catch (const std::exception& e)
    {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}
