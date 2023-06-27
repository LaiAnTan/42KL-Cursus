#pragma once

#ifndef PMERGEME_HPP

#define PMERGEME_HPP

#include <list>
#include <vector>
#include <iterator>
#include <iostream>

class PmergeMe
{
	public:
	
		PmergeMe();
		PmergeMe(const PmergeMe &to_copy);
		PmergeMe &operator = (const PmergeMe &to_copy);
		~PmergeMe();

		void	insertNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		const std::vector<int>	&getVec(void);
		const std::list<int>	&getLst(void);

		bool	isSortedVec();
		bool	isSortedLst();

		void	performFordJohnsonVec(void);
		// void	performFordJohnsonLst(void);

	private:
		std::vector<int>	vec;
		std::list<int>		lst;
};

std::ostream &operator << (std::ostream &outs, std::vector<int> vec);
std::ostream &operator << (std::ostream &outs, std::list<int> lst);

#endif