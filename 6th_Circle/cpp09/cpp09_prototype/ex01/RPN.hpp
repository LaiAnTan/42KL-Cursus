#pragma once

#ifndef RPN_HPP

#define RPN_HPP

#include <string>
#include <deque>

class RPN
{
	public:
		RPN();
		RPN(const RPN &tocopy);
		RPN	&operator = (const RPN &tocopy);
		~RPN();

		bool	isValidNotation(void);

		int		insertExpression(char *line);
		int		evalExpression(void);

	private:
		std::deque<std::string>	rpn_expr;
		std::deque<int>	rpn_stack;
};

std::ostream &operator << (std::ostream &out, std::deque<int> dq);

bool	isValidNumber(std::string num);
bool	isValidOperation(std::string op);

#endif