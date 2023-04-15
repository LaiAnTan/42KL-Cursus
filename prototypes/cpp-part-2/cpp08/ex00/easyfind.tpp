#include "easyfind.hpp"

#include <iterator>

const char* NotFoundException::what() const throw()
{
	return ("NotFoundException: Value not found in container");
}

template <typename T>
typename T::iterator	easyfind(T container, int toFind)
{
	typename T::iterator	iterBegin = container.begin();
	typename T::iterator	iterEnd = container.end();

	for (; iterBegin != iterEnd; ++iterBegin)
	{
		if (*iterBegin == toFind)
			return (iterBegin);
	}
	throw(NotFoundException());
}

