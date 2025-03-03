#include <iostream>

char iswalpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        for (int i = 1; i < ac; i++)
        {
            for (int j = 0; av[i][j]; j++)
            {
                if (iswalpha(av[i][j]))
                    std::cout << (char)toupper(av[i][j]);
                else
                    std::cout << av[i][j];
            }
        }
        std::cout << std::endl;
    }
}
