#pragma once

#ifndef WHATEVER_HPP

#define WHATEVER_HPP

template <typename type> type max(type a, type b)
{
	return ((a >= b) ? a : b);
}

template <typename type> type min(type a, type b)
{
	return ((a <= b) ? a : b);
}

template <typename type> void swap(type &a, type &b)
{
	type temp = b;

	b = a;
	a = temp;
}

#endif