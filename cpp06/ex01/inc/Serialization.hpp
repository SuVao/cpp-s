#pragma once 

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP


#include <string>
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serialization
{
private:
	Serialization();
	~Serialization();
public:
	static Data* deserialize(uintptr_t raw);
	static uintptr_t serialize(Data* ptr);
};


#endif