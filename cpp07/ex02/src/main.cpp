
#include "../inc/Array.hpp"

int main() {
    try {
        Array<int> a(9);

        for (size_t i = 0; i < a.size(); ++i) 
            a[i] = static_cast<int>(i * 10);

        for (size_t i = 0; i < a.size(); ++i) {
            std::cout << "a[" << i << "] = " << a[i] << std::endl;
        }

        std::cout << "Tentando acessar a[10]..." << std::endl;
        std::cout << a[10] << std::endl;  


    } catch (const std::out_of_range& e) {
        std::cerr << "Exceção capturada: " << e.what() << std::endl;
    }

	try {
   		const Array<int> b(3);
		size_t index = 2;
		std::cout << "Acessando array const: b[" << index << "] = " << b[index] << std::endl;
	} catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}