#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called\n";
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal copy constructor called\n";
	*this = src;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called\n";
}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "AAnimal assignment operator called\n";
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

std::string AAnimal::getType(void) const
{
	return this->type;
}

void AAnimal::makeSound(void) const
{
	std::cout << "Some random sound\n";
}
