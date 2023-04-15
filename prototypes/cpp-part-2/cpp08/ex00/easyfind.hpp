#pragma once

#ifndef EASYFIND_HPP

#define EASYFIND_HPP

#include <exception>
#include <iterator>

using std::exception;

class	NotFoundException: public exception
{
	public:
		const char* what() const throw();
};

template <typename T> typename T::iterator	easyfind(T container, int toFind);

#include "easyfind.tpp"

#endif