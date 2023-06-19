#include "Span.hpp"

Span::Span() : _index(0), _limit(10)
{
}

Span::Span(unsigned int number) : _index(0), _limit(number)
{
}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span()
{
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_index = rhs._index;
		this->_limit = rhs._limit;
		this->_set = rhs._set;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (this->_index >= this->_limit)
	{
		throw SpanException();
	}
	this->_set.insert(number);
	this->_index++;
}
int Span::shortestSpan()
{
	int span = 0;
	int shortestSpan = std::numeric_limits<int>::max();

	for (std::set<int>::iterator it = this->_set.begin(); it != this->_set.end(); it++)
	{
		std::set<int>::iterator it2 = it;
		span = std::abs(*it - *(++it2));

		if (span < shortestSpan)
		{
			shortestSpan = span;
		}
	}

	return (shortestSpan);
}

int Span::longestSpan()
{
	if (this->_set.size() <= 1)
	{
		throw SpanException();
	}
	int value = *(--this->_set.end()) - *this->_set.begin();

	return (value);
}

const char *Span::SpanException::what() const throw()
{
	return ("SpanException");
}
