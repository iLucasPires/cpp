#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal default constructor called\n";
}

AAnimal::AAnimal(const AAnimal &src)
{
	*this = src;
	std::cout << "AAnimal copy constructor called\n";
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called\n";
}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
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
