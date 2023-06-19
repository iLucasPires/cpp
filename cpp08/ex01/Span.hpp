#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <set>

class Span
{
	public:
		class SpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		Span();
		Span(unsigned int number);
		Span(Span const &src);
		~Span();

		Span &operator=(Span const &rhs);

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

	private:
		unsigned int _index;
		unsigned int _limit;
		std::set<int> _set;
};

#endif
