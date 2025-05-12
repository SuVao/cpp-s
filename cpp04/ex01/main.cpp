/* 
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
 */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    // Teste de criação e destruição com polimorfismo
    std::cout << "== Teste de criação e destruição com polimorfismo ==" << std::endl;
    const Animal* animals[4];
    
    // Criando 2 objetos de Dog e 2 de Cat
    for (int i = 0; i < 2; ++i)
        animals[i] = new Dog();
    for (int i = 2; i < 4; ++i)
        animals[i] = new Cat();
    
    // Destruindo os objetos criados
    for (int i = 0; i < 4; ++i)
        delete animals[i];

    // Teste de cópia profunda (deep copy)
    std::cout << "\n== Teste de cópia profunda com operador de cópia ==" << std::endl;
    Dog basic;
    basic.setIdea_d(0, "Chase the cat");

    // Criando uma cópia através do operador de cópia
    Dog copy = basic;
    copy.setIdea_d(0, "Eat food");

    // Verificando se as ideias são diferentes, indicando cópia profunda
    std::cout << "Ideia original (basic): " << basic.getIdea_d(0) << std::endl;
    std::cout << "Ideia copiada (copy): " << copy.getIdea_d(0) << std::endl;

    // Teste de construtor de cópia
    std::cout << "\n== Teste de construtor de cópia ==" << std::endl;
    Dog dog1;
    dog1.setIdea_d(1, "Bark loudly");

    // Criando uma cópia usando o construtor de cópia
    Dog dog2(dog1);

    std::cout << "Ideia do dog1: " << dog1.getIdea_d(1) << std::endl;
    std::cout << "Ideia do dog2: " << dog2.getIdea_d(1) << std::endl;

    // Teste de cópia do Brain no caso de Cat
    std::cout << "\n== Teste de cópia com o Cat ==" << std::endl;
    Cat cat1;
    cat1.setIdea_c(0, "Sleep on the chair");

    // Criando uma cópia do Cat
    Cat cat2(cat1);
    cat2.setIdea_c(0, "Chase the laser");

    std::cout << "Ideia do cat1: " << cat1.getIdea_c(0) << std::endl;
    std::cout << "Ideia do cat2: " << cat2.getIdea_c(0) << std::endl;

    // Teste de operador de atribuição
    std::cout << "\n== Teste de operador de atribuição ==" << std::endl;
    Dog dog3;
    dog3.setIdea_d(2, "Play fetch");

    Dog dog4;
    dog4 = dog3; // Testando operador de atribuição

    std::cout << "Ideia do dog3: " << dog3.getIdea_d(2) << std::endl;
    std::cout << "Ideia do dog4: " << dog4.getIdea_d(2) << std::endl;

    // Teste de destruição direta de objetos
    std::cout << "\n== Teste de destruição direta ==" << std::endl;
    Dog dog5;
    Cat cat3;

    // A destruição dos objetos ocorrerá quando sairmos do escopo
    std::cout << "Objetos Dog e Cat destruídos ao fim do escopo." << std::endl;

    return 0;
}
