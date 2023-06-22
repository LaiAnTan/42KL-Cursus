#include "RPN.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cerr;

bool	isValidNumber(std::string num)
{
	return (num.length() == 1 && num.find_first_not_of("0123456789") == std::string::npos);
}

bool	isValidOperation(std::string op)
{
	return (op.length() == 1 && op.find_first_not_of("+-*/") == std::string::npos);
}

int		getOpType(std::string op)
{
	std::string	str = "+-*/";

	return (str.find_first_of(op.at(0)) + 1);
}

void	resetExpression(t_expression &expr)
{
	expr.has_2_numbers = false;
	expr.num1 = 0;
	expr.num1 = 0;
	expr.op_type = 0;
}

int	parseExpression(RPN &rpn, char *line)
{
	std::string							s;
	std::stringstream					l(line);
	std::deque<std::string>				strings;
	std::deque<std::string>::iterator	it1;
	std::deque<std::string>::iterator	it2;
	t_expression						expr;

	while (std::getline(l, s, ' '))
		strings.push_back(s);

	it1 = strings.begin();
	it2 = it1 + 1;

	while (it1 != strings.end()) // fucking tokenizer
	{
		resetExpression(expr);
		if (isValidNumber(*it1) == true)
			expr.num1 = std::strtol((*it1).c_str(), NULL, 10);
		else
			return (-1);
		if (isValidNumber(*it2) == true)
		{
			expr.num2 = std::strtol((*it2).c_str(), NULL, 10);
			expr.has_2_numbers = true;
			++it2;
			if (isValidOperation(*it2) == true)
				expr.op_type = getOpType(*it2);
			else
				return (-1);
			it1 += 3;
			it2 += 2;
		}
		else if (isValidOperation(*it2) == true)
		{
			expr.op_type = getOpType(*it2);
			it1 += 2;
			it2 += 2;
		}
		else
			return (-1);
		rpn.insertExpression(expr);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	RPN	rpn;

	if (argc != 2 || parseExpression(rpn, argv[1]) == -1)
	{
		cerr << "Error" << endl; 
		return (-1);
	}
	cout << rpn.evalExpression() << endl;
	return (0);
}