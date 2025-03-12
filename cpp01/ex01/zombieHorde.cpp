
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name1)
{
    Zombie*  horda;
    horda = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        horda[i] = Zombie(name1);
    }
    return horda;
}
