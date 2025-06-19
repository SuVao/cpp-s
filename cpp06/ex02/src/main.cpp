
#include "../inc/Base.hpp"
#include "../inc/C.hpp"
#include "../inc/B.hpp"
#include "../inc/A.hpp"
#include <cstdlib>
#include <ctime>

Base* generate()
{
    std::srand(std::time(0));
    int i = std::rand() % 3 + 1;
    std::cout << i << std::endl;
    switch (i)
    {
        case (1): std::cout << "Returning A\n"; return new A();
        case (2): std::cout << "Returning B\n"; return new B();
        case (3): std::cout << "Returning C\n"; return new C();
    }
    std::cout << "aqui\n";
    return NULL;
}
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknow\n";
}

void identify(Base& p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(&p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(&p))
        std::cout << "C\n";
    else
        std::cout << "Unknow\n";
}

int main()
{
    Base* O = generate();

    identify(*O);
    identify(O);
    delete O;
}