/* 
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete j;
	delete i;
	delete meta;
	return 0;
} */
#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Construindo Animais ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n=== Testando getType() ===" << std::endl;
    std::cout << "dog type: " << dog->getType() << std::endl;
    std::cout << "cat type: " << cat->getType() << std::endl;
    std::cout << "meta type: " << meta->getType() << std::endl;

    std::cout << "\n=== Testando makeSound() ===" << std::endl;
    cat->makeSound(); // Deve fazer som de gato
    dog->makeSound(); // Deve fazer som de cão
    meta->makeSound(); // Pode ser genérico ou nada

    std::cout << "\n=== Testando polimorfismo incorreto (WrongAnimal) ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound(); // Vai fazer som de WrongAnimal porque makeSound() não é virtual
    wrongMeta->makeSound();

    std::cout << "\n=== Testando diretamente a classe WrongCat ===" << std::endl;
    const WrongCat* realWrongCat = new WrongCat();
    realWrongCat->makeSound(); // Aqui vai fazer som de WrongCat

    std::cout << "\n=== Limpando memória ===" << std::endl;
    delete meta;
    delete dog;
    delete cat;
    delete wrongMeta;
    delete wrongCat;
    delete realWrongCat;

    return 0;
}
