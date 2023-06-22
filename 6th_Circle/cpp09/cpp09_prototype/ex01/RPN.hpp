#pragma once

#ifndef RPN_HPP

#define RPN_HPP

#include <deque>

typedef struct s_expression
{
	int		op_type;
	int		num1;
	int		num2;

	bool	has_2_numbers;
}			t_expression;

class RPN
{
	public:
		RPN();
		RPN(const RPN &tocopy);
		RPN	&operator = (const RPN &tocopy);
		~RPN();

		void	insertExpression(t_expression expr);
		int		evalExpression(void);

	private:
		std::deque<t_expression>	expr_list;
};

t_expression	initExpressionStruct(int expr_type, int num1, int num2, bool has_2_numbers);



#endif