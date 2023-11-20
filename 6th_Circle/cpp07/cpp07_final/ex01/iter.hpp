#pragma once

#ifndef ITER_HPP

#define ITER_HPP

#include <iostream>
#include <string>
#include <typeinfo>

using std::endl;
using std::cout;
using std::string;

template <typename arrType, typename lenType, typename funcType>
void	iter(arrType *arr, lenType len, funcType func)
{
	for (int i = 0; i < len; i++)
		func(arr[i]);
}


#endif