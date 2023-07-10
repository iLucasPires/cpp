#include "Span.hpp"

Span::Span() : _index(0), _limit(10) {}

Span::Span(unsigned int number) : _index(0), _limit(number) {}

Span::Span(const Span &src) { *this = src; }

Span::~Span() {}

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
		throw std::out_of_range("Overflow limit");
	}
	this->_set.insert(number);
	this->_index++;
}

int Span::shortestSpan()
{
	if (this->_set.empty() || this->_set.size() == 1)
	{
		throw std::runtime_error("Set empty");
	}

	int shortestSpan = std::numeric_limits<int>::max();

	std::set<int>::iterator it = this->_set.begin();
	std::set<int>::iterator nextIt = it;
	++nextIt;

	while (nextIt != this->_set.end())
	{
		int span = std::abs(*it - *nextIt);
		if (span < shortestSpan)
		{
			shortestSpan = span;
		}
		++it;
		++nextIt;
	}

	return shortestSpan;
}

int Span::longestSpan()
{
	if (this->_set.empty())
	{
		throw std::runtime_error("Set empty");
	}

	int value = *(--this->_set.end()) - *this->_set.begin();
	return (value);
}

void Span::addManyNumbers(std::set<int>::iterator begin, std::set<int>::iterator end)
{
	unsigned int temp = this->_index + std::distance(begin, end);

	if (temp > this->_limit)
		throw std::out_of_range("Overflow limit");
	this->_index = temp;
	this->_set.insert(begin, end);
}
