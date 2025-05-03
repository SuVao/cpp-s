
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const Animal* animals[4];
    for (int i = 0; i < 2; ++i)
        animals[i] = new Dog();
    for (int i = 2; i < 4; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < 4; ++i)
        delete animals[i];

    // Teste deep copy
    Dog basic;
    basic.setIdea_d(0, "Chase the cat");

    Dog copy = basic;
    copy.setIdea_d(0, "Eat food");

    // Deve imprimir ideias diferentes
    std::cout << "Basic idea: " << basic.getIdea_d(0) << std::endl;
    std::cout << "Copy idea: " << copy.getIdea_d(0) << std::endl;

    return 0;
}
