#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &list, int value)
{
	if (list.empty())
	{
		throw std::runtime_error("List is empty");
	}

	typename T::iterator ptr = std::find(list.begin(), list.end(), value);

	if (ptr == list.end())
	{
		throw std::out_of_range("Value not found");
	}

	return ptr;
}

#endif
