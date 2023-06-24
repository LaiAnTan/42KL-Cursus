#include "PmergeMe.hpp"

#include <list>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

PmergeMe::PmergeMe()
{
	cout << "PmergeMe: Default constructor called" << endl;
}

PmergeMe::PmergeMe(const PmergeMe &to_copy)
{
	cout << "PmergeMe: Copy constructor called" << endl;
	*this = to_copy;
}

PmergeMe &PmergeMe::operator = (const PmergeMe &to_copy)
{
	cout << "PmergeMe: Copy assignment operator called" << endl;
	if (this == &to_copy)
		return (*this);
	this->vec = to_copy.vec;
	this->lst = to_copy.lst;
	return (*this);
}

PmergeMe::~PmergeMe()
{
	cout << "PmergeMe: Destructor called" << endl;
}

void	PmergeMe::insertNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		vec.push_back(*begin);
		lst.push_back(*begin);
		++begin;
	}
}

const std::vector<int>	&PmergeMe::getVec(void)
{
	return (vec);
}

const std::list<int>	&PmergeMe::getLst(void)
{
	return (lst);
}

static void swap(std::pair<int, int> &pair)
{
	int	temp;

	temp = pair.first;
	pair.first = pair.second;
	pair.second = temp;
	return ;
}

static void	sortPairs(std::vector<std::pair<int, int> > &pairs, int n)
{
	
}

void	PmergeMe::performFordJohnsonVec(void)
{
	
	std::pair<int, int>					pair;
	std::vector<std::pair<int, int> >	pairs;

	std::vector<int>::iterator					it;
	std::vector<std::pair<int, int> >::iterator	it_pair;

	std::vector<int>					s; // final vector
	std::vector<int>					pend; // auxiliary vector

	bool	has_leftover;
	int		leftover;

	leftover = 0;
	has_leftover = false;

	if (std::binary_search(vec.begin(), vec.end(), vec.front()) == true 
			&& std::binary_search(vec.begin(), vec.end(), vec.back()) == true)
		return ;

	// check for leftover
	if (vec.size() % 2 == 1) 
	{
		has_leftover = true;
		leftover = *vec.end();
		vec.pop_back();
		cout << "leftover found: " << leftover << endl;
	}

	// categorize into pairs & sort the pairs
	it = vec.begin();
	while (it < vec.end())
	{
		pair = std::pair<int, int>(*it, *(it + 1));
		if (pair.first > pair.second)
			swap(pair);
		cout << "Pair: " << pair.first << " & " << pair.second << endl;
		pairs.push_back(pair);
		it += 2;
	}

	// do recursive merge sort to sort pairs by their largest value in ascending order
	sortPairs(pairs, pairs.size());

	// place all largest elements in s
	it_pair = pairs.begin();
	while (it_pair < pairs.end()) 
	{
		s.push_back((*it_pair).second);
		pend.push_back((*it_pair).first);
		++it_pair;
	}
	cout << "S: " << s << endl;
	cout << "Pend: " << pend << endl;
	// place first element in pend into s because it is always smaller
	s.insert(s.begin(), pend.at(0));
	pend.erase(pend.begin());

	// binary search insert pend -> s
	it = pend.begin();
	while (it < pend.end())
	{
		s.insert(std::lower_bound(s.begin(), s.end(), *it), *it);
		++it;
	}
	cout << s << endl;
	// binary search insert leftover -> s
	if (has_leftover == true)
		s.insert(std::lower_bound(s.begin(), s.end(), leftover), leftover);

	vec = s;
	return ;
}

std::ostream &operator << (std::ostream &outs, std::vector<int> vec)
{
	std::vector<int>::iterator	it;

	it = vec.begin();
	while (it != vec.end())
		outs << *it++ << " ";
	return (outs);
}

std::ostream &operator << (std::ostream &outs, std::list<int> lst)
{
	std::list<int>::iterator	it;

	it = lst.begin();
	while (it != lst.end())
		outs << *it++ << " ";
	return (outs);
}