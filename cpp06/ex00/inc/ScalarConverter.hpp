

#pragma once 

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>

class ScalarConverter
{
public:
    const std::string type;
    ScalarConverter();
   // ScalarConverter& operator=(const ScalarConverter& other); 
    ~ScalarConverter();
    ScalarConverter(const std::string& a);
    static void    convert(const std::string& literal);
  
    char getChar();
    bool is_char(const std::string& a);
  
    float getFloat();
    bool is_float(const std::string& a);
  
    double getDouble();
    bool is_double(const std::string& a);
  
    int  getInt();
    bool is_int(const std::string& a);
};


#endif