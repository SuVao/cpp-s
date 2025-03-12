
#include "Zombie.hpp"

int main()
{
    std::string input1;
    std::string input2;
    int N;

    std::cout << "write the name of the zombies: ";
    std::cin >> input1;
    std::cout << "write the number of zombies for the horder: ";
    std::cin >> input2;
    N = std::atoi(input2.c_str());
    if (N <= 0)
    {
        std::cout << "Invalid number of zombies!" << std::endl;
        return -1;
    }
    Zombie *zombies = zombieHorde(N, input1);
    if (!zombies)
    {
        std::cout << "Fail to create zombies!" << std::endl;
        return -1;
    }
    for (int i = 0; i < N; i++)
        zombies[i].announce();
    delete[] zombies;
}
