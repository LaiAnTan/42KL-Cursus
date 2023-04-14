#include "ScalarConverter.hpp"

bool	checkChar(string str)
{
	if (str.length() == 1 && !(str[0] >= '0' && str[0] <= '9'))
		return (true);
	return (false);
}

bool	checkInt(string str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] < '0' || str[i] > '9')
			return (false);
	return (true);
}

bool	checkFloat(string str)
{
	int		len = str.length();
	int		decimalPoints = 0;

	if (str[len - 1] != 'f')
		return (false);
	if (str[0] == '.' || str[len - 2] == '.')
		return (false);
	if (str.compare("nanf") == 0 || str.compare("+inff") == 0 || str.compare("-inff") == 0)
		return (true);
	for (int i = 0; str[i] != 'f'; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '.'))
			return (false);
		if (str[i] == '.')
			decimalPoints += 1;
	}
	if (decimalPoints == 1)
		return (true);
	else
		return (false);
}

bool	checkDouble(string str)
{
	int		len = str.length();
	int		decimalPoints = 0;

	if (str.compare("nan") == 0 || str.compare("+inf") == 0 || str.compare("-inf") == 0)
		return (true);
	if (str[0] == '.' || str[len - 1] == '.')
		return (false);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '.'))
			return (false);
		if (str[i] == '.')
			decimalPoints += 1;
	}
	if (decimalPoints == 1)
		return (true);
	else
		return (false);
}

int		getType(string str)
{
	bool	(*func_ptr[4])(string) = {&checkChar, &checkFloat, &checkDouble, &checkInt};

	for (int i = 0; i < 4;)
	{
		if ((*func_ptr[i])(str) == true)
			return (i);
		i++;
	}
	return (-1);
}

void	printConverted(char	c, int i, float f, double d)
{
	if (d > CHAR_MAX || d < CHAR_MIN)
		cout << "Char: impossible" << endl;
	else if (c <= 31 || c == 127)
		cout << "Char: not displayable" << endl;
	else
		cout << "Char: '" << c << "'" << endl;
	
	cout << "Int: " << i << endl;

	cout << "Float: " << f << endl;
	cout << "Double: " << d << endl;
}

// #include <iomanip>

// void printConverted(char cval, int ival, float fval, double dval)
// {
// 	if (dval < CHAR_MAX)
// 	{
// 		if (isprint(cval))
// 			std::cout << "char : '" << cval << "'" << std::endl;
// 		else
// 			std::cout << "char : \"Non displayable\"" << std::endl;
// 	}
// 	else
// 		std::cout << "char : yeah bud no" << std::endl;

// 	if (dval <= INT_MAX && dval >= INT_MIN)
// 		std::cout << "int : " << ival << std::endl;
// 	else
// 		std::cout << "int : yeah bud no" << std::endl;

// 	if (dval == (double) ival && ival < 1000000)
// 	{
// 		std::cout << "float : " << std::fixed << std::setprecision(1) << fval << "f" << std::endl;
// 		std::cout << "double : " << std::fixed << std::setprecision(1) << dval << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << "float : " << fval << "f" << std::endl;
// 		std::cout << "double : " << dval << std::endl;
// 	}
// }

void	fromChar(char inputValue)
{
	cout << "char found" << endl;

	printConverted(inputValue, static_cast<int>(inputValue), static_cast<float>(inputValue), static_cast<double>(inputValue));
}

void	fromInt(int inputValue)
{
	cout << "int found" << endl;

	printConverted(static_cast<char>(inputValue), inputValue, static_cast<float>(inputValue), static_cast<double>(inputValue));
}

void	fromFloat(float inputValue)
{
	cout << "float found" << endl;

	printConverted(static_cast<char>(inputValue), static_cast<int>(inputValue), inputValue, static_cast<double>(inputValue));
}

void	fromDouble(double inputValue)
{
	cout << "double found" << endl;

	printConverted(static_cast<char>(inputValue), static_cast<int>(inputValue), static_cast<float>(inputValue), inputValue);
}