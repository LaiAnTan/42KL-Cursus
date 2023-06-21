#pragma once

#ifndef SPAN_HPP

#define SPAN_HPP

#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <limits>

using std::exception;
using std::ostream;

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span &span);
		Span &operator = (const Span &span);
		~Span();

		void	addNumber(int num);
		void	addNumbers(int *intArray, unsigned int size);
		
		int		getValue(unsigned int index) const;
		int		getSize(void) const;

		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class SpanFullException: public exception
		{
			public:
				const char* what() const throw();
		};

		class SpanNotFoundException: public exception
		{
			public:
				const char* what() const throw();
		};

		class SpanIndexOutOfBoundsException: public exception
		{
			public:
				const char* what() const throw();
		};

	private:
		std::vector<int>	container;
		unsigned int n;
};

ostream &operator << (ostream &outs, const Span &span);

#endif