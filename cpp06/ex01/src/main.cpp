
#include "../inc/Serialization.hpp"

int main()
{
	Data data;
    data.val = 42;
    data.name = "Pedro";

    uintptr_t raw = Serialization::serialize(&data);

    std::cout << "Serializado: " << raw << std::endl;

    Data* restored = Serialization::deserialize(raw);

    std::cout << "Restaurado ID: " << restored->val << std::endl;
    std::cout << "Restaurado Nome: " << restored->name << std::endl;

    return 0;
}