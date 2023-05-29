#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called\n";
	this->_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal()
{
	std::cout << "Dog copy constructor called\n";
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

Dog &Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof\n";
}

