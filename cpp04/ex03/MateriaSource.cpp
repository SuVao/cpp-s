
#include "MateriaSource.hpp"

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
            return;
        }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0;i < 4; i++)
		if (materiaStore[i] && materiaStore[i]->getType() == type)
		{
			return materiaStore[i]->clone();
		}
	return NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0;i < 4; i++)
		if (materiaStore[i] != NULL)
		{
			delete materiaStore[i];
			materiaStore[i] = NULL;
		}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.materiaStore[i])
			materiaStore[i] = other.materiaStore[i]->clone();
		else
			materiaStore[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete materiaStore[i];
            materiaStore[i] = NULL;
        }
        for (int i = 0; i < 4; ++i)
        {
            if (other.materiaStore[i])
                materiaStore[i] = other.materiaStore[i]->clone();
            else
                materiaStore[i] = NULL;
        }
    }
    return *this;
}
