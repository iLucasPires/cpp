#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <set>
#include <stdexcept>

class Span
{
	public:
		Span();
		Span(unsigned int number);
		Span(Span const &src);
		~Span();

		Span &operator=(Span const &rhs);

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void addManyNumbers(std::set<int>::iterator begin, std::set<int>::iterator end);

	private:
		unsigned int _index;
		unsigned int _limit;
		std::set<int> _set;
};

#endif
