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

		// getters for vector & list
		const std::vector<int>	&getVec(void);
		const std::list<int>	&getLst(void);

		// getters & setters for elapsed time
		void	setElapsedVec(double time);
		void	setElapsedLst(double time);
		double	getElapsedVec(void);
		double	getElapsedLst(void);

		// check if sorted
		bool	isSortedVec();
		bool	isSortedLst();

		// sorters for vector and list
		void	performFordJohnsonVec(void);
		void	performFordJohnsonLst(void);

	private:

		double				elapsed_vec;
		double				elapsed_lst;

		std::vector<int>	vec;
		std::list<int>		lst;
};

std::ostream &operator << (std::ostream &outs, std::vector<int> vec);
std::ostream &operator << (std::ostream &outs, std::list<int> lst);

#endif