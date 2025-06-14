
#include "../inc/ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

int ScalarConverter::getInt()
{
    return (std::strtol(type1.c_str(), NULL, 10));
}

double ScalarConverter::getDouble()
{
    return (std::strtod(type1.c_str(), NULL));    
}

float ScalarConverter::getFloat()
{
    return static_cast<float>(std::strtof(type1.c_str(), NULL));
}

char ScalarConverter::getChar()
{
    if (type1.length() == 3 && type1[0] == '\'' && type1[2] == '\'')
		return type1[1];
	return type1[0];
}

bool ScalarConverter::is_int()
{
    if (type1.empty())
        return false;
    size_t i = 0;
    if (type1[0] == '-' || type1[0] == '+')
        i = 1;
    if (i == type1.length())
        return false;
    for (; i < type1.length(); i++)
        if (!isdigit(type1[i]))
            return false;
    long val = std::strtol(type1.c_str(), NULL, 10);
    if (val  >= INT_MAX || val <= INT_MIN)
        return false;
    return true;
}

bool ScalarConverter::is_double()
{
    if (type1.empty())
        return false;
    size_t i = 0;
    if (type1[0] == '-' || type1[0] == '+')
        i = 1;
    if (i == type1.length())
        return false;
    size_t f = type1.find('.');
    for (;i < f; i++)
        if (!isdigit(type1[i]))
            return false;
    i++;
    for (;i < type1.length(); i++)
        if (!isdigit(type1[i]))
            return false;
    return true;
}

bool ScalarConverter::is_float()
{
    if (type1.empty())
        return false;
    size_t i = 0;
    if (type1[0] == '-' || type1[0] == '+')
        i = 1;
    if (i == type1.length())
        return false;
    size_t f = type1.find('.');
    for (;i < f; i++)
        if (!isdigit(type1[i]))
            return false;
    i++;
    for (;i < type1.length(); i++)
        if (!isdigit(type1[i]) && type1[i] != 'f' && type1[i] != 'F')
            return false;
    i--;
    if (type1[i] != 'f' && type1[i] != 'F')
        return false;
    return true;
}

bool   ScalarConverter::is_char()
{
    if (type1.empty())
        return false;

    if (type1.length() == 3 && type1[0] == '\'' && type1[2] == '\'')
		return true;
	else if (type1.length() == 1 && !isdigit(type1[0])) 
		return true;
    
    int val = getInt();
    if (val >= 32 && val <= 126)
        return true;
	
    return false;
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const std::string& a) : type1(a) {}

bool ScalarConverter::is_pseudo()
{
    if (type1 == "nan")
        return true;
    if (type1 == "-inf")
        return true;
    if (type1 == "+inf")
        return true;
    return false;
}

void ScalarConverter::Display_pseudo()
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << type1 << "f\n";
    std::cout << "double: " << type1 << "\n";
}

void ScalarConverter::convert(const std::string& type)
{
    ScalarConverter a(type);
    if (a.is_int())
    {
        if (!a.is_char())
            std::cout << "Char: Non displayable" << std::endl;
        else   
            std::cout << "Char: '" << a.getChar() << "'" << std::endl;
        std::cout << "Int: " << static_cast<int>(a.getInt()) << std::endl;
        std::cout << "Float: " << std::fixed << std::setprecision(1) << (a.getFloat()) << "f" << std::endl;
        std::cout << "Double: " << std::fixed << std::setprecision(1) << (a.getDouble()) << std::endl;
    }
    else if (a.is_double())
    {
        if (a.is_char())
            std::cout << "Char: '" << a.getChar() << "'" << std::endl;
        else
            std::cout << "Char: Non displayable" << std::endl;
        if (a.is_int())
            std::cout << "Int: " << a.getInt() << std::endl;
        else
            std::cout << "Int: Impossible" << std::endl;
        std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(a.getDouble()) << "f" << std::endl;
        std::cout << "Double: " << std::fixed << std::setprecision(1) << (a.getDouble()) << std::endl;
    }
    else if (a.is_float())
    {
        if (a.is_char())
            std::cout << "Char: '" << a.getChar() << "'" << std::endl;
        else
            std::cout << "Char: Non displayable" << std::endl;
        if (a.is_int())
            std::cout << "Int: " << a.getInt() << std::endl;
        else
            std::cout << "Int: Impossible" << std::endl;
        std::cout << "Float: " << std::fixed << std::setprecision(1) << (a.getFloat()) << "f" << std::endl;
        std::cout << "Double: " << std::fixed << std::setprecision(1) << (a.getDouble()) << std::endl;
    }
    else if (a.is_char())
    {
        if (a.is_char())
            std::cout << "Char: '" << a.getChar() << "'" << std::endl;
        else
            std::cout << "Char: Non displayable" << std::endl;
        int val = a.getChar();
        if (val >= 32 && val <= 126)
            std::cout << "Int: " << val << std::endl;
        else
            std::cout << "Int: impossible\n";
        std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
        std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
    
    }
    else if (a.is_pseudo())
    {
        a.Display_pseudo();
    }
    else
    {
        std::cout << "Impossible conversion, alpha string or out of bounds.\n";
    }   
}