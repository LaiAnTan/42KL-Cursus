#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	cout << "ScalarConverter: Default constructor called" << endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarconverter)
{
	cout << "ScalarConverter: Copy constructor called" << endl;
	*this = scalarconverter;
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &scalarconverter)
{
	cout << "ScalarConverter: Copy assignment operator called" << endl;
	if (this == &scalarconverter)
		return (*this);
	(void) scalarconverter;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	cout << "ScalarConverter: Destructor called" << endl;
}

void	ScalarConverter::convert(string inputValue)
{
	switch (getType(inputValue))
	{
		case 0:
			fromChar(inputValue[0]);
			break;
		case 1:
			fromFloat(strtof(inputValue.c_str(), NULL));
			break;
		case 2:
			fromDouble(strtod(inputValue.c_str(), NULL));
			break;
		case 3:
			fromInt(atoi(inputValue.c_str()));
			break;
		default:
			cout << "Not a valid type" << endl;
	}
	return ;
}

/*

test cases

char:
'a'		pass
b		pass
cdefg	fail

float:

2.2f	pass
2f		pass
42.f	fail
.42f	fail
2.2.22f	fail

nanf	pass
+inff	pass
-inff	pass

double:

2.2		pass
.20		fail
20.		fail
2.2.2	fail

nan		pass
+inf	pass
-inf	pass

int

1		pass
727		pass

*/