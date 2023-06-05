#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called\n";
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain assignment operator called\n";

	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}

void Brain::setIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = idea;
	}
}

std::string Brain::getIdea(int index) const
{
    return this->ideas[index];
}

std::ostream &operator<<(std::ostream &o, Brain const &rhs)
{
	o << rhs.getIdea(0);
	return o;

}
