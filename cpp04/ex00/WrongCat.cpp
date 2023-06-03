#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called\n";
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called\n";
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meow Meow\n";
}

