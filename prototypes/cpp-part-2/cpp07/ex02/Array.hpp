#pragma once

#ifndef ARRAY_TPP

#define ARRAY_TPP

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

		unsigned int	getSize() const;

	private:
		T				*ptr;
		unsigned int	size;

};

#endif