#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called\n";
	this->type = "Cat";
}

Cat::Cat(const Cat &src) : Animal()
{
	std::cout << "Cat copy constructor called\n";
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

Cat &Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow meow\n";
}
