
#include "../inc/ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

int ScalarConverter::getInt()
{
    return static_cast<int>(std::strtol(type1.c_str(), NULL, 10));
}

double ScalarConverter::getDouble()
{
    return static_cast<double>(std::strtod(type1.c_str(), NULL));    
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
    if (type1 == "nanf")
        return true;
    if (type1 == "-inf")
        return true;
    if (type1 == "+inf")
        return true;
    if (type1 == "-inff")
        return true;
    if (type1 == "+inff")
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

bool ScalarConverter::limits()
{
    try {
        int i = getInt();
        float f = getFloat();
        double d = getDouble();

        if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
            return false;
        if (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
            return false;
    } catch (const std::exception&) {
        return false;
    }
    return true;
}

void ScalarConverter::convert(const std::string& type)
{
    ScalarConverter a(type);
    if (!a.limits())
        std::cout << "Impossible conversion, out of bounds.\n";
    if (a.is_int())
    {
        if (!a.is_char())
            std::cout << "Char: Non displayable" << '\n';
        else   
            std::cout << "Char: '" << a.getChar() << "'" << '\n';
        std::cout << "Int: " << (a.getInt()) << '\n';
        std::cout << "Float: " << std::fixed << std::setprecision(1) << (a.getFloat()) << "f" << '\n';
        std::cout << "Double: " << std::fixed << std::setprecision(1) << (a.getDouble()) << '\n';
    }
    else if (a.is_double())
    {
        if (a.is_char())
            std::cout << "Char: '" << a.getChar() << "'" << std::endl;
        else
            std::cout << "Char: Non displayable" << std::endl;
        if (a.getInt())
            std::cout << "Int: " << a.getInt() << std::endl;
        else
            std::cout << "Int: Impossible" << std::endl;
        std::cout << "Float: " << std::fixed << std::setprecision(1) << (a.getDouble()) << "f" << '\n';
        std::cout << "Double: " << std::fixed << std::setprecision(1) << (a.getDouble()) << '\n';
    }
    else if (a.is_float())
    {
        if (a.is_char())
            std::cout << "Char: '" << a.getChar() << "'" << '\n';
        else
            std::cout << "Char: Non displayable" << '\n';
        if (a.is_int())
            std::cout << "Int: " << a.getInt() << '\n';
        else
            std::cout << "Int: Impossible" << '\n';
        std::cout << "Float: " << std::fixed << std::setprecision(1) << (a.getFloat()) << "f" << '\n';
        std::cout << "Double: " << std::fixed << std::setprecision(1) << (a.getDouble()) << '\n';
    }
    else if (a.is_char())
    {
        if (a.is_char())
            std::cout << "Char: '" << a.getChar() << "'" << '\n';
        else
            std::cout << "Char: Non displayable" << '\n';
        int val = a.getChar();
        if (val >= 32 && val <= 126)
            std::cout << "Int: " << val << '\n';
        else
            std::cout << "Int: impossible\n";
        std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << '\n';
        std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << '\n';
    
    }
    else if (a.is_pseudo())
    {
        a.Display_pseudo();
    }
    else
    {
        std::cerr << "Impossible conversion, alpha string or out of bounds.\n";
    }   
}

