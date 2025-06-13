
#include "../inc/ScalarConverter.hpp"

/* ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{
    *this = other;
    return *this;
}
 */
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
    //int val = getInt();
    //if (val >= 32 && val <= 126)
    //    return static_cast<char>(val);
    //return (0);
    if (type1.length() == 3 && type1[0] == '\'' && type1[2] == '\'')
		return type1[1];
	return type1[0];
}

bool ScalarConverter::is_int(const std::string& a)
{
    if (a.empty())
        return false;
    size_t i = 0;
    if (a[0] == '-' || a[0] == '+')
        i = 1;
    if (i == a.length())
        return false;
    for (; i < a.length(); i++)
        if (!isdigit(a[i]))
            return false;
    long val = std::strtol(a.c_str(), NULL, 10);
    if (val  >= INT_MAX || val <= INT_MIN)
    {
        std::cout << "Number out of range!\n";
        return false;
    }
    return true;
}

bool ScalarConverter::is_double(const std::string& a)
{
    if (a.empty())
        return false;
    size_t i = 0;
    if (a[0] == '-' || a[0] == '+')
        i = 1;
    if (i == a.length())
        return false;
    size_t f = a.find('.');
    for (;i < f; i++)
        if (!isdigit(a[i]))
            return false;
    i++;
    for (;i < a.length(); i++)
        if (!isdigit(a[i]))
            return false;
    return true;
}

bool ScalarConverter::is_float(const std::string& a)
{
    if (a.empty())
        return false;
    size_t i = 0;
    if (a[0] == '-' || a[0] == '+')
        i = 1;
    if (i == a.length())
        return false;
    size_t f = a.find('.');
    for (;i < f; i++)
        if (!isdigit(a[i]))
            return false;
    i++;
    for (;i < a.length(); i++)
        if (!isdigit(a[i]) && a[i] != 'f' && a[i] != 'F')
            return false;
    i--;
    if (a[i] != 'f' && a[i] != 'F')
        return false;
    return true;
}

bool   ScalarConverter::is_char(const std::string& a)
{
    if (a.empty())
        return false;
    if (type1.length() == 3 && type1[0] == '\'' && type1[2] == '\'')
		return true;
	else if (type1.length() == 1 && !isdigit(type1[0])) 
		return true;
	return false;
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const std::string& a) : type1(a) {}


void ScalarConverter::convert(const std::string& type)
{
    ScalarConverter a(type);
    if (a.is_int(a.type1))
    {
        if (!a.is_char(a.type1))
            std::cout << "Char: Non displayable" << std::endl;
        else   
            std::cout << "Char: '" << a.getChar() << "'" << std::endl;
        std::cout << "Int: " << static_cast<int>(a.getInt()) << std::endl;
        std::cout << "Float: " << (a.getFloat()) << "f" << std::endl;
        std::cout << "Double: " << (a.getDouble()) << std::endl;
    }
    else if (a.is_double(a.type1))
    {
        if (a.is_char(a.type1))
            std::cout << "Char: '" << a.getChar() << "'" << std::endl;
        else
            std::cout << "Char: Non displayable" << std::endl;
        std::cout << "Int: " << a.getInt() << std::endl;
        std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(a.getDouble()) << "f" << std::endl;
        std::cout << "Double: " << std::fixed << std::setprecision(1) << (a.getDouble()) << std::endl;
    }
    else if (a.is_float(a.type1))
    {
        if (a.is_char(a.type1))
            std::cout << "Char: '" << a.getChar() << "'" << std::endl;
        else
            std::cout << "Char: Non displayable" << std::endl;
        std::cout << "Int: " << a.getInt() << std::endl;
        //if (!a.is_double())
        std::cout << "Float: " << std::fixed << std::setprecision(1) << (a.getFloat()) << "f" << std::endl;
        std::cout << "Double: " << std::fixed << std::setprecision(1) << (a.getDouble()) << std::endl;
    }
    else if (a.is_char(a.type1))
    {
        if (a.is_char(a.type1))
            std::cout << "Char: '" << a.getChar() << "'" << std::endl;
        else
            std::cout << "Char: Non displayable" << std::endl;
        if (!a.is_int(a.type1))
            std::cout << "char: impossible\n";
        else
            std::cout << "Int: " << a.getInt() << std::endl;
        std::cout << "Float: " << std::fixed << std::setprecision(1) << (a.getFloat()) << "f" << std::endl;
        std::cout << "Double: " << std::fixed << std::setprecision(1) << (a.getDouble()) << std::endl;
    
    }
    else if (a.type1 == "nan")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << a.type1 << "f\n";
        std::cout << "double: " << a.type1 << "\n";
    }
    else
    {
        std::cout << "Impossible conversion, alpha string or out of bounds.\n";
    }   
}