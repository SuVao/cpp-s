
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


void ScalarConverter::convert(const std::string& type)
{
    
}