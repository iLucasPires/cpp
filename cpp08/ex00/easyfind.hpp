#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <string>

template <typename T>
int easyfind(T &first, int second)
{
	if (first.empty())
	{
		throw std::exception();
	}

	typename T::iterator ptr = std::find(first.begin(), first.end(), second);

	if (ptr == first.end())
	{
		throw std::exception();
	}

	return *ptr;
}

#endif
