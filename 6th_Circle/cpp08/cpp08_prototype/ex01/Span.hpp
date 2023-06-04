#pragma once

#ifndef SPAN_HPP

#define SPAN_HPP

#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>
#include <iterator>
#include <limits>

using std::exception;

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span &span);
		Span &operator = (const Span &span);
		~Span();

		void	addNumber(int num);

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

	private:
		std::vector<int>	container;
		unsigned int n;
};

#endif