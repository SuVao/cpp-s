

#pragma once 

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>

class ScalarConverter
{
public:
    ScalarConverter& operator=(const ScalarConverter& other); 
    ~ScalarConverter();
    static void    convert(const std::string& literal);
    int getInt(const std::string& a);
    double getDouble(const std::string& a);
    float getFloat(const std::string& a);
    char getChar(const std::string& a);
    bool is_int(const std::string& a);

    
};

#endif