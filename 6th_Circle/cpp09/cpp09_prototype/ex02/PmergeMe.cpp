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

bool	PmergeMe::isSortedVec(void)
{
	if (std::binary_search(vec.begin(), vec.end(), vec.front()) == true 
			&& std::binary_search(vec.begin(), vec.end(), vec.back()) == true)
		return (true);
	return (false);
}

bool	PmergeMe::isSortedLst(void)
{
	if (std::binary_search(lst.begin(), lst.end(), lst.front()) == true 
			&& std::binary_search(lst.begin(), lst.end(), lst.back()) == true)
		return (true);
	return (false);
}

static void swap(std::pair<int, int> &pair)
{
	int	temp;

	temp = pair.first;
	pair.first = pair.second;
	pair.second = temp;
	return ;
}

static void	merge(std::vector<std::pair<int, int> > &left, std::vector<std::pair<int, int> > &right, std::vector<std::pair<int, int> > &res)
{
	std::vector<std::pair<int, int> >::iterator		it1 = left.begin();
	std::vector<std::pair<int, int> >::iterator		it2 = right.begin();

	// append the smaller
	while (it1 != left.end() && it2 != right.end())
	{
		if ((*it1).second < (*it2).second)
		{
			res.push_back(*it1);
			++it1;
		}
		else
		{
			res.push_back(*it2);
			++it2;
		}
	}

	// append remaining
	while (it1 != left.end())
	{
		res.push_back(*it1);
		++it1;
	}
	while (it2 != right.end())
	{
		res.push_back(*it2);
		++it2;
	}
	return ;
}

// recursive merge sort
static void	sortPairs(std::vector<std::pair<int, int> > &pairs)
{
	if (pairs.size() <= 1)
		return ;
	
	std::vector<std::pair<int, int> >::iterator	mid = pairs.begin() + pairs.size() / 2;
	std::vector<std::pair<int, int> >			left(pairs.begin(), mid);
	std::vector<std::pair<int, int> >			right(mid, pairs.end());

	sortPairs(left);
	sortPairs(right);

	pairs.clear();
	merge(left, right, pairs);
	return ;
}

static int	jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + (2 * jacobsthal(n - 2)));
}

/*
Ford-Johnson's Merge-Insertion Sort

Steps:
1) check if the sequence is odd, if yes, save the leftover value and make the sequence even
2) split elements into pairs of 2
3) sort the pairs internally so that the it is in the form <smaller, larger>
4) sort the pairs externally by their largest value (either recursively or non-recursively)
5) split the pairs, inserting the smaller and larger values into different chains
6) insert the first element of smaller chain into first spot of larger chain because it is always smaller
7) build the optimal binary insertion sequence of the smaller chain using relevant jacobsthal numbers

- jacobsthal number corresponds to the order in which elements should be inserted
- eg. (first 3 ignored because irrelevant), 3, 5, 11
- which means the 3rd element in the sequence should be inserted first, followed by the 5th, 11th and so on ...
- this takes advantage of a property of binary search where:

the maximal number of comparisons needed to perform a binary search on a sorted sequence is the same when 
the number of elements is 2^(n) and when it is 2^(n+1) −1

- therefore we can minimise the comparisons used by building an optimal binary insertion sequence
- elements which do not match any jacobsthal number are put to the end to be inserted normally

8) use binary sort to insert elements in the optimally sequenced smaller chain into the larger chain
9) done

fml
*/
void	PmergeMe::performFordJohnsonVec(void)
{
	typedef typename std::vector<std::pair<int, int> >::iterator	pair_iter;
	typedef typename std::vector<std::pair<int, int> >				pair_vector;

	pair_vector	pairs;
	std::pair<int, int>				pair;

	pair_iter	it_pair;
	std::vector<int>::iterator		it1;
	std::vector<int>::iterator		it2;

	std::vector<int>				pend;

	int		n = 2;
	int		jacob = 0;
	int		leftover = 0;
	bool	has_leftover = false;

	// handle leftover value in odd numbered sequence
	if (vec.size() % 2 == 1) 
	{
		has_leftover = true;
		leftover = *vec.end();
		vec.pop_back();
	}

	// categorize into pairs & sort the pairs so that pair.first = smaller value && pair.second = larger value
	for (it1 = vec.begin(); it1 < vec.end(); it1 += 2)
	{
		pair = std::pair<int, int>(*it1, *(it1 + 1));
		if (pair.first > pair.second)
			swap(pair);
		pairs.push_back(pair);
	}

	// sort pairs by their largest value
	sortPairs(pairs);
	vec.clear();

	// place all largest elements in s && smallest elements in pend
	for (it_pair = pairs.begin(); it_pair != pairs.end(); ++it_pair)
	{
		vec.push_back((*it_pair).second);
		pend.push_back((*it_pair).first);
	}

	// place first element in pend into s because it is always smaller
	vec.insert(vec.begin(), pend.front());
	pend.erase(pend.begin());

	// build optimal binary insertion sequence
	it2 = pend.begin();
	while (true)
	{
		it1 = pend.begin();
		jacob = jacobsthal(n);
		if (jacob >= static_cast<int> (pend.size()))
			break ;
		std::advance(it1, jacob - 1);
		pend.insert(it2, *it1);
		pend.erase(it1 + 1);
		++n;
		++it2;
	}

	// binary search insert optimally sequenced pend into s
	for (it1 = pend.begin(); it1 < pend.end(); ++it1)
		vec.insert(std::lower_bound(vec.begin(), vec.end(), *it1), *it1);

	// binary search insert leftover into s
	if (has_leftover == true)
		vec.insert(std::lower_bound(vec.begin(), vec.end(), leftover), leftover);

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