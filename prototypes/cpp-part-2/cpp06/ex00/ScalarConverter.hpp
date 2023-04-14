#pragma once

#ifndef SCALAR_CONVERTER_HPP

#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <cmath>

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

int		getType(string str);
bool	checkChar(string str);
bool	checkInt(string str);
bool	checkFloat(string str);
bool	checkDouble(string str);

void	fromChar(char inputValue);
void	fromInt(int inputValue);
void	fromFloat(float inputValue);
void	fromDouble(double inputValue);

void	printConverted(char	c, int i, float f, double d);

// void printConverted(char cval, int ival, float fval, double dval);

#endif