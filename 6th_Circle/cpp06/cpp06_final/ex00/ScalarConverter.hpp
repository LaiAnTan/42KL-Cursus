#pragma once

#ifndef SCALAR_CONVERTER_HPP

#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <cmath>
#include <iomanip>

using std::string;
using std::endl;
using std::cout;

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarconverter);
		ScalarConverter &operator = (const ScalarConverter &scalarconverter);
		~ScalarConverter();

		static void	convert(string inputValue);
};

// lexer
int		getType(string str);
bool	checkChar(string str);
bool	checkInt(string str);
bool	checkFloat(string str);
bool	checkDouble(string str);

// converters
void	fromChar(char inputValue);
void	fromInt(int inputValue);
void	fromFloat(float inputValue);
void	fromDouble(double inputValue);

// print
void	printConverted(char	c, int i, float f, double d);

#endif