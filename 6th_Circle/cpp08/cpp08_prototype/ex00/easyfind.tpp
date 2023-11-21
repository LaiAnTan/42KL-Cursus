#include "easyfind.hpp"

#include <iterator>

const char* NotFoundException::what() const throw()
{
	return ("NotFoundException: Value not found in container");
}

template <typename T>
typename T::iterator	easyfind(T &container, int toFind)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), toFind); // used STL algo std::find

	if (it == container.end())
		throw(NotFoundException());
	return (it);
}

