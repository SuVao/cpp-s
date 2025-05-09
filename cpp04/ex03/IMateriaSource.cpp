
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        materiaStore[i] = NULL;
}

void    MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < 4; i++)
        if (materiaStore[i] == NULL)
        {
            materiaStore[i] = materia;
            break;
        }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    
}