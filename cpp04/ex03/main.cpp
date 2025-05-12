/* 
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    
    return 0;
} */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

void separator(const std::string& title) {
	std::cout << "\n--- " << title << " ---\n";
}

int main() {
	separator("1. Criação de MateriaSource e Aprendizado");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); // deve ignorar (máximo 4)

	separator("2. Criação de Personagem e Equipar Materias");
	ICharacter* me = new Character("Pedro");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp); // não deve equipar (máximo 4)

	separator("3. Usar todas as Materias");
	ICharacter* bob = new Character("Bob");
	for (int i = 0; i < 4; i++)
		me->use(i, *bob);

	separator("4. Usar índice inválido");
	me->use(-1, *bob); // fora do range
	me->use(4, *bob);  // fora do range

	separator("5. Testar unequip e uso de slot vazio");
	me->unequip(1);    // unequipa cure
	me->use(1, *bob);  // deve não fazer nada ou logar

	separator("6. Testar deep copy de personagem");
	Character* clone = new Character(*(Character*)me);
	clone->use(0, *bob); // deve funcionar
	me->unequip(0);
	clone->use(0, *bob); // deve ainda funcionar (deep copy)

	separator("7. Testar deletar personagem original");
	delete me;
	clone->use(2, *bob); // deve ainda funcionar

	separator("8. Testar criar materia inválida");
	AMateria* invalid = src->createMateria("fire");
	if (!invalid)
		std::cout << "Materia 'fire' inválida como esperado.\n";

	separator("9. Testar copia de MateriaSource");
	MateriaSource* src2 = new MateriaSource(*((MateriaSource*)src));
	tmp = src2->createMateria("ice");
	bob->equip(tmp);
	bob->use(0, *clone);

	separator("10. Cleanup Final");
	delete clone;
	delete bob;
	delete src;
	delete src2;

	return 0;
}
