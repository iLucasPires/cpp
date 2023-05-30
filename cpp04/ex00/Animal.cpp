#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}

std::string Animal::getType(void) const
{
	return this->_type;
}

void Animal::makeSound(void) const
{
	std::cout << "Some strange sound" << std::endl;
}
