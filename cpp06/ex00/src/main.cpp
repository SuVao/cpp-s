/* Escreva uma classe ScalarConverter que contenha apenas um método estático "convert"
que receberá como parâmetro uma representação em string de um literal C++ na sua forma
mais comum e apresentará o seu valor na seguinte série de tipos escalares:
•char
•int
•float
•double
Como esta classe não necessita de armazenar nada, não deve ser instanciável pelos utilizadores.
Exceto para os parâmetros char, apenas será utilizada a notação decimal.
Exemplos de literais char: 'c', 'a', ...
Para simplificar, note que os caracteres não exibíveis não devem ser utilizados como
entradas. Se uma conversão para char não for exibível, imprima uma mensagem informativa.
Exemplos de literais int: 0, -42, 42...
Exemplos de literais float: 0.0f, -4.2f, 4.2f...
Também tem de lidar com estes pseudoliterais (para fins científicos, por exemplo): -inff, +inff,
e nanf.

C++ - Módulo 06 Conversões em C++
Exemplos de literais double: 0.0, -4.2, 4.2...
Também tem de lidar com estes pseudoliterais (para fins científicos, por exemplo): -inf, +inf e
nan. */


#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal_value>" << std::endl;
        return 1;
    }

    int i = 98;

    std::cout << static_cast<char>(i) << std::endl;

    ScalarConverter::convert(argv[1]);
    return 0;
}
