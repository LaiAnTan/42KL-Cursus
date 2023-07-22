#include "RPN.hpp"

#include <deque>
#include <string>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;

RPN::RPN()
{
	cout << "RPN: Default constructor called" << endl;
}

RPN::RPN(const RPN &tocopy)
{
	cout << "RPN: Copy constructor called" << endl;
	*this = tocopy;
}

RPN	&RPN::operator = (const RPN &tocopy)
{
	cout << "RPN: Copy assignment operator called" << endl;
	if (this == &tocopy)
		return (*this);
	this->rpn_stack = tocopy.rpn_stack;
	return (*this);
}

RPN::~RPN()
{
	cout << "RPN: Destructor called" << endl;
}

std::ostream &operator << (std::ostream &out, std::deque<int> dq)
{
	for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
		out << *it << " ";
	return (out);
}

bool	isValidNumber(std::string num)
{
	return (num.length() == 1 && num.find_first_not_of("0123456789") == std::string::npos);
}

bool	isValidOperation(std::string op)
{
	return (op.length() == 1 && op.find_first_not_of("+-*/") == std::string::npos);
}

int	RPN::insertExpression(char *line)
{
	string	s;
	std::stringstream	ss(line);

	while (std::getline(ss, s, ' ')) // split into tokens
	{
		if (isValidNumber(s) || isValidOperation(s))
			rpn_expr.push_back(s);
		else
			return (-1);
	}
	return (0);
}

static int stringToInt(string str)
{
	int n = 0;
	std::stringstream ss(str);

	ss >> n;
	return (n);
}

int		RPN::evalExpression(void)
{
	int		num1;
	int		num2;
	std::deque<string>::iterator		it;

	num1 = 0;
	num2 = 0;
	for (it = rpn_expr.begin(); it != rpn_expr.end(); ++it)
	{
		if (isValidOperation(*it))
		{
			num1 = rpn_stack.back();
			rpn_stack.pop_back();
			num2 = rpn_stack.back();
			rpn_stack.pop_back();
			cout << num1 << " " << num2 << ": " << *it << endl;
			if (*it == "+")
				rpn_stack.push_back(num1 + num2);
			else if (*it == "-")
				rpn_stack.push_back(num2 - num1);
			else if (*it == "*")
				rpn_stack.push_back(num1 * num2);
			else if (*it == "/")
				rpn_stack.push_back(num1 / num2);
			else
			{
				cout << "Error" << endl;
				return (-1);
			}
		}
		else
			rpn_stack.push_back(stringToInt(*it));
		cout << rpn_stack << endl;
	}
	return (*rpn_stack.begin());
}