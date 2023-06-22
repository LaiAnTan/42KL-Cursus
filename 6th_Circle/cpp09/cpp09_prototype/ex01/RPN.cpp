#include "RPN.hpp"

#include <deque>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

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
	this->expr_list = tocopy.expr_list;
	return (*this);
}

RPN::~RPN()
{
	cout << "RPN: Destructor called" << endl;
}

void	RPN::insertExpression(t_expression expr)
{
	expr_list.push_back(expr);
}

static int	calculateResult(int num1, int num2, int expr_type)
{
	switch (expr_type)
	{
	case (1): // +
		return (num1 + num2);
	case (2): // -
		return (num1 - num2);
	case (3): // *
		return (num1 * num2);
	case (4): // /
		return (num1 / num2);
	default:
		return (0);
	}
	return (0);
}

int		RPN::evalExpression(void)
{
	int									result;
	std::deque<t_expression>::iterator	it;

	result = 0;
	it = expr_list.begin();
	while (it != expr_list.end())
	{
		if (it->has_2_numbers == false)
		{
			it->num2 = it->num1;
			it->num1 = result;
		}
		cout << "Doing: " << it->num1 << " " << it->op_type << " " << it->num2 << endl;
		result = calculateResult(it->num1, it->num2, it->op_type);
		++it;
	}
	return (result);
}