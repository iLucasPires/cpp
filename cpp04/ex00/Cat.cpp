#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called\n";
	this->_type = "Cat";
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
		this->_type = rhs._type;
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow meow\n";
}
