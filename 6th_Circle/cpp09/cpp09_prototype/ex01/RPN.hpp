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

		int		insertExpression(char *line);
		int		evalExpression(void);

	private:
		std::deque<std::string>	rpn_expr;
		std::deque<int>	rpn_stack;
};

std::ostream &operator << (std::ostream &out, std::deque<int> dq);

bool	isValidNumber(std::string num);
bool	isValidOperation(std::string op);

/*
---
Container used: std::deque (stack)

Should have used stack but stack is just a container adaptor so it doesnt really matter

Reason:
The nature of the RPN expression is that of a stack, as elements are processed in a
Last-In-First-Out (LIFO) manner.

*/

#endif