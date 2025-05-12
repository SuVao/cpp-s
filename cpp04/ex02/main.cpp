/* 
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const AAnimal* AAnimals[4];
    for (int i = 0; i < 2; ++i)
        AAnimals[i] = new Dog();
    for (int i = 2; i < 4; ++i)
        AAnimals[i] = new Cat();

    for (int i = 0; i < 4; ++i)
        delete AAnimals[i];

    // Teste deep copy
    Dog *basic = new Dog();
    Dog n;
    basic->setIdea_d(0, "Chase the cat");
    n = *basic;
    delete(basic);
    n.getIdea_d(0);
     Dog copy = *basic;
    copy.setIdea_d(0, "Eat food"); 

    // Deve imprimir ideias diferentes
   // std::cout << "Basic idea: " << basic.getIdea_d(0) << std::endl;
    //std::cout << "Copy idea: " << copy.getIdea_d(0) << std::endl;

    return 0;
}
 */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    std::cout << "== Teste de criação e destruição com polimorfismo ==" << std::endl;
    const AAnimal* animals[4];
    for (int i = 0; i < 2; ++i)
        animals[i] = new Dog();
    for (int i = 2; i < 4; ++i)
        animals[i] = new Cat();
    for (int i = 0; i < 4; ++i)
        delete animals[i];

    std::cout << "\n== Teste de cópia profunda (deep copy) ==" << std::endl;
    Dog* original = new Dog();
    original->setIdea_d(0, "Chase the cat");
    original->setIdea_d(1, "Bark at the mailman");

    Dog copy;
    copy = *original;

    delete original;

    std::cout << "Ideia 0 do copy (deve ser 'Chase the cat'): " << copy.getIdea_d(0) << std::endl;
    std::cout << "Ideia 1 do copy (deve ser 'Bark at the mailman'): " << copy.getIdea_d(1) << std::endl;

    std::cout << "\n== Teste de cópia por construtor (deep copy) ==" << std::endl;
    Cat c1;
    c1.setIdea_c(0, "Sleep on the keyboard");

    Cat c2(c1); // cópia por construtor
    c2.setIdea_c(0, "Jump on the table");

    std::cout << "Ideia do c1 (deve ser 'Sleep on the keyboard'): " << c1.getIdea_c(0) << std::endl;
    std::cout << "Ideia do c2 (deve ser 'Jump on the table'): " << c2.getIdea_c(0) << std::endl;

    std::cout << "\n== Teste com destruição direta ==" << std::endl;
    Dog stackDog;
    Cat stackCat;

    return 0;
}
