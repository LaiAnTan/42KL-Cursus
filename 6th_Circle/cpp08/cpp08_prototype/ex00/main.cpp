#include "easyfind.hpp"

#include <vector>
#include <deque>
#include <list>

#include <iostream>

using std::endl;
using std::cout;

int main(void)
{
	std::vector<int>		vec;
	std::deque<int>			dq;
	std::list<int>			lst;

	for (int i = 0; i < 5; i++)
	{
		vec.push_back(i);
		dq.push_back(i);
		lst.push_back(i);
	}

	std::vector<int>::iterator	vec_iter = easyfind(vec, 2);
	std::deque<int>::iterator	dq_iter = easyfind(dq, 2);
	std::list<int>::iterator	lst_iter = easyfind(lst, 2);

	cout << *vec_iter << endl;
	cout << *dq_iter << endl;
	cout << *lst_iter << endl;

	return (0);
}