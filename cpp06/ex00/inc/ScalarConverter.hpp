

#pragma once 

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>

class ScalarConverter
{
    const std::string type1;
public:
    ScalarConverter();
   // ScalarConverter& operator=(const ScalarConverter& other); 
    ~ScalarConverter();
    ScalarConverter(const std::string& a);
    static void    convert(const std::string& literal);
    char getChar();
    bool is_char();
  
    float getFloat();
    bool is_float();
  
    double getDouble();
    bool is_double();
   
    int  getInt();
    bool is_int();

    bool is_pseudo();
    void Display_pseudo();

};


#endif