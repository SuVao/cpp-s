
#include "Zombie.hpp"

int main()
{
    Zombie *Zombie_heap;
    std::string input;

    std::cout << "Give me a name!" << std::endl;
    std::cin >> input;
    Zombie_heap = newZombie(input + " heap");
    Zombie_heap->announce();
    randomChump(input + " stack");
    delete Zombie_heap;
}
