#include "ScalarConverter.hpp"

bool	checkChar(string str)
{
	if (str.length() == 1 && !(str[0] >= '0' && str[0] <= '9'))
		return (true);
	return (false);
}

bool	checkInt(string str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		i = 1;

	for (; str[i] != '\0'; i++)
		if (str[i] < '0' || str[i] > '9')
			return (false);
	return (true);
}

bool	checkFloat(string str)
{
	int		i;
	int		len = str.length();
	int		decimalPoints = 0;

	i = 0;
	if (str[0] == '-')
		i = 1;

	if (str[len - 1] != 'f' || str[i] == '.' || str[len - 2] == '.')
		return (false);
	if (str.compare("nanf") == 0 || str.compare("+inff") == 0 || str.compare("-inff") == 0)
		return (true);
	for (; str[i] != 'f'; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '.'))
			return (false);
		if (str[i] == '.')
			decimalPoints += 1;
	}
	return decimalPoints == 1 ? true : false;
}

bool	checkDouble(string str)
{
	double check = strtod(str.c_str(), 0);

	if (check > std::numeric_limits<int>::max() || check < std::numeric_limits<int>::min() || str.find('.') != std::string::npos)
		return (true);
	return (false);
}

int		getType(string str)
{
	bool	(*func_ptr[4])(string) = {&checkChar, &checkFloat, &checkDouble, &checkInt};

	for (int i = 0; i < 4; i++)
	{
		if ((*func_ptr[i])(str) == true)
			return (i);
	}
	return (-1);
}

// double is used for all checks because it can store the largest value among all 4 datatypes
void	printConverted(char	c, int i, float f, double d)
{
	// checks for char
	if (std::isnan(d) == true)
		cout << "Char: impossible" << endl;
	else if (std::isprint(c) != 0)
		cout << "Char: '" << c << "'" << endl;
	else
		cout << "Char: not displayable" << endl;

	// checks for int
	if (std::isnan(d) == true || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		cout << "Int: impossible" << endl;
	else
		cout << "Int: " << i << endl;

	cout << "Float: "<< std::fixed << std::setprecision(1) << f << "f" << endl;
	
	cout << "Double: " << std::fixed << std::setprecision(1) << d << endl;
}

void	fromChar(char inputValue)
{
	printConverted(inputValue, static_cast<int>(inputValue), static_cast<float>(inputValue), static_cast<double>(inputValue));
}

void	fromInt(int inputValue)
{
	printConverted(static_cast<char>(inputValue), inputValue, static_cast<float>(inputValue), static_cast<double>(inputValue));
}

void	fromFloat(float inputValue)
{
	printConverted(static_cast<char>(inputValue), static_cast<int>(inputValue), inputValue, static_cast<double>(inputValue));
}

void	fromDouble(double inputValue)
{
	printConverted(static_cast<char>(inputValue), static_cast<int>(inputValue), static_cast<float>(inputValue), inputValue);
}
