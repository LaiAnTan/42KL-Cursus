#pragma once

#ifndef ARRAY_HPP

#define ARRAY_HPP

#include <exception>

using std::exception;

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &array);
		Array &operator = (const Array &array);
		~Array();

		T	&operator [] (unsigned int index);

		unsigned int	size() const;

		class IndexOutOfBoundsException: public exception
		{
			public:
				const char* what() const throw();
		};

	private:
		T				*ptr;
		unsigned int	arraySize;

};

// .tpp files are usually included after the template defenition
#include "Array.tpp"

#endif