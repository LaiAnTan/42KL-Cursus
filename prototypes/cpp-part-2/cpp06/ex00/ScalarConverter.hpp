#pragma once

#ifndef SCALAR_CONVERTER_HPP

#define SCALAR_CONVERTER_HPP

#include <string>

using std::string;

class ScalarConverter
{
	public:
		ScalarConverter &operator = (const ScalarConverter &scalarconverter);
		~ScalarConverter();

		static void	convert(string inputValue);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarconverter);

};

#endif