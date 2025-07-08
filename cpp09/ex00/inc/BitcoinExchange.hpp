
#pragma once 

#ifndef BITCOINEXCHANGE_HPP
#define  BITCOINEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <map>
#include <cstdlib>
#include <limits>
#include <cctype>

class BitcoinExchange
{
private:
	std::map<std::string, double> a;
public: 
	BitcoinExchange();
	~BitcoinExchange();
	void Inserting(const std::string& date, double& valeu);
	void Print();
	double search_and_multiple(double val, std::string date);
};


#endif