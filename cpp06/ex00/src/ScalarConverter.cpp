
#include "../inc/ScalarConverter.hpp"

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{
    return *this;
}

ScalarConverter::~ScalarConverter() { std::cout << "ScalarConverter destructor called\n";}

int ScalarConverter::getInt(const std::string& a)
{
   return std::strtol(a.c_str(), NULL, 10);
}

double ScalarConverter::getDouble(const std::string& a)
{
    return std::strtod(a.c_str(), NULL);    
}

float ScalarConverter::getFloat(const std::string& a)
{
    return std::strtof(a.c_str(), NULL);
}

char ScalarConverter::getChar(const std::string& a)
{
    if (a.length() == 3 && a[0] == '\'' && a[2] == '\'')
        return a[1];
    return a[0];
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
    int f = a.find('.');
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
    int f = a.find('.');
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
    for (int i = 0; i < a.length(); i++)
        if (a[i] >= 32 && a[i] <= 126)
            return false;
    return true;
}


void ScalarConverter::convert(const std::string& type)
{
    
}