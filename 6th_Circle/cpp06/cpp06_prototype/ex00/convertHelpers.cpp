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

/*
for lexer
check float (has . and f at the back) (+inff, -inff, nanf)
check double (has . btwn 2 numbers) (+inf, -inf, nan)
check int (only numbers) 
check char (str len 1, isprintable)
*/

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



// double is used for all checks because it can store the largest value among all 4 datatypes
void	printConverted(char	c, int i, float f, double d)
{
	// checks for char
	if (std::isnan(d) == true)
		cout << "Char: impossible" << endl;
	else if (std::isprint(c) == true)
		cout << "Char: '" << c << "'" << endl;
	else
		cout << "Char: not displayable" << endl;

	// checks for int
	if (std::isnan(d) == true || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		cout << "Int: impossible" << endl;
	else
		cout << "Int: " << i << endl;

	// checks for float
	if (std::isnan(d) == true || d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
		cout << "Float: impossible" << endl;
	else
		cout << "Float: "<< std::fixed << std::setprecision(1) << f << "f" << endl;
	
	// checks for double
	if (std::isnan(d) == true || d > std::numeric_limits<double>::max() || d < std::numeric_limits<double>::min())
		cout << "Double: impossible" << endl;
	else
		cout << "Double: " << std::fixed << std::setprecision(1) << d << endl;
}

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