#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called\n";
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal assignment operator called\n";
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::makeSound(void) const
{
	std::cout << "Some random sound\n";
}
