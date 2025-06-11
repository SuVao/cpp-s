
#include "../inc/ScalarConverter.hpp"

/* ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{
    *this = other;
    return *this;
}
 */
ScalarConverter::~ScalarConverter() { std::cout << "ScalarConverter destructor called\n";}

int ScalarConverter::getInt()
{
    return (std::strtol(type.c_str(), NULL, 10));
}

double ScalarConverter::getDouble()
{
    return (std::strtod(type.c_str(), NULL));    
}

float ScalarConverter::getFloat()
{
    return (std::strtof(type.c_str(), NULL));
}

char ScalarConverter::getChar()
{
    if (type.length() == 3 && type[0] == '\'' && type[2] == '\'')
        return type[1];
    return (type[0]);
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
    for (;i < a.length() - 1; i++)
        if (!isdigit(a[i]))
            return false;
    i++;
    if (a[i] != 'f' && a[i] != 'F')
        return false;
    return true;
}

bool   ScalarConverter::is_char(const std::string& a)
{
    if (a.empty())
        return false;
    for (size_t i = 0; i < a.length(); i++)
        if (a[i] < 32 && a[i] > 126)
            return false;
    return false;
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const std::string& a) : type(a) {}

void ScalarConverter::convert(const std::string& type)
{
    ScalarConverter a(type);
    if (a.is_int(type))
    {
        std::cout << "Int: " << static_cast<int>(a.getInt()) << std::endl;
        if (a.is_char(type))
            std::cout << "Char: " << static_cast<char>(a.getChar()) << std::endl;
        else   
            std::cout << "Char: isn't printable" << std::endl;
        std::cout << "Double: " << static_cast<double>(a.getDouble()) << std::endl;
        std::cout << "Float: " << static_cast<float>(a.getFloat()) << std::endl;
    }
    else if (a.is_double(type))
    {
        std::cout << "Int: " << a.getInt() << std::endl;
        
       // std::cout << "The number is double type: " << val_double << std::endl;
    }
        
}