
#pragma once

#ifndef MUTANTSTACK_HPP
#define  MUTANTSTACK_HPP

#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <iostream>

template <typename T, typename Mutant = std::deque<T> >
class MutantStack : public std::stack<T, Mutant>
{
public:
	typedef typename Mutant::iterator iterator;

	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};


#endif
